// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00816030 { int words[8]; };
extern void (__thiscall* str_ctor_00816030)(Str_00816030*, Str_00816030*);
struct X_00816030 {
    char pad[0x54];
    Str_00816030 value;
    Str_00816030* copy(Str_00816030* out);
};
Str_00816030* X_00816030::copy(Str_00816030* out)
{
    volatile int zero = 0;
    str_ctor_00816030(out, &value);
    return out;
}
