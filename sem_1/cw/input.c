#include "struct.h"
#include "input.h"

void input(struct Text *text)
{
    text->senten = 5;
    text->size = 5;
    int count = 0;
    wchar_t letter;
    int index = 0;
    int check = 1;
    text->text = (struct Sentence*)calloc((text->size), sizeof(struct Sentence));

    for(int i = 0; i < 5; i++)
    {
        text->text[i].arr = (wchar_t*)calloc(30, sizeof(wchar_t));
    }

    while(check == 1)
    {
        letter = getwchar();

        if((index == 0) && (letter == L'\n'))
        {
                check = 0;
            	continue;
        }

        if((index == 0) && (letter != L'\n'))
        {
            if(((count+1) % 5 == 0) && (count != 0))
            {
                text->text = (struct Sentence*)realloc(text->text, (count+6) * sizeof(struct Sentence));
                text->size += 5;

                for(int i = count+1; i < count+6; i++)
                {
                    text->text[i].arr = (wchar_t*)calloc(30, sizeof(wchar_t));
                }
            }

            text->text[count].arr[index] = letter;
            index++;
            continue;
        }

        if((index != 0) && (letter != L'.'))
        {
            if((index+1) % 30 == 0)
            {
                text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (index+30) * sizeof(wchar_t));
            }

            text->text[count].arr[index] = letter;
            index++;
            continue;
        }

        if((index != 0) && (letter == L'.'))
        {
            if((index+1) % 30 == 0)
            {
                text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (index+2) * sizeof(wchar_t));
            }

            text->text[count].arr[index] = letter;
            text->text[count].arr[index+1] = L'\0';
            if(getwchar() == L'\n')
            {
		        break;
	        }
            index = 0;
            count++;
            continue;
        }
    }
    text->senten = count+1;
}