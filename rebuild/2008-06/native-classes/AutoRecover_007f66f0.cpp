// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: Accessor descriptors contain a code address, adjustment, and zero.
struct Accessor
{
    void* function;
    int adjustment;
    int zero;
};

extern "C" int __fastcall fn_005da980(
    void* self, int unusedEdx, const char* name, const char* category,
    Accessor getter, Accessor setter, int flags);

extern "C" void fn_005d74b0();
extern "C" void fn_005dbe70();
extern "C" void __cdecl fn_007ff380();

namespace RBX
{
    // INFERRED: Descriptor size is based on adjacent property addresses.
    struct HealthProperty
    {
        char storage[28];

        __forceinline HealthProperty()
        {
            Accessor setter = { (void*)&fn_005dbe70, -332, 0 };
            Accessor getter = { (void*)&fn_005d74b0, -332, 0 };
            fn_005da980(this, -332, "Health", "Game", getter, setter, 5);
            atexit(fn_007ff380);
        }
    };

    HealthProperty propHealth;
}
