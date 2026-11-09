// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
typedef void (__thiscall *Ctor)(void*,const char*); extern Ctor ctor; extern "C" void final(void*);
void func(){ctor((void*)0xa58850,(const char*)0x923a08);final((void*)0x89d640);}
