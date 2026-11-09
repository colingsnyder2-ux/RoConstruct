// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct Obj{void m(int,int);};
void func(){((Obj*)0xcb857c)->m(-1,65535);}
