// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00746440 { int words[8]; };
extern void (__thiscall* str_ctor_00746440)(Str_00746440*, Str_00746440*);
struct X_00746440 {
    char pad[0x30];
    Str_00746440 value;
    Str_00746440* copy(Str_00746440* out);
};
Str_00746440* X_00746440::copy(Str_00746440* out)
{
    volatile int zero = 0;
    str_ctor_00746440(out, &value);
    return out;
}
