// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0079c380 { int words[8]; };
extern void (__thiscall* str_ctor_0079c380)(Str_0079c380*, Str_0079c380*);
struct X_0079c380 {
    char pad[0x34];
    Str_0079c380 value;
    Str_0079c380* copy(Str_0079c380* out);
};
Str_0079c380* X_0079c380::copy(Str_0079c380* out)
{
    volatile int zero = 0;
    str_ctor_0079c380(out, &value);
    return out;
}
