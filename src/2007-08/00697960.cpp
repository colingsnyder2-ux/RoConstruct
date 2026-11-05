// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00697960 { int words[8]; };
extern void (__thiscall* str_ctor_00697960)(Str_00697960*, Str_00697960*);
struct X_00697960 {
    char pad[0xac];
    Str_00697960 value;
    Str_00697960* copy(Str_00697960* out);
};
Str_00697960* X_00697960::copy(Str_00697960* out)
{
    volatile int zero = 0;
    str_ctor_00697960(out, &value);
    return out;
}
