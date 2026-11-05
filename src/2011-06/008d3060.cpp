// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008d3060 { int words[8]; };
extern void (__thiscall* str_ctor_008d3060)(Str_008d3060*, Str_008d3060*);
struct X_008d3060 {
    char pad[0x28];
    Str_008d3060 value;
    Str_008d3060* copy(Str_008d3060* out);
};
Str_008d3060* X_008d3060::copy(Str_008d3060* out)
{
    volatile int zero = 0;
    str_ctor_008d3060(out, &value);
    return out;
}
