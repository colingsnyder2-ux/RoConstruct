// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <G3D/RegistryUtil.h>

extern "C" void fn_005014b0(unsigned int n);
extern "C" void fn_00501520(unsigned int n);

namespace RBX { namespace Render {

// 0x00501400
__int64 GetCyclesDifference(void (*fn)(unsigned int), unsigned int n);

int getCPUSpeed()
{
    int speed;
    bool ok;
    {
        std::string key("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\~MHz");
        ok = G3D::RegistryUtil::readInt32(key, speed);
    }

    if (ok && speed > 300)
        return speed;

    // INFERRED: fallback measurement of cycle count difference between two delay loops
    __int64 a = 0;
    __int64 b = 0;
    for (int i = 0; i < 2; ++i)
    {
        a += GetCyclesDifference(fn_005014b0, 50);
        b += GetCyclesDifference(fn_00501520, 50);
    }

    // INFERRED: result kept as a 64-bit value (explains the dead high-word store in the original)
    __int64 mhz = (a - b) / 2;
    mhz = mhz / 50;
    mhz = mhz / 1000;

    if (mhz < 100 || mhz > 50000)
    {
        // INFERRED: default of 1400 MHz when the measurement is out of range
        mhz = 1400;
    }
    return (int)mhz;
}

} }
