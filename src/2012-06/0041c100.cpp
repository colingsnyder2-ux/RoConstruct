// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
void g(int,int,void*); struct A{ void f(int a,int b){ g(a,b,this);} }; void h(A*p,int a,int b){p->f(a,b);}
