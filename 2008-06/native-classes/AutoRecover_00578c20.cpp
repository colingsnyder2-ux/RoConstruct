// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header available; callees declared by address. Target is a
// __thiscall member with one stack arg, written as __fastcall(self, edx, arg) -> ret 4.

struct ArrayAndFlags {
    unsigned char array[0xc];   // G3D::Array<Vector4>
    unsigned char flagA;        // +0xc
    unsigned char flagB;        // +0xd
};

extern "C" int   fn_00574fe0(void* self);                                           // cdecl, returns mode 0..4
extern "C" ArrayAndFlags* fn_00577690();                                            // cdecl, no args
extern "C" void  __fastcall fn_00576f90(void* dst, int unusedEdx, const void* src); // G3D::Array<Vector4>::operator=
extern "C" void* __fastcall fn_004125d0(void* self, int unusedEdx);                 // ServiceProvider::find<Players>
extern "C" void  __fastcall fn_004995d0(void* players, int unusedEdx, ArrayAndFlags* arg);
extern "C" void* fn_0049ac80(void* instance);                                       // Players::findLocalPlayer (static, cdecl)
extern "C" void  __fastcall fn_004930d0(void* player, int unusedEdx, ArrayAndFlags* arg);

extern "C" void __fastcall fn_00578c20(void* self, int unusedEdx, ArrayAndFlags* arg)
{
    switch (fn_00574fe0(self)) {
    case 0:
        if (self) {
            void* players = fn_004125d0(self, 0);
            if (players)
                fn_004995d0(players, 0, arg);
        }
        break;
    case 1:
    case 2: {
        void* player = fn_0049ac80(self);
        if (player)
            fn_004930d0(player, 0, arg);
        break;
    }
    case 3:
    case 4: {
        ArrayAndFlags* src = fn_00577690();
        fn_00576f90(arg, 0, src);
        arg->flagA = src->flagA;
        arg->flagB = src->flagB;
        break;
    }
    }
}
