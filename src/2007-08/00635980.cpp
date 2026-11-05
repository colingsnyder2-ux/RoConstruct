// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00635980 { int words[8]; };
extern void (__thiscall* str_ctor_00635980)(Str_00635980*, Str_00635980*);
struct X_00635980 {
    char pad[0x54];
    Str_00635980 value;
    Str_00635980* copy(Str_00635980* out);
};
Str_00635980* X_00635980::copy(Str_00635980* out)
{
    volatile int zero = 0;
    str_ctor_00635980(out, &value);
    return out;
}
