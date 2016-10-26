#include "includes/rt.h"
#include "includes/get_scene.h"

float	length2(t_vec *r)
{
	float x;

	x = r->x * r->x + r->y * r->y + r->z * r->z;
	return (x);
}

t_vec	normalize(t_vec *r)
{
	float	len;
	float	bla;
	t_vec	dir;

	bla = dot_product(*r,*r);
	if (bla > 0)
	{
		len = 1.0f / sqrt(bla);
		dir = scale_vec(len, *r);
	}
	return (dir);
}

float		mix(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}

float		max(float i, float j)
{
	if (i >= j)
		return (i);
	else return (j);
}

float		min(float i, float j)
{
	if (i <= j)
		return (i);
	else return (j);
}

t_vec		trace(t_ray *r, t_object *objects, int depth)
{
	t_vec		pixel;
	t_vec		surf_color;
	t_object	*sphere;
	t_object	*pony;
	t_vec		p_hit;
	t_vec		n_hit;
	t_vec		refl_color;
	t_vec		refr_color;
	t_ray		refl;
	t_ray		refr;
	float		bias;
	float		tclosest;
	float		t0;
	float		t1;
	float		facing_ratio;
	float		fresnel;
	float		ior;
	float		eta;
	float		cosi;
	float		k;
	int			inside;

	sphere = NULL;
	pony =	objects;
	t0 = INF;
	t1 = INF;
	tclosest = INF;
	bias = 1e-4;
	inside = 0;
	facing_ratio = 0;
	ior = 1.1;
	eta = 0;
	cosi = 0;
	k = 0;
	surf_color = (t_vec){0,0,0};
	refl_color = (t_vec){0,0,0};
	refr_color = (t_vec){0,0,0};
	while (pony)
	{
		if (intersect_sphere(r, pony, &t0, &t1))
		{
			t0 < 0 ? t0 = t1 : 0;
			if (t0 < tclosest)
			{
				tclosest = t0;
				sphere = pony;
			}
		}
		pony = pony->next;
	}
	if(!sphere)
		return (t_vec){2,2,2};
	p_hit = add_vec(r->origin, scale_vec(tclosest, r->dir));
	n_hit = vec_subtract(p_hit, (t_vec){sphere->position_x, sphere->position_y, sphere->position_z});
	n_hit = normalize(&n_hit);
	if (dot_product(r->dir, n_hit) > 0)
	{
		n_hit = scale_vec(-1.f, n_hit);
		inside = 1;
	}
	if ((sphere->trans > 0 || sphere->reflection > 0) && depth < M_DEPTH)
	{
		facing_ratio = -1 * dot_product(r->dir, n_hit);
		fresnel = mix(pow(1 - facing_ratio, 5), 1, .1);
		refl.dir = vec_subtract(r->dir, scale_vec(2*dot_product(r->dir, n_hit), n_hit));
		refl.dir = normalize(&refl.dir);
		refl.origin = add_vec(p_hit, scale_vec(bias, n_hit));
		refl_color = trace(&refl, objects, depth + 1);
		if (sphere->trans)
		{
			if(inside)
				eta = ior;
			else eta = 1.0f / ior;
			cosi = -1.0f * dot_product(n_hit, r->dir);
			k = 1.0f - eta * eta * (1.0f - cosi * cosi);
			refr.dir = add_vec(scale_vec(eta, r->dir),
						scale_vec(eta * cosi - sqrt(k), n_hit));
			refr.dir = normalize(&refr.dir);
			refr.origin = vec_subtract(p_hit, scale_vec(bias, n_hit));
			refr_color = trace(&refr, objects, depth + 1.0f);
		}
		surf_color = add_vec(scale_vec(fresnel, refl_color),
					scale_vec((1.0f - fresnel) *  sphere->trans,refr_color));
		surf_color = cross_prod(surf_color, (t_vec){sphere->red,
					sphere->green, sphere->blue});
	}
	else
	{
		pony = objects;
		t_vec sphere_color;
		t_vec transmission;
		t_ray light_ray;
		t_object *light;
		t0 = INF;
		t1 = INF;
		float x = 0;
		while (pony)
		{
			if (strcmp(pony->name, "Light") == 0)
			{
				sphere_color = (t_vec){sphere->red, sphere->green, sphere->blue};
				transmission = (t_vec){1,1,1};
				light_ray.dir = vec_subtract((t_vec){pony->position_x, pony->position_y, pony->position_z}, p_hit);
				light_ray.dir = normalize(&light_ray.dir);
				t_object *unicorn = objects;
				light = pony;
				while (unicorn)
				{
					if (strcmp(unicorn->name, "Light") !=  0)
					{
						light_ray.origin = add_vec(p_hit, scale_vec(bias, n_hit));
						if(intersect_sphere(&light_ray, unicorn, &t0, &t1))
						{
							transmission = (t_vec){0.1,0.1,0.1};
							light = pony;
							unicorn = NULL;
						}
					}
					if (unicorn)
						unicorn = unicorn->next;
				}
				t_vec a = cross_prod(sphere_color, transmission);
				x = dot_product(n_hit,light_ray.dir);
				x = max(0, x);
				t_vec b = scale_vec(x, (t_vec){light->emis_r, light->emis_g, light->emis_b});
				surf_color = add_vec(surf_color, cross_prod(a, b));
			}
			pony = pony->next;
		}
	}
	return (add_vec(surf_color, (t_vec){sphere->emis_r, sphere->emis_g, sphere->emis_b}));
}

