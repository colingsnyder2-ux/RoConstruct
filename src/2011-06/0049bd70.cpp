// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0049bd70 { int words[8]; };
extern void (__thiscall* str_ctor_0049bd70)(Str_0049bd70*, Str_0049bd70*);
struct X_0049bd70 {
    char pad[0xca0];
    Str_0049bd70 value;
    Str_0049bd70* copy(Str_0049bd70* out);
};
Str_0049bd70* X_0049bd70::copy(Str_0049bd70* out)
{
    volatile int zero = 0;
    str_ctor_0049bd70(out, &value);
    return out;
}
