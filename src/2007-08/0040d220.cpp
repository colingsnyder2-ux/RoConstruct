// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0040d220 { int words[8]; };
extern void (__thiscall* str_ctor_0040d220)(Str_0040d220*, Str_0040d220*);
struct X_0040d220 {
    char pad[0xc8];
    Str_0040d220 value;
    Str_0040d220* copy(Str_0040d220* out);
};
Str_0040d220* X_0040d220::copy(Str_0040d220* out)
{
    volatile int zero = 0;
    str_ctor_0040d220(out, &value);
    return out;
}
