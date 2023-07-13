#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#define PNG_DEBUG 3
#include <png.h>

struct Png
{
	int width, height;
	png_byte color_type;
	png_byte bit_depth;

	png_structp png_ptr;
	png_infop info_ptr;
	int number_of_passes;
	png_bytep *row_pointers;
};

int read_png_file(char *file_name, struct Png *image)
{
	int x,y;
	char header[8]; //8 - максимальный размер

	/* открытие файла и его на проверка на тип png */
	FILE *fp = fopen(file_name, "rb");

	if(!fp)
    {
		fprintf(stderr, "При считывание файла произошла ошибка\n");
		return 1;
	}

	fread(header, 1, 8, fp);

	if(png_sig_cmp(header, 0, 8))
    {
		fprintf(stderr, "Считанный файл не является png-файлом\n");
		return 1;
	}

	/* Инициализирование png_ptr структурой */
	image->png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if(!image->png_ptr)
    {
		fprintf(stderr, "Произошла ошибка при создании файла\n");
		return 1;
	}
	
	image->info_ptr = png_create_info_struct(image->png_ptr);

	if(!image->info_ptr)
    {
		fprintf(stderr, "Произошла ошибка при создании структуры\n");
		return 1;
	}
		
	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при инициализации ввода/вывода\n");
		return 1;
	}

	png_init_io(image->png_ptr, fp);
	png_set_sig_bytes(image->png_ptr, 8);

	png_read_info(image->png_ptr, image->info_ptr);

	image->width = png_get_image_width(image->png_ptr, image->info_ptr);
	image->height = png_get_image_height(image->png_ptr, image->info_ptr);
	image->color_type = png_get_color_type(image->png_ptr, image->info_ptr);
	image->bit_depth = png_get_bit_depth(image->png_ptr, image->info_ptr);

	image->number_of_passes = png_set_interlace_handling(image->png_ptr);
	png_read_update_info(image->png_ptr, image->info_ptr);
	
	/* чтение файла */
	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при считывании файла\n");
		return 1;
	}

	image->row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * image->height);

	for(y = 0; y < image->height; y++)
    {
		image->row_pointers[y] = (png_byte *) malloc(png_get_rowbytes(image->png_ptr, image->info_ptr));
	}

	png_read_image(image->png_ptr, image->row_pointers);

	fclose(fp);
	return 0;
}

void write_png_file(char *file_name, struct Png *image)
{
	int x,y;
	/* создание файла */
	FILE *fp = fopen(file_name, "wb");

	if (!fp)
    {
		fprintf(stderr, "Произошла ошибка при создании файла под запись\n");
		return;
	}

	/* Инициализирование структурой */
	image->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if(!image->png_ptr)
    {
		fprintf(stderr, "Произошла ошибка при инициализации структурой\n");
		return;
	}

	image->info_ptr = png_create_info_struct(image->png_ptr);

	if(!image->info_ptr)
    {
		fprintf(stderr, "Произошла ошибка при инициализации\n");
		return;
	}

	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при инициализации ввода/вывода\n");
		return;
	}

	png_init_io(image->png_ptr, fp);

	/* записываем header */
	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при записи header\n");
		return;
	}

	png_set_IHDR(image->png_ptr, image->info_ptr, image->width, image->height, image->bit_depth, image->color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_write_info(image->png_ptr, image->info_ptr);

	/* записываем bytes */
	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при записи bytes\n");
		return;
	}
	
	png_write_image(image->png_ptr, image->row_pointers);

	/* записываем конец файла */
	if(setjmp(png_jmpbuf(image->png_ptr)))
    {
		fprintf(stderr, "Произошла ошибка при записи конца файла\n");
		return;
	}

	png_write_end(image->png_ptr, NULL);
	fclose(fp);
}

