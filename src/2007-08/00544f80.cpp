// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00544f80 { int words[8]; };
extern void (__thiscall* str_ctor_00544f80)(Str_00544f80*, Str_00544f80*);
struct X_00544f80 {
    char pad[0x34];
    Str_00544f80 value;
    Str_00544f80* copy(Str_00544f80* out);
};
Str_00544f80* X_00544f80::copy(Str_00544f80* out)
{
    volatile int zero = 0;
    str_ctor_00544f80(out, &value);
    return out;
}
