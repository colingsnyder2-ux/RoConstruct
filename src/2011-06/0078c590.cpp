// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0078c590 { int words[8]; };
extern void (__thiscall* str_ctor_0078c590)(Str_0078c590*, Str_0078c590*);
struct X_0078c590 {
    char pad[0x20];
    Str_0078c590 value;
    Str_0078c590* copy(Str_0078c590* out);
};
Str_0078c590* X_0078c590::copy(Str_0078c590* out)
{
    volatile int zero = 0;
    str_ctor_0078c590(out, &value);
    return out;
}
