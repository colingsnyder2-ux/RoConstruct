// native-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <windows.h>

double sub_00455d70()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    return (time.wHour * 60 + time.wMinute) * 60
         + time.wMilliseconds * 0.001f;
}