void square(struct Png *image, int start_x, int start_y, int start_a, int line_width, int new_red, int new_green, int new_blue, int condition, int new_red_1, int new_green_1, int new_blue_1){
	
	int x,y;
	if(png_get_color_type(image->png_ptr, image->info_ptr) !=  PNG_COLOR_TYPE_RGBA)
    {
		fprintf(stderr, "Изображение должно соответствовать PNG_COLOR_TYPE_RGBA\n");
		return;
	}

	if(start_x < 0 || start_y < 0 || start_x > image->width - 1 || start_y > image->height - 1)
    {
		fprintf(stderr, "Недопустимые координаты левого верхнего угла\n");
		return;
	}
	
	if(start_a < 0 || start_a > image->width - start_x - 1 || start_a > image->height - start_y - 1)
    {
		fprintf(stderr, "Недопустимый размер стороны\n");
		return;
	}

	if(line_width < 0 || line_width > start_a)
    {
		fprintf(stderr, "Недопустимая толщина линий\n");
		return;
	}

	for(y = start_y; y < start_y + line_width; y++)
    {
		png_byte *row = image->row_pointers[y];

		for(x = start_x; x < start_x + start_a; x++)
        {
			png_byte *ptr = &(row[x * 4]);
			ptr[0] = new_red;
			ptr[1] = new_green;
			ptr[2] = new_blue;
			ptr[3] = 255;
		}
	}

	for(y = start_y + start_a; y > start_y + start_a - line_width; y--)
    {
		png_byte *row = image->row_pointers[y];

		for(x = start_x; x < start_x + start_a; x++)
        {
			png_byte *ptr = &(row[x * 4]);
			ptr[0] = new_red;
			ptr[1] = new_green;
			ptr[2] = new_blue;
			ptr[3] = 255;
		}
	}

	for(y = start_y; y < start_y + start_a; y++)
    {
		png_byte *row = image->row_pointers[y];

		for(x = start_x; x < start_x + line_width; x++)
        {
			png_byte *ptr = &(row[x * 4]);
			ptr[0] = new_red;
			ptr[1] = new_green;
			ptr[2] = new_blue;
			ptr[3] = 255;
		}
	}

	for(y = start_y; y < start_y + start_a; y++)
    {
		png_byte *row = image->row_pointers[y];

		for(x = start_x + start_a ; x > start_x + start_a - line_width; x--)
        {
			png_byte *ptr = &(row[x * 4]);
	    	ptr[0] = new_red;
			ptr[1] = new_green;
			ptr[2] = new_blue;
			ptr[3] = 255;
		}
	}
	
	if(condition == 1)
    {
		for(y = start_y + line_width; y < start_y + start_a - line_width + 1; y++)
        {
			png_byte *row = image->row_pointers[y];

			for(x = start_x + line_width; x < start_x + start_a - line_width + 1; x++)
            {
				png_byte *ptr = &(row[x * 4]);
				ptr[0] = new_red_1;
				ptr[1] = new_green_1;
				ptr[2] = new_blue_1;
				ptr[3] = 255;
			}
		}
	}
	
	x = 0;
    for(y = start_y + line_width; y < start_y + start_a - line_width + 1; y++)
    {
        png_byte *row = image->row_pointers[y];

        if(start_x + line_width +  x < start_x + start_a - line_width + 1)
        {
            png_byte *ptr = &(row[(start_x + line_width + x) * 4]);
            ptr[0] = new_red;
            ptr[1] = new_green;
            ptr[2] = new_blue;
            ptr[3] = 255;
        }
        x++;
    }

	for(int k = 0; k < line_width/2; k++)
    {	
		x = 0;

		for(y = start_y + line_width; y < start_y + start_a - line_width + 1; y++)
        {
			png_byte *row = image->row_pointers[y];

			if(start_x + line_width +  x + k+1 < start_x + start_a - line_width + 1)
            {
				png_byte *ptr = &(row[(start_x + line_width + x + k+1) * 4]);		
				ptr[0] = new_red;
				ptr[1] = new_green;
				ptr[2] = new_blue;
				ptr[3] = 255;
			}

			x++;
		}
		x = 0;

		for(y = start_y + line_width; y < start_y + start_a - line_width + 1; y++)
        {
			png_byte *row = image->row_pointers[y];

	      	if(start_x + line_width + x - k-1 > start_x + line_width - 1)
            {
				png_byte *ptr = &(row[(start_x + line_width + x - k-1) * 4]);
				ptr[0] = new_red;
				ptr[1] = new_green;
				ptr[2] = new_blue;
				ptr[3] = 255;
			}
			x++;
		}
	}

	x = 0;
	for(y = start_y + start_a - line_width; y > start_y + line_width-1; y--)
    {
        png_byte *row = image->row_pointers[y];

        if(start_x + line_width +  x < start_x + start_a - line_width + 1)
        {
            png_byte *ptr = &(row[(start_x + line_width + x) * 4]);
            ptr[0] = new_red;
            ptr[1] = new_green;
            ptr[2] = new_blue;
            ptr[3] = 255;
        }
        x++;
    }

    for(int k = 0; k < line_width/2; k++)
    {
        x = 0;
        for(y = start_y + start_a - line_width; y > start_y + line_width-1; y--)
        {
            png_byte *row = image->row_pointers[y];

            if(start_x + line_width +  x + k+1 < start_x + start_a - line_width + 1)
            {
                png_byte *ptr = &(row[(start_x + line_width + x + k+1) * 4]);
                ptr[0] = new_red;
                ptr[1] = new_green;
                ptr[2] = new_blue;
                ptr[3] = 255;
            }
            x++;
        }
        x = 0;

        for(y = start_y + start_a - line_width; y > start_y + line_width-1; y--)
        {
            png_byte *row = image->row_pointers[y];

            if(start_x + line_width + x - k-1 > start_x + line_width - 1)
            {
                png_byte *ptr = &(row[(start_x + line_width + x - k-1) * 4]);
                ptr[0] = new_red;
                ptr[1] = new_green;
                ptr[2] = new_blue;
                ptr[3] = 255;
            }

            x++;
        }
	} 
}	

