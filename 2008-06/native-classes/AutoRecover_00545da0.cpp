// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: args are two 8-byte by-value iterator structs (ebp+8, ebp+0x10); real types unknown.
struct Iter { int a; int b; };

struct Self545da0 {
    unsigned int count;   // [0]
    unsigned int modulo;  // [4]
};

extern "C" void __fastcall fn_00540f50(Iter* self, int unusedEdx);
extern "C" bool __fastcall fn_00540f20(Iter* self, int unusedEdx, Iter* other);
extern "C" void* __fastcall fn_005462c0(Iter* self, int unusedEdx);
extern "C" int __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" int __fastcall fn_00546290(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00546210(void* self, int unusedEdx, int* a1);

extern "C" void __fastcall fn_00545da0(Self545da0* self, int unusedEdx, Iter cur, Iter end)
{
    unsigned int i = 0;
    for (;; fn_00540f50(&cur, 0)) {
        if (!fn_00540f20(&cur, 0, &end))
            break;
        int q = fn_00540e80(fn_005462c0(&cur, 0), 0);
        int* p = &q;
        char* e = (char*)fn_00546290((char*)self + 8, 0, (int)i);
        fn_00546210(e + 0xc, 0, p);
        i = (i + 1) % self->modulo;
        self->count++;
    }
}
