// Implementation: C:\Users\colin\RoConstruct\tools\openrbx\Client\roc_espeon_fmod_b2ffaf4c16384e8e.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\005b87a0.cpp
#include "../3rdparty/fmod/api/inc/fmod_errors.h"

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


extern "C" __declspec(dllimport) char* __cdecl strncpy(char*, const char*, unsigned int);

struct Settings {
    char padding[0x133];
    unsigned char enabled;
};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> LoggerHandle;

Settings* __cdecl getSettings();

LoggerHandle __cdecl getLogger();
void __cdecl writeLog(void*, int, const char*, ...);

void __cdecl reportSoundError(int error)
{
    char text[512];
    if (error && getSettings()->enabled) {
        strncpy(text, FMOD_ErrorString(static_cast<FMOD_RESULT>(error)), 512);
        writeLog(getLogger().get(), 2, "FMOD %d: %s", error, text);
    }
}