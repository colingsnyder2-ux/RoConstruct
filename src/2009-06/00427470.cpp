// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00427470 { int words[8]; };
extern void (__thiscall* str_ctor_00427470)(Str_00427470*, Str_00427470*);
struct X_00427470 {
    char pad[0x44];
    Str_00427470 value;
    Str_00427470* copy(Str_00427470* out);
};
Str_00427470* X_00427470::copy(Str_00427470* out)
{
    volatile int zero = 0;
    str_ctor_00427470(out, &value);
    return out;
}
