// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006f8c80 { int words[8]; };
extern void (__thiscall* str_ctor_006f8c80)(Str_006f8c80*, Str_006f8c80*);
struct X_006f8c80 {
    char pad[0x20];
    Str_006f8c80 value;
    Str_006f8c80* copy(Str_006f8c80* out);
};
Str_006f8c80* X_006f8c80::copy(Str_006f8c80* out)
{
    volatile int zero = 0;
    str_ctor_006f8c80(out, &value);
    return out;
}
