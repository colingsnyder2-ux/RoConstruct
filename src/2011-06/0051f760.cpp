// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x7]; void f(char v);};
void S::f(char v){*(char*)((char*)this+0x7)=v;}
