// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
typedef void (__thiscall *Fn)(void*); extern Fn release; extern int a,b;
void func(){release(&a); release(&b);}
