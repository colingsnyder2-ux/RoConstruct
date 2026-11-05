// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0044d310 { int words[8]; };
extern void (__thiscall* str_ctor_0044d310)(Str_0044d310*, Str_0044d310*);
struct X_0044d310 {
    char pad[0x8c];
    Str_0044d310 value;
    Str_0044d310* copy(Str_0044d310* out);
};
Str_0044d310* X_0044d310::copy(Str_0044d310* out)
{
    volatile int zero = 0;
    str_ctor_0044d310(out, &value);
    return out;
}
