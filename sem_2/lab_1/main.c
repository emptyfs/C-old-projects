#include <stdio.h>
#include <regex.h> // на windows нет такого файла в стандартной библиотеке :)
#include <string.h>
#include <stdlib.h>

char* InputSentence();
char** InputText(int*);

int main()
{
    int n = 0;
    char** SentenceS = InputText(&n);
    char* regexs = "([A-Za-z0-9_]+)@[A-Za-z0-9_-]+: ?~ ?# (.+)\n$";
    size_t maxGroups = 3;
    regmatch_t Groups[maxGroups];
    regex_t regexCompiled;

    if(regcomp(&regexCompiled, regexs, REG_EXTENDED))
    {
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(regexec(&regexCompiled, SentenceS[i], maxGroups, Groups, 0) == 0)
        {
            for(int j = Groups[1].rm_so; j<Groups[1].rm_eo; j++)
            {
                printf("%c", SentenceS[i][j]);
            }
            printf(" - ");
            for(int j = Groups[2].rm_so; j<Groups[2].rm_eo; j++)
            {
                printf("%c", SentenceS[i][j]);
            }
            printf("\n");
        }
    }
    regfree(&regexCompiled);
    for(int i = 0; i < n; i++)
    {
        free(SentenceS[i]);
    }
    free(SentenceS);
    return 0;
}

char* InputSentence()
{   
    int size = 15;
    int index = 0;
    char* Sentence = malloc(size * sizeof(char));
    char key = getchar();
    Sentence[index] = key;
    index++;

    while(key != '\n')
    {
        key = getchar();
        Sentence[index] = key;
        index++;

        if (strcmp(Sentence,"Fin.") == 0)
        {
            break;
        }
        
        if(index+1 == size)
        {
           size += 15;
           Sentence = realloc(Sentence, size * sizeof(char));
        }
    }
    return Sentence;
}

char** InputText(int *count)
{
    int index = 0;
    int size = 10;
    char** SentenceS = malloc(size * sizeof(char*));

    while(1)
    {
       SentenceS[index] = InputSentence();

       if(strcmp(SentenceS[index], "Fin.") == 0)
       {
           break;
       }

       index++;

       if(index+1 == size)
       {
           size += 10;
           SentenceS = realloc(SentenceS, size * sizeof(char*));
       }
    }
    *count = index;
    return SentenceS;
}