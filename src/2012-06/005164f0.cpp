// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E { int v; void init(int a); };
void fill(E* first, E* last, int a)
{
    for (; first != last; ++first) first->init(a);
}
