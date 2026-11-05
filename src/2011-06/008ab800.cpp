// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008ab800 { int words[8]; };
extern void (__thiscall* str_ctor_008ab800)(Str_008ab800*, Str_008ab800*);
struct X_008ab800 {
    char pad[0x30];
    Str_008ab800 value;
    Str_008ab800* copy(Str_008ab800* out);
};
Str_008ab800* X_008ab800::copy(Str_008ab800* out)
{
    volatile int zero = 0;
    str_ctor_008ab800(out, &value);
    return out;
}
