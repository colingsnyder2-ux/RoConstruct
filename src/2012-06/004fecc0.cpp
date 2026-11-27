// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Elem { int v[8]; };
struct Vec
{
    int al;
    Elem* first;
    Elem* last;
    Elem* end;
    unsigned size() const { return last - first; }
    void resize(unsigned n);
};
struct S
{
    char pad[0x44];
    Vec vec;
    unsigned f(int);
};
unsigned S::f(int x)
{
    vec.resize(vec.size() + x);
    return vec.size();
}
