#pragma once
#include <stdio.h>

namespace AiEngine
{
    #define LOG(M, ...) printf(M "\n", __VA_ARGS__)
}