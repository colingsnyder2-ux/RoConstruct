// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ int p[4]; void (__thiscall *fn)(char*,int,int); int adj; char* obj; int x; void f(int a);};
void S::f(int a){ fn(adj+obj,a,x);}
