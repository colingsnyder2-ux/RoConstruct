// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00430300 { int words[8]; };
extern void (__thiscall* str_ctor_00430300)(Str_00430300*, Str_00430300*);
struct X_00430300 {
    char pad[0x48];
    Str_00430300 value;
    Str_00430300* copy(Str_00430300* out);
};
Str_00430300* X_00430300::copy(Str_00430300* out)
{
    volatile int zero = 0;
    str_ctor_00430300(out, &value);
    return out;
}
