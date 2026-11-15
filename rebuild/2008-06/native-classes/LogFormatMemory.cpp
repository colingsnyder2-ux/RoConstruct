#include "util/Log.h"
#include <cstdio>

std::string RBX::Log::formatMem(unsigned bytes)
{
    char buffer[64];
    if (bytes < 1000)
        sprintf(buffer, "%dB", bytes);
    else if (bytes < 1000 * 1000)
        sprintf(buffer, "%dKB", bytes / 1000);
    else if (bytes < 1000 * 1000 * 1000)
        sprintf(buffer, "%dMB", bytes / (1000 * 1000));
    else
        sprintf(buffer, "%dGB", bytes / (1000 * 1000 * 1000));
    return buffer;
}
