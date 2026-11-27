// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Ev { virtual void fire(float a, float b, float c, float d); };
struct H { char pad[8]; Ev* e0; int x; int n; };
void f(H* s, float a, float b, float c, float d)
{
    if (s->n) { Ev* e = (Ev*)((char*)s + 8); e->fire(a, b, c, d); }
}
