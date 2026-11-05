// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00794660 { int words[8]; };
extern void (__thiscall* str_ctor_00794660)(Str_00794660*, Str_00794660*);
struct X_00794660 {
    char pad[0x28];
    Str_00794660 value;
    Str_00794660* copy(Str_00794660* out);
};
Str_00794660* X_00794660::copy(Str_00794660* out)
{
    volatile int zero = 0;
    str_ctor_00794660(out, &value);
    return out;
}
