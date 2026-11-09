// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0068da00 { int words[8]; };
extern void (__thiscall* str_ctor_0068da00)(Str_0068da00*, Str_0068da00*);
struct X_0068da00 {
    char pad[0x28];
    Str_0068da00 value;
    Str_0068da00* copy(Str_0068da00* out);
};
Str_0068da00* X_0068da00::copy(Str_0068da00* out)
{
    volatile int zero = 0;
    str_ctor_0068da00(out, &value);
    return out;
}
