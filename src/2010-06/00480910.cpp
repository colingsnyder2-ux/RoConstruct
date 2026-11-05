// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00480910 { int words[8]; };
extern void (__thiscall* str_ctor_00480910)(Str_00480910*, Str_00480910*);
struct X_00480910 {
    char pad[0x3c];
    Str_00480910 value;
    Str_00480910* copy(Str_00480910* out);
};
Str_00480910* X_00480910::copy(Str_00480910* out)
{
    volatile int zero = 0;
    str_ctor_00480910(out, &value);
    return out;
}
