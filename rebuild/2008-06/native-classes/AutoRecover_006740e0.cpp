// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

extern "C" void fn_0067ca20(Elem8* dest, unsigned int count, const Elem8* value);
extern "C" int __fastcall fn_00671c90(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: std::vector<8-byte T>-like layout (MSVC 2008, no iterator debugging)
struct Vec8 {
    int field0;
    int field4;
    int alloc;      // +8
    char* first;    // +0xc
    char* last;     // +0x10
    char* end;      // +0x14
};

extern "C" void __fastcall fn_006740e0(Vec8* self, int unusedEdx, int arg)
{
    unsigned cap = self->first ? (unsigned)(self->end - self->first) >> 3 : 0;
    if (((unsigned)(self->last - self->first) >> 3) < cap) {
        int tmp;
        *(char*)&tmp = 0;
        fn_0067ca20(arg, 0, (int)self->last, 1, arg, (int)&self->alloc, arg, tmp);
        self->last += 8;
        return;
    }
    if (self->first > self->last)
        _invalid_parameter_noinfo();
    char local[8];
    fn_00671c90(self, 0, (int)local, self->field0, (int)self->last, arg);
}
