// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the callee at 0x5875e0 takes one stack argument (the instance) and
// returns the signal object. The other four pushed dwords are consumed by
// fn_0042b400, which has ret 0x10.
extern "C" char* __stdcall fn_005875e0(int instance);
extern "C" int __fastcall fn_0042b400(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: ecx is unused by the target; arg1 is an output/result block that is also returned.
extern "C" int* __fastcall fn_0042b680(void* self, int unusedEdx, int* out, int instance, int a3, int a4)
{
    if (instance != 0)
    {
        char* sig = fn_005875e0(instance);
        fn_0042b400(sig + 0x10, 0, (int)out, (int)&a4, a3, 0);
        return out;
    }
    out[1] = 0;
    out[2] = 0;
    *((char*)out + 0xc) = 0;
    return out;
}
