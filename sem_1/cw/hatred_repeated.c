#include "struct.h"
#include "hatred_repeated.h"
#include <wchar.h>

void hatred_repeated(struct Text *text)
{
    int indexI = 0;
    int indexJ = 0;

    while(1)
    {
        if((indexI != indexJ) && (wcslen(text->text[indexI].arr) == wcslen(text->text[indexJ].arr)) && (!(wcsicmp(text->text[indexI].arr, text->text[indexJ].arr))))
        {
            for(int k = indexJ; k < (text->senten); k++)
            {
                if(wcslen(text->text[k].arr) < wcslen(text->text[k+1].arr))
                {
                    text->text[k].arr = (wchar_t*)realloc(text->text[k].arr, (wcslen(text->text[k+1].arr)+1) * sizeof(wchar_t));
                }

                wcscpy(text->text[k].arr, text->text[k+1].arr);
            }
            text->senten -= 1;
            indexJ -= 1;
        }

        if((indexJ == (text->senten) - 1) && (indexI != (text->senten) - 1))
        {
            indexI++;
            indexJ = indexI + 1;
        }

        else
        {
            indexJ++;
        }

        if(indexI == (text->senten) - 1)
        {
            break;
        }
    }
}