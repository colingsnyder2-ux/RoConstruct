// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0094e050 { int words[8]; };
extern void (__thiscall* str_ctor_0094e050)(Str_0094e050*, Str_0094e050*);
struct X_0094e050 {
    char pad[0xc];
    Str_0094e050 value;
    Str_0094e050* copy(Str_0094e050* out);
};
Str_0094e050* X_0094e050::copy(Str_0094e050* out)
{
    volatile int zero = 0;
    str_ctor_0094e050(out, &value);
    return out;
}
