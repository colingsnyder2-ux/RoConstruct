// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005fd7a0 { int words[8]; };
extern void (__thiscall* str_ctor_005fd7a0)(Str_005fd7a0*, Str_005fd7a0*);
struct X_005fd7a0 {
    char pad[0x20];
    Str_005fd7a0 value;
    Str_005fd7a0* copy(Str_005fd7a0* out);
};
Str_005fd7a0* X_005fd7a0::copy(Str_005fd7a0* out)
{
    volatile int zero = 0;
    str_ctor_005fd7a0(out, &value);
    return out;
}
