// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008a5c10 { int words[8]; };
extern void (__thiscall* str_ctor_008a5c10)(Str_008a5c10*, Str_008a5c10*);
struct X_008a5c10 {
    char pad[0x98];
    Str_008a5c10 value;
    Str_008a5c10* copy(Str_008a5c10* out);
};
Str_008a5c10* X_008a5c10::copy(Str_008a5c10* out)
{
    volatile int zero = 0;
    str_ctor_008a5c10(out, &value);
    return out;
}
