// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00469080 { int words[8]; };
extern void (__thiscall* str_ctor_00469080)(Str_00469080*, Str_00469080*);
struct X_00469080 {
    char pad[0x3c];
    Str_00469080 value;
    Str_00469080* copy(Str_00469080* out);
};
Str_00469080* X_00469080::copy(Str_00469080* out)
{
    volatile int zero = 0;
    str_ctor_00469080(out, &value);
    return out;
}
