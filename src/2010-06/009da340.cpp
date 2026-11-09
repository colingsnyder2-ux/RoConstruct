// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
typedef void (__thiscall *Ctor)(void*,const char*); extern Ctor ctor; extern "C" void final(void*);
void func(){ctor((void*)0xc2c428,(const char*)0xa88638);final((void*)0x9e9240);}
