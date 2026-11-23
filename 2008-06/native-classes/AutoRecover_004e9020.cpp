// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Slot { int a; int b; int c; };
extern "C" void* __stdcall fn_005875e0(void* desc);
extern "C" int __fastcall fn_004e8e70(void* self, int unusedEdx, void* a1, void* a2, void* a3, int a4);

// INFERRED: 5875e0 takes one stack arg (no ecx set); remaining 4 pushes feed 4e8e70.
extern "C" Slot* __fastcall fn_004e9020(void* self, int unusedEdx, Slot* out, void* desc, void* a3, void* a4)
{
    volatile int zero = 0;
    (void)zero;
    if (desc) {
        void* sig = fn_005875e0(desc);
        fn_004e8e70((char*)sig + 0x10, 0, out, &a4, a3, 0);
        return out;
    }
    out->b = 0;
    out->c = 0;
    *((char*)out + 0xc) = 0;
    return out;
}
