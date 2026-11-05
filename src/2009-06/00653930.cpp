// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00653930 { int words[8]; };
extern void (__thiscall* str_ctor_00653930)(Str_00653930*, Str_00653930*);
struct X_00653930 {
    char pad[0x24];
    Str_00653930 value;
    Str_00653930* copy(Str_00653930* out);
};
Str_00653930* X_00653930::copy(Str_00653930* out)
{
    volatile int zero = 0;
    str_ctor_00653930(out, &value);
    return out;
}
