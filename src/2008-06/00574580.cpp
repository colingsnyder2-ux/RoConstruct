// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00574580 { int words[8]; };
extern void (__thiscall* str_ctor_00574580)(Str_00574580*, Str_00574580*);
struct X_00574580 {
    char pad[0x144];
    Str_00574580 value;
    Str_00574580* copy(Str_00574580* out);
};
Str_00574580* X_00574580::copy(Str_00574580* out)
{
    volatile int zero = 0;
    str_ctor_00574580(out, &value);
    return out;
}
