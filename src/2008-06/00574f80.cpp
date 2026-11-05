// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{void f();}; typedef void(__thiscall* Fn)(void*,const char*); extern Fn assign;
void S::f(){assign((char*)this+564,"[[[progress]]]");}
