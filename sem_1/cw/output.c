#include "struct.h"
#include "output.h"

void output(struct Text *text)
{
    for(int i = 0; i<text->senten; i++)
    {
        wprintf(L"%ls ", text->text[i].arr);
    }
    
    wprintf(L"\n");
}