// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0073f150 { int words[8]; };
extern void (__thiscall* str_ctor_0073f150)(Str_0073f150*, Str_0073f150*);
struct X_0073f150 {
    char pad[0x24];
    Str_0073f150 value;
    Str_0073f150* copy(Str_0073f150* out);
};
Str_0073f150* X_0073f150::copy(Str_0073f150* out)
{
    volatile int zero = 0;
    str_ctor_0073f150(out, &value);
    return out;
}
