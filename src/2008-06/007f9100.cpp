// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
typedef void (__thiscall *Ctor)(void*,const char*); extern Ctor ctor; extern "C" void final(void*);
void func(){ctor((void*)0x97dc3c,(const char*)0x84e018);final((void*)0x8015a0);}