void rtd(struct Png *image, int condition_1, int condition_2)
{
	
	int x,y;

	if(png_get_color_type(image->png_ptr, image->info_ptr) != PNG_COLOR_TYPE_RGBA)
    {
		fprintf(stderr, "Изображние должно соответствовать PNG_COLOR_TYPE_RGBA\n");
		return;
	}
	
	if(condition_1 != 0 && condition_1 != 1 && condition_1 != 2)
    {
		fprintf(stderr, "Доступны только три состоянии - 0, 1 и 2\n");
		return;
	}

	if(condition_2 != 0 && condition_2 != 255)
    {
		fprintf(stderr, "Доступны только два цвет - под номер 0 и под номером 255\n");
		return;
	}

	for(y = 0; y < image->height; y++)
    {
		png_byte *row = image->row_pointers[y];

		for(x = 0; x < image->width; x++)
        {
			png_byte *ptr = &(row[x * 4]);
			ptr[condition_1] = condition_2;
		}
	}
}

void turn(struct Png *image, int x1, int y1, int x2, int y2, int corner)
{
	
	int x,y,k;

	if(png_get_color_type(image->png_ptr, image->info_ptr) != PNG_COLOR_TYPE_RGBA)
    {
		fprintf(stderr, "Изображение должно соответствовать PNG_COLOR_TYPE_RGBA\n");
		return;
	}

	if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > image->width-1 || x2 > image->width || y1 > image->height-1 || y2 > image->height-1 || y1 > y2 || x1 > x2)
    {
		fprintf(stderr, "Введены некорректные координаты\n");
		return;
	}

	if(corner != 90 && corner != 180 && corner != 270)
    {
		fprintf(stderr, "Угол поворота может быть только 90, 180 и 270\n");
		return;
	}
	
	png_bytep *row_change;

	row_change = (png_bytep *) malloc(sizeof(png_bytep) * image->height);

	for(y = 0; y < image->height; y++)
    {
		row_change[y] = (png_byte *) malloc(sizeof(png_bytep) * image->width);
	}

	for(y = 0; y < image->height; y++)
    {
		png_byte *row1 = image->row_pointers[y];
		png_byte *row2 = row_change[y];

		for(x = 0; x < image->width; x++)
        {
			png_byte *ptr1 = &(row1[x * 4]);
			png_byte *ptr2 = &(row2[x * 4]);
			ptr2[0] = ptr1[0];
			ptr2[1] = ptr1[1];
			ptr2[2] = ptr1[2];
			ptr2[3] = ptr1[3];
		}
	}

	int kx;
	int ky;

	if(corner == 90)
    {

		if(image->width-1 < x1+y2)
        {
            fprintf(stderr, "Часть изображения не может быть повернута, потому как выходит за рамки\n");
            return;
        }

		if(image->height-1 < y1+x2)
        {
			fprintf(stderr, "Часть изображения не может быть повернутна, потому как выходит за рамки\n");
			return;
		}

		ky = y1;
		kx = x1;

		for(y = y2; y > y1-1; y--)
        {
			png_byte *row2 = row_change[y];
            
			for(x = x1; x < x2+1; x++)
            {
				png_byte *row1 = image->row_pointers[ky];
				ky++;
				png_byte *ptr1 = &(row1[kx * 4]);	
				png_byte *ptr2 = &(row2[x * 4]);
				ptr1[0] = ptr2[0];
                ptr1[1] = ptr2[1];
                ptr1[2] = ptr2[2];
                ptr1[3] = ptr2[3];
			}

			kx++;
			ky = y1;
		}
	}

	if(corner == 180)
    {
	
		for(y = y1; y < y2+1; y++)
        {
			png_byte *row2 = row_change[y];
			png_byte *row1 = image->row_pointers[y1+y2-y];

			for(x = x1; x < x2+1; x++)
            {
				png_byte *ptr2 = &(row2[x * 4]);
				png_byte *ptr1 = &(row1[(x1+x2-x) * 4]);
				ptr1[0] = ptr2[0];
				ptr1[1] = ptr2[1];
				ptr1[2] = ptr2[2];
				ptr1[3] = ptr2[3];
			}
		}
	}

	if(corner == 270)
    {
		if(image->width-1 < x1+y2)
        {
            fprintf(stderr, "Часть изображения не может быть повернута, потому как выходит за рамки\n");
            return;
        }

        if(image->height-1 < y1+x2)
        {
            fprintf(stderr, "Часть изображения не может быть повернутна, потому как выходит за рамки\n");
            return;
        }

		ky = y1+x2;
		kx = x1+y2;

		for(y = y2; y > y1-1; y--)
        {
			png_byte *row2 = row_change[y];

			for(x = x1; x < x2+1; x++)
            {
				png_byte *row1 = image->row_pointers[ky];
				ky--;
				png_byte *ptr1 = &(row1[kx * 4]);
				png_byte *ptr2 = &(row2[x * 4]);
				ptr1[0] = ptr2[0];
				ptr1[1] = ptr2[1];
				ptr1[2] = ptr2[2];
				ptr1[3] = ptr2[3];
			}

			kx--;
			ky = y1+x2;
		}
	}

	for(y = 0; y < image->height; y++)
    {
		free(row_change[y]);
	}

	free(row_change);
}

