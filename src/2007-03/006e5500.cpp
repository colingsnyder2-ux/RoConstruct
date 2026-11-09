// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006e5500 { int words[8]; };
extern void (__thiscall* str_ctor_006e5500)(Str_006e5500*, Str_006e5500*);
struct X_006e5500 {
    char pad[0x34];
    Str_006e5500 value;
    Str_006e5500* copy(Str_006e5500* out);
};
Str_006e5500* X_006e5500::copy(Str_006e5500* out)
{
    volatile int zero = 0;
    str_ctor_006e5500(out, &value);
    return out;
}
