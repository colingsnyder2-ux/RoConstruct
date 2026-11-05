// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00416f60 { int words[8]; };
extern void (__thiscall* str_ctor_00416f60)(Str_00416f60*, Str_00416f60*);
struct X_00416f60 {
    char pad[0x44];
    Str_00416f60 value;
    Str_00416f60* copy(Str_00416f60* out);
};
Str_00416f60* X_00416f60::copy(Str_00416f60* out)
{
    volatile int zero = 0;
    str_ctor_00416f60(out, &value);
    return out;
}
