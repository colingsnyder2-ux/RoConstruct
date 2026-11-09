// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007d8410 { int words[8]; };
extern void (__thiscall* str_ctor_007d8410)(Str_007d8410*, Str_007d8410*);
struct X_007d8410 {
    char pad[0x280];
    Str_007d8410 value;
    Str_007d8410* copy(Str_007d8410* out);
};
Str_007d8410* X_007d8410::copy(Str_007d8410* out)
{
    volatile int zero = 0;
    str_ctor_007d8410(out, &value);
    return out;
}
