// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct W { virtual void v0(); virtual void v1(W* a); };
void f(char* a, char* b)
{
    W* w = b ? (W*)(b + 0x1c) : 0;
    w->v1((W*)(a + 0x1c));
}
