#include "struct.h"
#include "replacement.h"

void replacement(struct Text *text)
{
    wchar_t* numbers = L"23456789";
    int check = 0;
    int count = 0;
    int index = 0;

    if(text->senten != 0)
    {
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

            for(int i = 0; i < 8; i++)
            {
                if(text->text[count].arr[index] == numbers[i])
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

                if(text->text[count].arr[index] == L'2')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'0';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'3')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 1; i > index + 1; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-1];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'1';
                    index += 2;
                    continue;
                }

                if(text->text[count].arr[index] == L'4')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'0';
                    text->text[count].arr[index+2] = L'0';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'5')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'0';
                    text->text[count].arr[index+2] = L'1';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'6')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'1';
                    text->text[count].arr[index+2] = L'0';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'7')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                
                    for(int i = wcslen(text->text[count].arr) + 2; i > index + 2; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-2];
                    }
                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'1';
                    text->text[count].arr[index+2] = L'1';
                    index += 3;
                    continue;
                }

                if(text->text[count].arr[index] == L'8')
                {
                    
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 3; i > index + 3; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-3];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'0';
                    text->text[count].arr[index+2] = L'0';
                    text->text[count].arr[index+3] = L'0';
                    index += 4;
                    continue;
                }

                if(text->text[count].arr[index] == L'9')
                {
                    text->text[count].arr = (wchar_t*)realloc(text->text[count].arr, (wcslen(text->text[count].arr) + 1 + 4) * sizeof(wchar_t));
                    
                    for(int i = wcslen(text->text[count].arr) + 3; i > index + 3; i--)
                    {
                        text->text[count].arr[i] = text->text[count].arr[i-3];
                    }

                    text->text[count].arr[index] = L'1';
                    text->text[count].arr[index+1] = L'0';
                    text->text[count].arr[index+2] = L'0';
                    text->text[count].arr[index+3] = L'1';
                    index += 4;
                    continue;
                }
            }
        }
    }
}