void help()
{
	printf("Использование утилиты: <имя_программы> <имя входного файла> <имя выходного файла> <ключ> <параметры>\n");
	printf("ключ может быть полным (тогда используйте <--> перед ним) и сокращенным (тогда используйте <-> перед ним\n");
	printf("вам доступны следующие ключи:\n");
	printf("1. -s или --square - рисование квадрата с дигоналями с возможностью заливки, с выбором цветов заливки и линий квадрата\n");
	printf("параметры для квадрата должны указываться в следующем порядке через пробел:\n");
	printf("<координата x левого верхнего угла> <координата y левого верхнего угла> <размер стороны> <толщина линий>\n");
    printf("<красный цвет линий (от 0 до 255)> <зеленый цвет линий (от 0 до 255)> <синий цвет линий (от 0 до 255)>\n");
    printf("<заливка (1 - заливать, 0 или любое другое число - не заливать)> <красный цвет заливки (от 0 до 255, если вы не выбрали\n");
    printf("заливку, укажите 0)> <зеленый цвет заливки (от 0 до 255, если вы не выбрали заливку, укажите 0)> <синий цвет заливки\n");
    printf("(от 0 до 255, если вы не выбрали заливку укажите 0)>\n");
	printf("2. -r или --rtd - выключить или включить на максимум одну из компонент цвета картинки\n");
	printf("параметры для rtd должны указываться в следующем порядке через пробел:\n");
	printf("<выбор компоненты (от 0 до 2)> <цвет выбранной компоненты (0 либо 255)>\n");
	printf("3. -t или --turn - повернуть выбранную область на углы 90, 180 и 270\n");
	printf("параметры для поворота должны указываться в следующем порядке через пробел\n");
	printf("<координата x левого верхнего угла> <координата y левого верхнего угла> <координата x правого нижнего угла>\n");
    printf("<координата y правого нижнего угла> <угол поворота (90, 180 или 270)>\n");
	printf("4. -i или --info - распечать картинку\n");
	printf("5. -h или --help - получить справку о помоще\n");
	printf("если вы что-то введете неправильно, вам сообщат об ошибке\n");
}

