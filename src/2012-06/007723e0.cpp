// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ int p[4]; void (__thiscall *fn)(char*,float); char* obj; int adj; void f(float a); };
void S::f(float a){ fn(obj+adj,a); }
