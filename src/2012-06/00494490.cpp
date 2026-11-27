// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ int a,b,c; void (__thiscall*fn)(void*,int,int,int); void* o; int x,y,z; void m(int); };
void S::m(int){ fn(o,x,y,z); }

