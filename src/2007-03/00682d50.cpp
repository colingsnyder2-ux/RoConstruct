// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00682d50 { int words[8]; };
extern void (__thiscall* str_ctor_00682d50)(Str_00682d50*, Str_00682d50*);
struct X_00682d50 {
    char pad[0xac];
    Str_00682d50 value;
    Str_00682d50* copy(Str_00682d50* out);
};
Str_00682d50* X_00682d50::copy(Str_00682d50* out)
{
    volatile int zero = 0;
    str_ctor_00682d50(out, &value);
    return out;
}
