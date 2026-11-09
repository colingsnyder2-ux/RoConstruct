// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0041d830 { int words[8]; };
extern void (__thiscall* str_ctor_0041d830)(Str_0041d830*, Str_0041d830*);
struct X_0041d830 {
    char pad[0x74];
    Str_0041d830 value;
    Str_0041d830* copy(Str_0041d830* out);
};
Str_0041d830* X_0041d830::copy(Str_0041d830* out)
{
    volatile int zero = 0;
    str_ctor_0041d830(out, &value);
    return out;
}