t_object	*my_pony(char *s, t_vec c, float refl, float trans, t_vec pos, float r, t_vec e)
{
	t_object	*pony;
	static int i=0;
	pony = (t_object*)malloc(sizeof(t_object));
	pony->name = s;
	pony->red = c.x;
	pony->green = c.y;
	pony->blue = c.z;
	pony->reflection = refl;
	pony->trans = trans;
	pony->position_x = pos.x;
	pony->position_y = pos.y;
	pony->position_z = pos.z;
	pony->radius = r;
	pony->radius_x2 = r * r;
	pony->length_x = 0;
	pony->length_y = 0;
	pony->length_z = 0;
	pony->emis_r = e.x;
	pony->emis_g = e.y;
	pony->emis_b = e.z;
	pony->next = NULL;
	return (pony);
}

void le_main(t_object *objects)
{
	t_object		*pony;
	t_ray			r;
	t_index			num;
	unsigned char	img[WIDTH * HEIGHT * 3];
	t_vec			pixel;

	if (!(mlx = mlx_init()))
	{
		write(1, "Couldn't init mlx", 18);
		return (0);
	}
	
	r.origin.x = 0;
	r.origin.y = 0;
	r.origin.z = 0;
	set_up_num(&num);
	objects = my_pony("Sphere", (t_vec){0.2, 0.6, 0.2}, 0.0, 0.0, (t_vec){0.0, -10004, -20}, 10000, (t_vec){0,0,0});
	objects->next = my_pony("Sphere", (t_vec){1.0, 0.95, 0.3}, 1.0, 0.0, (t_vec){-2.0, 0.0, -20}, 4, (t_vec){0,0,0});
	objects->next->next = my_pony("Sphere", (t_vec){0.1, 0.7, 0.46}, 0.0, 1.0, (t_vec){5.0, 1.0, -15}, 2, (t_vec){0,0,0});
	objects->next->next->next = my_pony("Sphere", (t_vec){0.05, 0.7, 0.9}, 0.5, 0.0, (t_vec){5.0, 0.0, -25}, 3, (t_vec){0,0,0});
	objects->next->next->next->next = my_pony("Sphere", (t_vec){0.9, 0.1, 0.9}, 0.0, 0.0, (t_vec){-5.5, 5.0, -15}, 3, (t_vec){0, 0, 0});
	objects->next->next->next->next->next = my_pony("Light", (t_vec){0.0, 0.0, 0.0}, 0.0, 0.0, (t_vec){0.0, 20.0, -30}, 3, (t_vec){3,3,3});
	while (num.i < HEIGHT)
	{
		num.j = 0;
		num.y_dir = (1 - 2 * ((num.i + 0.5f) * num.inv_h)) * num.angle;
		while (num.j < WIDTH)
		{
			num.x_dir = (2 * ((num.j + 0.5f) * num.inv_w) - 1)
						* num.angle * num.aspect_r;
			r.dir.x = num.x_dir;
			r.dir.y = num.y_dir;
			r.dir.z = -1.f;

			r.dir = normalize(&r.dir);
			pixel = trace(&r, objects, 0);
			img[(num.j + num.i * WIDTH) * 3 + 0] = min(1, pixel.x) * 255;
			img[(num.j + num.i * WIDTH) * 3 + 1] = min(1, pixel.y) * 255;
			img[(num.j + num.i * WIDTH) * 3 + 2] = min(1, pixel.z) * 255;
			num.j++;
		}
		num.i++;
	}
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "Raytraycing")))
	{
		write(1, "Couldn't create window", 22);
		return (0);
	}
	save_xpm("scene1.xpm", img, WIDTH, HEIGHT);
	mlx_loop(mlx);
	pony_freedom(objects);
}

int	main(int argc, char **argv)
{
	int			a;
	t_object	*pony;
	t_object	*objects;
	void		*mlx;
	void		*win;
	void		*img;
	int			w;
	int			h;

	w = WIDTH;
	h = HEIGHT;
	if (!(mlx = mlx_init()))
	{
		write(1, "Couldn't init mlx", 18);
		return (0);
	}
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "Raytraycing")))
	{
		write(1, "Couldn't create window", 22);
		return (0);
	}
	le_main(objects);
	if (!(img = mlx_xpm_file_to_image(mlx, "scene1.xpm", 0, 0)))
	{
		write(1, "Couldn't create imgage", 22);
		return (0);
	}
	if (mlx_put_image_to_window(mlx, win, img, &w, &h))
		write(1, "Woow",4);
	mlx_loop(mlx);
	
	return (2000);
}