void clear(struct Png *image)
{
	int x,y;

	for(y = 0; y < image->height; y++)
    {
		free(image->row_pointers[y]);
	}

	free(image->row_pointers);
}

int main(int argc, char **argv)
{
	const char *options = "srtih";
	struct option longOpts[] = 
    {
		{"square", no_argument, NULL, 's'},
		{"rtd", no_argument, NULL, 'r'},
		{"turn", no_argument, NULL, 't'},
		{"info", no_argument, NULL, 'i'},
		{"help", no_argument, NULL, 'h'}
	};

	struct Png image;

    int read = read_png_file(argv[1], &image);

    if(read != 0)
    {
		return 1;
	}	
	int longIndex;
	int way = getopt_long(argc, argv, options, longOpts, &longIndex);

	while(way != -1)
    {
	    switch(way)
        {
		    case 's':
				if(argc != 15)
                {
					fprintf(stderr, "Были введены некорректные данные\n");
					help();
					return 0;
				}

				for(int i = 4; i < 15; i++)
                {
                    for(int j = 0; j < strlen(argv[i]); j++)
                    {
                        if(isdigit(argv[i][j]) == 0)
                        {
                            fprintf(stderr, "Были введены некорректные данные\n");
							help();
                            return 0;
                        }
                    }
                }
				square(&image, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]), atoi(argv[13]), atoi(argv[14]));
				write_png_file(argv[2], &image);
				break;
			case 'r':
				if(argc != 6)
                {
					fprintf(stderr, "Были введены некорректные данные\n");
					help();
					return 0;
				}

				for(int i = 4; i < 6; i++)
                {
                    for(int j = 0; j < strlen(argv[i]); j++)
                    {
                        if(isdigit(argv[i][j]) == 0)
                        {
                            fprintf(stderr, "Были введены некорректные данные\n");
							help();
                            return 0;
                        }
                    }
                }
                
				rtd(&image, atoi(argv[4]), atoi(argv[5]));
				write_png_file(argv[2], &image);
				break;
			case 't':
				if(argc != 9)
                {
					fprintf(stderr, "Были введены некорректные данные\n");
					help();
					return 0;
				}

				for(int i = 4; i < 9; i++)
                {
                    for(int j = 0; j < strlen(argv[i]); j++)
                    {
                        if(isdigit(argv[i][j]) == 0)
                        {
                            fprintf(stderr, "Были введены некорректные данные\n");
							help();
                            return 0;
                        }
                    }
                }
				turn(&image, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]));
				write_png_file(argv[2], &image);
				break;
			case 'i':
				write_png_file(argv[2], &image);
				break;
			case 'h': 
				help();
				return 0;
				break;
			default:
				help();
				return 0;
				break;
		}
		way = getopt_long(argc, argv, options, longOpts, &longIndex);
	}
	clear(&image);
	return 0;
}
