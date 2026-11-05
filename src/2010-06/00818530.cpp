// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00818530 { int words[8]; };
extern void (__thiscall* str_ctor_00818530)(Str_00818530*, Str_00818530*);
struct X_00818530 {
    char pad[0xb0];
    Str_00818530 value;
    Str_00818530* copy(Str_00818530* out);
};
Str_00818530* X_00818530::copy(Str_00818530* out)
{
    volatile int zero = 0;
    str_ctor_00818530(out, &value);
    return out;
}
