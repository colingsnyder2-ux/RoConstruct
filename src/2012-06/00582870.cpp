// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern const double kZero;
void __stdcall G(void *, void *, double);
struct S
{
    void *f(void *, void *);
};
void *S::f(void *a, void *b)
{
    G(a, b, kZero);
    return a;
}