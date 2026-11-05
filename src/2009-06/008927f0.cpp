// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
typedef void (__thiscall *Ctor)(void*,const char*); extern Ctor ctor; extern "C" void final(void*);
void func(){ctor((void*)0xa503f0,(const char*)0x8eef94);final((void*)0x89d1b0);}
