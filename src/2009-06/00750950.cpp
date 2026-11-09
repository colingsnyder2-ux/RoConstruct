// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00750950 { int words[8]; };
extern void (__thiscall* str_ctor_00750950)(Str_00750950*, Str_00750950*);
struct X_00750950 {
    char pad[0x7c];
    Str_00750950 value;
    Str_00750950* copy(Str_00750950* out);
};
Str_00750950* X_00750950::copy(Str_00750950* out)
{
    volatile int zero = 0;
    str_ctor_00750950(out, &value);
    return out;
}
