// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00431650 { int words[8]; };
extern void (__thiscall* str_ctor_00431650)(Str_00431650*, Str_00431650*);
struct X_00431650 {
    char pad[0xa4];
    Str_00431650 value;
    Str_00431650* copy(Str_00431650* out);
};
Str_00431650* X_00431650::copy(Str_00431650* out)
{
    volatile int zero = 0;
    str_ctor_00431650(out, &value);
    return out;
}
