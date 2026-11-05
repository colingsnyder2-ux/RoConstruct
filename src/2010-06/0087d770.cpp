// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0087d770 { int words[8]; };
extern void (__thiscall* str_ctor_0087d770)(Str_0087d770*, Str_0087d770*);
struct X_0087d770 {
    char pad[0x20];
    Str_0087d770 value;
    Str_0087d770* copy(Str_0087d770* out);
};
Str_0087d770* X_0087d770::copy(Str_0087d770* out)
{
    volatile int zero = 0;
    str_ctor_0087d770(out, &value);
    return out;
}
