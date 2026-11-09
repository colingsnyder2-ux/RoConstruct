// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004207d0 { int words[8]; };
extern void (__thiscall* str_ctor_004207d0)(Str_004207d0*, Str_004207d0*);
struct X_004207d0 {
    char pad[0x40];
    Str_004207d0 value;
    Str_004207d0* copy(Str_004207d0* out);
};
Str_004207d0* X_004207d0::copy(Str_004207d0* out)
{
    volatile int zero = 0;
    str_ctor_004207d0(out, &value);
    return out;
}
