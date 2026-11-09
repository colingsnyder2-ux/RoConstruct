// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006d0e60 { int words[8]; };
extern void (__thiscall* str_ctor_006d0e60)(Str_006d0e60*, Str_006d0e60*);
struct X_006d0e60 {
    char pad[0x280];
    Str_006d0e60 value;
    Str_006d0e60* copy(Str_006d0e60* out);
};
Str_006d0e60* X_006d0e60::copy(Str_006d0e60* out)
{
    volatile int zero = 0;
    str_ctor_006d0e60(out, &value);
    return out;
}
