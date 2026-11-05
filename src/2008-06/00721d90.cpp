// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00721d90 { int words[8]; };
extern void (__thiscall* str_ctor_00721d90)(Str_00721d90*, Str_00721d90*);
struct X_00721d90 {
    char pad[0x98];
    Str_00721d90 value;
    Str_00721d90* copy(Str_00721d90* out);
};
Str_00721d90* X_00721d90::copy(Str_00721d90* out)
{
    volatile int zero = 0;
    str_ctor_00721d90(out, &value);
    return out;
}
