// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00646c50 { int words[8]; };
extern void (__thiscall* str_ctor_00646c50)(Str_00646c50*, Str_00646c50*);
struct X_00646c50 {
    char pad[0x24];
    Str_00646c50 value;
    Str_00646c50* copy(Str_00646c50* out);
};
Str_00646c50* X_00646c50::copy(Str_00646c50* out)
{
    volatile int zero = 0;
    str_ctor_00646c50(out, &value);
    return out;
}
