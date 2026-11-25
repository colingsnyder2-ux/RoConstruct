// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial, best-effort reconstruction. It is not byte-exact.
// INFERRED: the original receives lua_State* in ecx and the stack index in edi, an implicit register input.
// It also reads a descriptor pointer at [esp+4] and a by-value property object at [esp+8], and the caller pops them.
// The required ABI declaration has no stack parameters, so those slots are read relative to the return address.
// INFERRED: unusedEdx carries the lua stack index here, because edi cannot be expressed.
// INFERRED: the FunctionRef, shared_ptr, Vector3, CoordinateFrame, Color3, BrickColor, ContentId
// and enum branches are omitted.
#include <intrin.h>
#include <string>
#include <stdexcept>

#pragma intrinsic(_AddressOfReturnAddress)

struct lua_State;
struct TypeDesc { int pad[5]; const void* type; };   // type pointer at +0x14

extern "C" int lua_tointeger(lua_State*, int);
extern "C" int fn_00611fe0(int a1, int a2);
extern "C" int __fastcall fn_004ad240(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ad1e0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ad2a0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004adcf0(void* self, int unusedEdx, int a1);
extern "C" const void* fn_0056cbc0(void);
extern "C" const void* fn_0056cc30(void);
extern "C" const void* fn_0056cca0(void);
extern "C" const void* fn_0056cd10(void);
extern "C" float fn_0061c830(lua_State* L, int idx);

extern "C" void __fastcall fn_0061b190(lua_State* self, int unusedEdx)
{
    // INFERRED: stack argument layout taken from the disassembly
    char* args = (char*)_AddressOfReturnAddress() + 4;
    TypeDesc* desc = *(TypeDesc**)args;
    void* prop = args + 4;
    lua_State* L = self;
    int idx = unusedEdx;

    if (desc->type == fn_0056cbc0()) {
        int v = lua_tointeger(L, idx);
        fn_004ad240(prop, 0, (int)&v);
        return;
    }
    if (desc->type == fn_0056cc30()) {
        bool b = fn_00611fe0((int)L, idx) != 0;
        fn_004ad1e0(prop, 0, (int)&b);
        return;
    }
    if (desc->type == fn_0056cca0()) {
        float f = fn_0061c830(L, idx);
        fn_004ad2a0(prop, 0, (int)&f);
        return;
    }
    if (desc->type == fn_0056cd10()) {
        double d = fn_0061c830(L, idx);
        fn_004adcf0(prop, 0, (int)&d);
        return;
    }
    throw std::runtime_error("Unable to set property");
}
