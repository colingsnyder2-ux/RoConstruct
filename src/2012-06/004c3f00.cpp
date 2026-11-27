// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Color;
struct Vec;
const Vec &F1();
const Color &F2();
struct AdornRbxGfx
{
    void g(int, int, const Color &, const Vec &, int);
    void f(int, int, int);
};
void AdornRbxGfx::f(int a, int b, int c)
{
    g(a, b, F2(), F1(), c);
}