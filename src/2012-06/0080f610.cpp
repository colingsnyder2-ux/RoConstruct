// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc;
extern Desc descA;
extern Desc descB;
struct S
{
    void init();
    void add(Desc *);
    void f();
};
void S::f()
{
    init();
    add(&descA);
    add(&descB);
}