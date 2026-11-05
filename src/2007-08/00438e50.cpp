// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00438e50 { int words[8]; };
extern void (__thiscall* str_ctor_00438e50)(Str_00438e50*, Str_00438e50*);
struct X_00438e50 {
    char pad[0xa0];
    Str_00438e50 value;
    Str_00438e50* copy(Str_00438e50* out);
};
Str_00438e50* X_00438e50::copy(Str_00438e50* out)
{
    volatile int zero = 0;
    str_ctor_00438e50(out, &value);
    return out;
}
