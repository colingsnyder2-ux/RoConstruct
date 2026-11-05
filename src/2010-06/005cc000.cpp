// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005cc000 { int words[8]; };
extern void (__thiscall* str_ctor_005cc000)(Str_005cc000*, Str_005cc000*);
struct X_005cc000 {
    char pad[0xb60];
    Str_005cc000 value;
    Str_005cc000* copy(Str_005cc000* out);
};
Str_005cc000* X_005cc000::copy(Str_005cc000* out)
{
    volatile int zero = 0;
    str_ctor_005cc000(out, &value);
    return out;
}
