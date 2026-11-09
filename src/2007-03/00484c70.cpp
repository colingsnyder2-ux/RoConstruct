// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00484c70 { int words[8]; };
extern void (__thiscall* str_ctor_00484c70)(Str_00484c70*, Str_00484c70*);
struct X_00484c70 {
    char pad[0x168];
    Str_00484c70 value;
    Str_00484c70* copy(Str_00484c70* out);
};
Str_00484c70* X_00484c70::copy(Str_00484c70* out)
{
    volatile int zero = 0;
    str_ctor_00484c70(out, &value);
    return out;
}
