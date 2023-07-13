#include "struct.h"
#include "hatred_odd.h"

void hatred_odd(struct Text *text)
{
    int count = 0;
    int index= 0;

    while(1)
    {
        if(text->text[count].arr[index] == L'\0')
        {
            count++;
            index = 0;

            if(count == (text->senten))
            {
                if(text->senten == 0)
                {
                    wprintf(L"Были удалены все предложения, так как другим функция нужно для обработки хотя бы одно преложение, вам следует выйти из программы и ввести новый текст.\n");
                }
                break;
            }

            else
            {
                continue;
            }
        }

        if((text->text[count].arr[index] != L'7') && (text->text[count].arr[index] != L'1') && (text->text[count].arr[index] != L'3') && (text->text[count].arr[index] != L'5') && (text->text[count].arr[index] != L'9'))
        {
            index++;
            continue;
        }

        else
        {
            for(int i = count; i < (text->senten); i++)
            {
                if(wcslen(text->text[i].arr) < wcslen(text->text[i+1].arr))
                {
                    text->text[i].arr = (wchar_t*)realloc(text->text[i].arr, (wcslen(text->text[i+1].arr)+1) * sizeof(wchar_t));
                }

                wcscpy(text->text[i].arr, text->text[i+1].arr);
            }

            text->senten = text->senten - 1;
            index = 0;

            if(count == text->senten)
            {
                if(text->senten == 0)
                {
                    wprintf(L"Были удалены все предложения, так как другим функция нужно для обработки хотя бы одно преложение, вам следует выйти из программы и ввести новый текст.\n");
                }
                
                break;
            }
        }
    }
}