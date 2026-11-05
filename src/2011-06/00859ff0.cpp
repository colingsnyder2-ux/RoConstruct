// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00859ff0 { int words[8]; };
extern void (__thiscall* str_ctor_00859ff0)(Str_00859ff0*, Str_00859ff0*);
struct X_00859ff0 {
    char pad[0xf0];
    Str_00859ff0 value;
    Str_00859ff0* copy(Str_00859ff0* out);
};
Str_00859ff0* X_00859ff0::copy(Str_00859ff0* out)
{
    volatile int zero = 0;
    str_ctor_00859ff0(out, &value);
    return out;
}
