// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the 8-byte values are small pair structs (e.g. points/sizes), copied as two dwords.
struct Pair8 {
    int a;
    int b;
};

extern "C" Pair8* __fastcall fn_00540660(void* self, int unusedEdx, void* a1);
extern "C" Pair8* __fastcall fn_00540630(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_00541400(void* self, int unusedEdx, void* a1, int a2, int a3, int a4, int a5);

extern "C" int __fastcall fn_00540780(void* self, int unusedEdx)
{
    Pair8 tmp1;
    Pair8 tmp2;
    Pair8 out;

    Pair8 first = *fn_00540660(self, 0, &tmp1);
    Pair8 second = *fn_00540630(self, 0, &tmp2);

    return fn_00541400(self, 0, &out, second.a, second.b, first.a, first.b);
}
