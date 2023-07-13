#include "struct.h"
#include "special_characters.h"
#include "comp.h"

void special_characters(struct Text *text)
{
    if(text->senten != 0)
    {
        wchar_t* characters = L"~`!@\"№#;$\%^:?&*()-_+=|\\/\'><";
        int check = 0;
        int count = 0;
        int index_characters = 0;
        int index = 0;
        wchar_t** arr_characters = (wchar_t**)calloc((text->senten), sizeof(wchar_t*));
        
        for(int i = 0; i < (text->senten); i++)
        {
            arr_characters[i] = (wchar_t*)calloc(wcslen(text->text[i].arr) + 1, sizeof(wchar_t));
        }

        while(1)
        {
            if(text->text[count].arr[index] == L'\0')
            {
                arr_characters[count][index_characters] = L'\0'; 
                count++;
                index = 0;
                index_characters = 0;
                
                if(count == (text->senten))
                {
                    break;
                }

                else
                {
                    continue;
                }
            }

            for(int i = 0; i < 27; i++)
            {
                if(text->text[count].arr[index] == characters[i])
                {
                    check = 1;
                }
            }

            if(check == 0)
            {
                index++;
                continue;
            }

            else
            {
                check = 0;
                arr_characters[count][index_characters] = text->text[count].arr[index];
                index_characters++;
                index++;
            }
        }

        for(int i = 0; i<(text->senten); i++)
        {
            qsort(arr_characters[i], wcslen(arr_characters[i]), sizeof(wchar_t), comp);
        }

        for(int i = 0; i<(text->senten); i++)
        {
            wprintf(L"Предложение %d: ", i+1);

            for(int j = 0; j<(wcslen(arr_characters[i])); j++)
            {
                wprintf(L"%lc ", arr_characters[i][j]);
            }

            wprintf(L"\n");
        }

        for(int i = 0; i<(text->senten); i++)
        {
            free(arr_characters[i]);
        }
        
        free(arr_characters);
    }
}
