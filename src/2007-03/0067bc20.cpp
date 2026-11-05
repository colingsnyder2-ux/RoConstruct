// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0067bc20 { int words[8]; };
extern void (__thiscall* str_ctor_0067bc20)(Str_0067bc20*, Str_0067bc20*);
struct X_0067bc20 {
    char pad[0x40];
    Str_0067bc20 value;
    Str_0067bc20* copy(Str_0067bc20* out);
};
Str_0067bc20* X_0067bc20::copy(Str_0067bc20* out)
{
    volatile int zero = 0;
    str_ctor_0067bc20(out, &value);
    return out;
}
