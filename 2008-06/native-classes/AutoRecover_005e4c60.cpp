// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void* fn_006a0920(unsigned int size);
extern "C" int __fastcall fn_005e41d0(void* self, int unusedEdx, void* a1);
void __cdecl operator delete(void*);

// INFERRED: unknown globals are vtable addresses; declared as opaque externs
extern "C" char g_0083e13c[];
extern "C" char g_0083f4dc[];
extern "C" char g_0083f4d0[];
extern "C" char g_0083f4c8[];
extern "C" char g_0083f4c0[];
extern "C" char g_0083f4b0[];
extern "C" char g_0083f4a0[];
extern "C" char g_0083f490[];
extern "C" char g_0083f480[];
extern "C" char g_0083f470[];
extern "C" char g_0083f460[];
extern "C" char g_0083f448[];

namespace RBX {
struct RotateJoint {
    unsigned int words[49];
    RotateJoint();
};
}

struct Connector : RBX::RotateJoint {
    float value;
    // INFERRED: class-level allocation routes to the original allocator func_006a0920
    static void* operator new(unsigned int n) { return fn_006a0920(n); }
    Connector() : RBX::RotateJoint(), value(0.0f) {
        words[0] = (unsigned int)g_0083e13c;
    }
};

struct Factory {
    unsigned int words[77];
    // INFERRED: base-constructor helper func_005e41d0 called as a true __thiscall
    // (no edx setup); bound at link time to the fastcall C-linkage symbol.
    int fn_005e41d0(void* a1);
};

// INFERRED: thiscall(ecx, 1 stack arg) is ABI-compatible with fastcall(ecx, dummy edx, 1 stack arg)
#pragma comment(linker, "/alternatename:?fn_005e41d0@Factory@@QAEHPAX@Z=@fn_005e41d0@12")

extern "C" Factory* __fastcall fn_005e4c60(Factory* self, int unusedEdx)
{
    Connector* c = new Connector;
    self->fn_005e41d0(c);
    self->words[0]  = (unsigned int)g_0083f4dc;
    self->words[4]  = (unsigned int)g_0083f4d0;
    self->words[5]  = (unsigned int)g_0083f4c8;
    self->words[8]  = (unsigned int)g_0083f4c0;
    self->words[9]  = (unsigned int)g_0083f4b0;
    self->words[17] = (unsigned int)g_0083f4a0;
    self->words[25] = (unsigned int)g_0083f490;
    self->words[33] = (unsigned int)g_0083f480;
    self->words[41] = (unsigned int)g_0083f470;
    self->words[49] = (unsigned int)g_0083f460;
    self->words[76] = (unsigned int)g_0083f448;
    return self;
}
