// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern double get(void*,int); extern void push(void*,double); extern double g;
int func(void* s){double x=get(s,1); x*=g; push(s,x); return 1;}
