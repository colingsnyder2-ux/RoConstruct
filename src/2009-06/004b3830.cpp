// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004b3830 { int words[8]; };
extern void (__thiscall* str_ctor_004b3830)(Str_004b3830*, Str_004b3830*);
struct X_004b3830 {
    char pad[0xa8];
    Str_004b3830 value;
    Str_004b3830* copy(Str_004b3830* out);
};
Str_004b3830* X_004b3830::copy(Str_004b3830* out)
{
    volatile int zero = 0;
    str_ctor_004b3830(out, &value);
    return out;
}
