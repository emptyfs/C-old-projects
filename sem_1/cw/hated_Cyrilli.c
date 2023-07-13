#include "struct.h"
#include "hated_Cyrilli.h"

void hated_Cyrilli(struct Text *text)
{
    if(text->senten != 0)
    {
        int count = 0;
        int index = 0;
        int check = 0;
        wchar_t* rus = L"ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";

        while(1)
        {
            if(text->text[count].arr[index] == L'\0')
            {
                count++;
                index = 0;

                if(count == (text->senten))
                {
                    break;
                }

                else
                {
                    continue;
                }
            }

            for(int i = 0; i < 66; i++)
            {
                if(rus[i] == text->text[count].arr[index])
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

                if(text->text[count].arr[index] == L'а')
                {
                    text->text[count].arr[index] = L'a';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'А')
                {
                    text->text[count].arr[index] = L'A';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'б')
                {
                    text->text[count].arr[index] = L'b';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Б')
                {
                    text->text[count].arr[index] = L'B';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'в')
                {
                    text->text[count].arr[index] = L'v';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'В')
                {
                    text->text[count].arr[index] = L'V';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'г')
                {
                    text->text[count].arr[index] = L'g';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Г')
                {
                    text->text[count].arr[index] = L'G';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'д')
                {
                    text->text[count].arr[index] = L'd';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Д')
                {
                    text->text[count].arr[index] = L'D';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'е')
                {
                    text->text[count].arr[index] = L'e';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Е')
                {
                    text->text[count].arr[index] = L'E';
                    index++;
                    continue;
                }

                if(text->text[count].arr[index] == L'ё')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'y';
                    text->text[count].arr[index+1] = L'o';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ё')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'Y';
                    text->text[count].arr[index+1] = L'O';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'ж')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'z';
                    text->text[count].arr[index+1] = L'h';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ж')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'Z';
                    text->text[count].arr[index+1] = L'H';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'з')
                {
                    text->text[count].arr[index] = L'z';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'З')
                {
                    text->text[count].arr[index] = L'Z';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'и')
                {
                    text->text[count].arr[index] = L'i';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'И')
                {
                    text->text[count].arr[index] = L'I';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'й')
                {
                    text->text[count].arr[index] = L'j';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Й')
                {
                    text->text[count].arr[index] = L'J';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'к')
                {
                    text->text[count].arr[index] = L'k';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'К')
                {
                    text->text[count].arr[index] = L'K';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'л')
                {
                    text->text[count].arr[index] = L'l';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Л')
                {
                    text->text[count].arr[index] = L'L';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'м')
                {
                    text->text[count].arr[index] = L'm';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'М')
                {
                    text->text[count].arr[index] = L'M';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'н')
                {
                    text->text[count].arr[index] = L'n';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Н')
                {
                    text->text[count].arr[index] = L'N';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'о')
                {
                    text->text[count].arr[index] = L'o';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'О')
                {
                    text->text[count].arr[index] = L'O';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'п')
                {
                    text->text[count].arr[index] = L'p';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'П')
                {
                    text->text[count].arr[index] = L'P';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'р')
                {
                    text->text[count].arr[index] = L'r';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Р')
                {
                    text->text[count].arr[index] = L'R';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'с')
                {
                    text->text[count].arr[index] = L's';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'С')
                {
                    text->text[count].arr[index] = L'S';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'т')
                {
                    text->text[count].arr[index] = L't';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Т')
                {
                    text->text[count].arr[index] = L'T';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'у')
                {
                    text->text[count].arr[index] = L'u';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'У')
                {
                    text->text[count].arr[index] = L'U';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'ф')
                {
                    text->text[count].arr[index] = L'f';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ф')
                {
                    text->text[count].arr[index] = L'F';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'х')
                {
                    text->text[count].arr[index] = L'x';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Х')
                {
                    text->text[count].arr[index] = L'X';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'ц')
                {
                    text->text[count].arr[index] = L'c';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ц')
                {
                    text->text[count].arr[index] = L'C';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'ч')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'c';
                    text->text[count].arr[index+1] = L'h';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ч')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'C';
                    text->text[count].arr[index+1] = L'H';
                    index += 2;
                    continue;
                }
            
                if(text->text[count].arr[index] == L'ш')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L's';
                    text->text[count].arr[index+1] = L'h';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ш')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'S';
                    text->text[count].arr[index+1] = L'H';
                    index += 2;
                    continue;
                }
            
                if(text->text[count].arr[index] == L'щ')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }

                    text->text[count].arr[index] = L's';
                    text->text[count].arr[index+1] = L'h';
                    text->text[count].arr[index+2] = L'h';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'Щ')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }

                    text->text[count].arr[index] = L'S';
                    text->text[count].arr[index+1] = L'H';
                    text->text[count].arr[index+2] = L'H';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'ъ')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'`';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ъ')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'`';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'ы')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'y';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ы')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'Y';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'ь')
                {
                    text->text[count].arr[index] = L'`';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ь')
                {
                    text->text[count].arr[index] = L'`';
                    index ++;
                    continue;
                }

                if(text->text[count].arr[index] == L'э')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'e';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Э')
                {
                text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
               
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'E';
                    text->text[count].arr[index+1] = L'`';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'ю')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'y';
                    text->text[count].arr[index+1] = L'u';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Ю')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'Y';
                    text->text[count].arr[index+1] = L'U';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'я')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'y';
                    text->text[count].arr[index+1] = L'a';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'Я')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'Y';
                    text->text[count].arr[index+1] = L'A';
                    index += 2;
                    continue;
                }
            }
        }
    }
}