// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0073f060 { int words[8]; };
extern void (__thiscall* str_ctor_0073f060)(Str_0073f060*, Str_0073f060*);
struct X_0073f060 {
    char pad[0x204];
    Str_0073f060 value;
    Str_0073f060* copy(Str_0073f060* out);
};
Str_0073f060* X_0073f060::copy(Str_0073f060* out)
{
    volatile int zero = 0;
    str_ctor_0073f060(out, &value);
    return out;
}
