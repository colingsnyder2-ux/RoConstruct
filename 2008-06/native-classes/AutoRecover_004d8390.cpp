// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct SlotResult {
    int a0;
    int a4;
    int a8;
    char ac;
};

extern "C" void* __stdcall fn_005875e0(void* desc);
extern "C" int __fastcall fn_004d81c0(void* self, int unusedEdx, SlotResult* out, int* a2, int a3, int a4);

// INFERRED: arg1 is a hidden return struct, arg2 a signal desc pointer; ecx is unused.
extern "C" SlotResult* __fastcall fn_004d8390(void* self, int unusedEdx, SlotResult* out, void* desc, int a3, int a4)
{
    if (desc) {
        void* sig = fn_005875e0(desc);
        fn_004d81c0((char*)sig + 0x10, 0, out, &a4, a3, 0);
        return out;
    }
    out->a4 = 0;
    out->a8 = 0;
    out->ac = 0;
    return out;
}
