// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00601f70 { int words[8]; };
extern void (__thiscall* str_ctor_00601f70)(Str_00601f70*, Str_00601f70*);
struct X_00601f70 {
    char pad[0xa4];
    Str_00601f70 value;
    Str_00601f70* copy(Str_00601f70* out);
};
Str_00601f70* X_00601f70::copy(Str_00601f70* out)
{
    volatile int zero = 0;
    str_ctor_00601f70(out, &value);
    return out;
}
