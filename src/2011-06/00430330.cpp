// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00430330 { int words[8]; };
extern void (__thiscall* str_ctor_00430330)(Str_00430330*, Str_00430330*);
struct X_00430330 {
    char pad[0x44];
    Str_00430330 value;
    Str_00430330* copy(Str_00430330* out);
};
Str_00430330* X_00430330::copy(Str_00430330* out)
{
    volatile int zero = 0;
    str_ctor_00430330(out, &value);
    return out;
}
