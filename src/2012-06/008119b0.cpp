// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Params { float a[3]; float b[3]; float c; float d; };
struct Owner { void g(Params *, float *, float, float); };
struct Inner
{
    void f(Params *p);
};
void Inner::f(Params *p)
{
    Owner *o = ((Owner **)this)[-1];
    o->g(p, p->b, p->c, p->d);
}