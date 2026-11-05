// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006ba970 { int words[8]; };
extern void (__thiscall* str_ctor_006ba970)(Str_006ba970*, Str_006ba970*);
struct X_006ba970 {
    char pad[0xc4];
    Str_006ba970 value;
    Str_006ba970* copy(Str_006ba970* out);
};
Str_006ba970* X_006ba970::copy(Str_006ba970* out)
{
    volatile int zero = 0;
    str_ctor_006ba970(out, &value);
    return out;
}
