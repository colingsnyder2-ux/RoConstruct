// >>> native-status (generated) -- do not edit >>>
// LogFormatTime | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 28214486 | roc native-status --write
#include "util/Log.h"
#include <cstdio>

std::string RBX::Log::formatTime(double time)
{
    char buffer[64];
    if (time == 0.0)
        sprintf(buffer, "0s");
    if (time < 0.0)
        sprintf(buffer, "%.3gs", time);
    else if (time >= 0.1)
        sprintf(buffer, "%.3gs", time);
    else
        sprintf(buffer, "%.3gms", time * 1000.0);
    return buffer;
}
