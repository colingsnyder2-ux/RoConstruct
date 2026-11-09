// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Str{int words[8];}; extern void (__thiscall* str_ctor)(Str*,Str*); struct X{char pad[0x60]; Str value; Str* copy(Str* out,int unused);}; Str* X::copy(Str* out,int unused){volatile int zero=0; str_ctor(out,&value); return out;}
