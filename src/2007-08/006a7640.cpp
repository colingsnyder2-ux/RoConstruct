// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006a7640 { int words[8]; };
extern void (__thiscall* str_ctor_006a7640)(Str_006a7640*, Str_006a7640*);
struct X_006a7640 {
    char pad[0x98];
    Str_006a7640 value;
    Str_006a7640* copy(Str_006a7640* out);
};
Str_006a7640* X_006a7640::copy(Str_006a7640* out)
{
    volatile int zero = 0;
    str_ctor_006a7640(out, &value);
    return out;
}
