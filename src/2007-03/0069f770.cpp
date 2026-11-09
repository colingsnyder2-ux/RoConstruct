// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0069f770 { int words[8]; };
extern void (__thiscall* str_ctor_0069f770)(Str_0069f770*, Str_0069f770*);
struct X_0069f770 {
    char pad[0x2c];
    Str_0069f770 value;
    Str_0069f770* copy(Str_0069f770* out);
};
Str_0069f770* X_0069f770::copy(Str_0069f770* out)
{
    volatile int zero = 0;
    str_ctor_0069f770(out, &value);
    return out;
}
