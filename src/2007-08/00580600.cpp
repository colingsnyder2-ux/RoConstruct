// from server: 100% by Intel_Inside
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

#include <string>
#include <ymath.h>
#include <stdio.h>

namespace RBX {
struct Log {
    static std::string formatTime(const float& time);
};

std::string Log::formatTime(const float& time)
{
    if (time == _Inf._Float)
        return std::string("INF");
    if (time == -_Inf._Float)
        return std::string("-INF");
    if (time == _Nan._Float)
        return std::string("NAN");
    if (time == _Snan._Float)
        return std::string("NAN");
    char buf[32];
    _snprintf(buf, 32, "%.9g", time);
    return std::string(buf);
}
}
