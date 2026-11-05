// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00438df0 { int words[8]; };
extern void (__thiscall* str_ctor_00438df0)(Str_00438df0*, Str_00438df0*);
struct X_00438df0 {
    char pad[0xa8];
    Str_00438df0 value;
    Str_00438df0* copy(Str_00438df0* out);
};
Str_00438df0* X_00438df0::copy(Str_00438df0* out)
{
    volatile int zero = 0;
    str_ctor_00438df0(out, &value);
    return out;
}
