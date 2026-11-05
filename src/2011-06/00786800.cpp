// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00786800 { int words[8]; };
extern void (__thiscall* str_ctor_00786800)(Str_00786800*, Str_00786800*);
struct X_00786800 {
    char pad[0x28];
    Str_00786800 value;
    Str_00786800* copy(Str_00786800* out);
};
Str_00786800* X_00786800::copy(Str_00786800* out)
{
    volatile int zero = 0;
    str_ctor_00786800(out, &value);
    return out;
}
