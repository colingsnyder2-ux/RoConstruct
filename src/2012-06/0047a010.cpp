// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0047a010 { int words[8]; };
extern void (__thiscall* str_ctor_0047a010)(Str_0047a010*, Str_0047a010*);
struct X_0047a010 {
    char pad[0xcc];
    Str_0047a010 value;
    Str_0047a010* copy(Str_0047a010* out);
};
Str_0047a010* X_0047a010::copy(Str_0047a010* out)
{
    volatile int zero = 0;
    str_ctor_0047a010(out, &value);
    return out;
}
