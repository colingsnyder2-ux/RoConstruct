// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005cd190 { int words[8]; };
extern void (__thiscall* str_ctor_005cd190)(Str_005cd190*, Str_005cd190*);
struct X_005cd190 {
    char pad[0x28];
    Str_005cd190 value;
    Str_005cd190* copy(Str_005cd190* out);
};
Str_005cd190* X_005cd190::copy(Str_005cd190* out)
{
    volatile int zero = 0;
    str_ctor_005cd190(out, &value);
    return out;
}
