// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006ace30 { int words[8]; };
extern void (__thiscall* str_ctor_006ace30)(Str_006ace30*, Str_006ace30*);
struct X_006ace30 {
    char pad[0x28];
    Str_006ace30 value;
    Str_006ace30* copy(Str_006ace30* out);
};
Str_006ace30* X_006ace30::copy(Str_006ace30* out)
{
    volatile int zero = 0;
    str_ctor_006ace30(out, &value);
    return out;
}
