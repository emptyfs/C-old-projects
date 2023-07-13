#pragma once

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

struct Sentence
{
    wchar_t* arr;
};

struct Text
{
    int senten;
    int size;
    struct Sentence *text;
};