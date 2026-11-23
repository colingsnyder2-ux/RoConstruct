// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: raw offset writes; class layout for this Stats::Item subclass is unknown.
extern "C" void __fastcall fn_0045ebe0(void* self, int unusedEdx);
extern "C" bool fn_0060a2f0(void* args);

struct LocalArgs {
    unsigned int a;
    unsigned int b;
};

static inline void setPtr(void* self, int off, unsigned int v) {
    *(unsigned int*)((char*)self + off) = v;
}

extern "C" void* __fastcall fn_0045ecc0(void* self, int unusedEdx, unsigned int arg) {
    fn_0045ebe0(self, 0);
    LocalArgs local;
    local.a = 0x5ec170;
    setPtr(self, 0x00, 0x81a08c);
    setPtr(self, 0x10, 0x81a07c);
    setPtr(self, 0x14, 0x81a074);
    setPtr(self, 0x20, 0x81a06c);
    setPtr(self, 0x24, 0x81a05c);
    setPtr(self, 0x44, 0x81a04c);
    setPtr(self, 0x64, 0x81a03c);
    setPtr(self, 0x84, 0x81a02c);
    setPtr(self, 0xa4, 0x81a01c);
    setPtr(self, 0xc4, 0x81a00c);
    local.b = arg;
    setPtr(self, 0x158, 0);
    if (!fn_0060a2f0(&local)) {
        unsigned int* dst = (unsigned int*)((char*)self + 0x160);
        if (dst) {
            dst[0] = local.a;
            dst[1] = local.b;
        }
        setPtr(self, 0x158, 0x819cdc);
        return self;
    }
    setPtr(self, 0x158, 0);
    return self;
}
