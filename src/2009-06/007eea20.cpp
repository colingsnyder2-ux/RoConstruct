// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007eea20 { int words[8]; };
extern void (__thiscall* str_ctor_007eea20)(Str_007eea20*, Str_007eea20*);
struct X_007eea20 {
    char pad[0x20];
    Str_007eea20 value;
    Str_007eea20* copy(Str_007eea20* out);
};
Str_007eea20* X_007eea20::copy(Str_007eea20* out)
{
    volatile int zero = 0;
    str_ctor_007eea20(out, &value);
    return out;
}
