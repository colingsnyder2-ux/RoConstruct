// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0079c350 { int words[8]; };
extern void (__thiscall* str_ctor_0079c350)(Str_0079c350*, Str_0079c350*);
struct X_0079c350 {
    char pad[0x2c];
    Str_0079c350 value;
    Str_0079c350* copy(Str_0079c350* out);
};
Str_0079c350* X_0079c350::copy(Str_0079c350* out)
{
    volatile int zero = 0;
    str_ctor_0079c350(out, &value);
    return out;
}
