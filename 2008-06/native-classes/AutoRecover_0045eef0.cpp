// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object layout unknown; vtable stores done through byte offsets.
// INFERRED: 8-byte local is {static data ptr 0x5ec170, ctor arg}, copied to self+0x160 on convert failure.

struct Pair8 {
    const void* a;
    int b;
};

extern "C" char vt_0081a154[], vt_0081a144[], vt_0081a13c[], vt_0081a134[], vt_0081a124[];
extern "C" char vt_0081a114[], vt_0081a104[], vt_0081a0f4[], vt_0081a0e4[], vt_0081a0d4[];
extern "C" char vt_00819ce4[];
extern "C" char data_005ec170[];

extern "C" void* __fastcall fn_0045ebe0(void* self, int unusedEdx);
extern "C" bool fn_0060a2f0(Pair8* out);

#define AT(off) (*(const void**)((char*)self + (off)))

extern "C" void* __fastcall fn_0045eef0(void* self, int unusedEdx, int arg)
{
    fn_0045ebe0(self, 0);

    Pair8 v;
    v.a = data_005ec170;
    AT(0x00) = vt_0081a154;
    AT(0x10) = vt_0081a144;
    AT(0x14) = vt_0081a13c;
    AT(0x20) = vt_0081a134;
    AT(0x24) = vt_0081a124;
    AT(0x44) = vt_0081a114;
    AT(0x64) = vt_0081a104;
    AT(0x84) = vt_0081a0f4;
    AT(0xa4) = vt_0081a0e4;
    AT(0xc4) = vt_0081a0d4;
    v.b = arg;
    AT(0x158) = 0;

    if (!fn_0060a2f0(&v)) {
        Pair8* dst = (Pair8*)((char*)self + 0x160);
        if (dst)
            *dst = v;
        AT(0x158) = vt_00819ce4;
        return self;
    }
    AT(0x158) = 0;
    return self;
}
