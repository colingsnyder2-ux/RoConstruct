// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0042f210 { int words[8]; };
extern void (__thiscall* str_ctor_0042f210)(Str_0042f210*, Str_0042f210*);
struct X_0042f210 {
    char pad[0x44];
    Str_0042f210 value;
    Str_0042f210* copy(Str_0042f210* out);
};
Str_0042f210* X_0042f210::copy(Str_0042f210* out)
{
    volatile int zero = 0;
    str_ctor_0042f210(out, &value);
    return out;
}
