// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0074d190 { int words[8]; };
extern void (__thiscall* str_ctor_0074d190)(Str_0074d190*, Str_0074d190*);
struct X_0074d190 {
    char pad[0x7c];
    Str_0074d190 value;
    Str_0074d190* copy(Str_0074d190* out);
};
Str_0074d190* X_0074d190::copy(Str_0074d190* out)
{
    volatile int zero = 0;
    str_ctor_0074d190(out, &value);
    return out;
}
