#include "struct.h"
#include "input.h"
#include "hatred_repeated.h"
#include "hatred_odd.h"
#include "replacement.h"
#include "special_characters.h"
#include "comp.h"
#include "hated_Cyrilli.h"
#include "output.h"

int main()
{   
    setlocale(LC_ALL,"");
    struct Text text;
    wchar_t key = ' ';
    wprintf(L"Ожидается ввод текста\n");
    input(&text);
    hatred_repeated(&text);

    while(key != L'0')
    {
        wprintf(L"Выберите одну из предложенных функций\n");
        wprintf(L"1 - транслетирация всех кириллических букв\n");
        wprintf(L"2 - специальные символы в порядке уменьшения их кода\n");
        wprintf(L"3 - замена всех цифр в тексте их двоичным кодом\n");
        wprintf(L"4 - удаление всех предложений, в которых присутcвуют нечетные цифры\n");
        wprintf(L"5 - вывести текст\n");
        wprintf(L"Если хотите выйти - введите 0\n");
        key = getwchar();
        getwchar();

        switch(key)
        {
            case L'0':
                break;
            case L'1':
                hated_Cyrilli(&text);
                break;
            case L'2':
                special_characters(&text);
                wprintf(L"\n");
                break;
            case L'3':
                replacement(&text);
                break;
            case L'4':
                hatred_odd(&text);
                break;
            case L'5':
                output(&text);
                break;
            default:
                wprintf(L"Были введены некорректные данные\n");
                wprintf(L"\n");
                break;
        }
    }

    for(int i = 0; i<text.size; i++)
    {
        free(text.text[i].arr);
    }

    free(text.text);
    
    return 0;
}