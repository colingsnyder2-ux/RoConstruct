// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I{ virtual void v0(int,int)=0; };
void f(char* t,int a,int b){ if(*(int*)(t+0x10)) ((I*)(t+8))->v0(a,b); }
