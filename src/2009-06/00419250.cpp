// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    bool f(S*);
    int g(S*);
};

int S::g(S* other)
{
    if (other && !other->f(this))
        return 0;
    return 1;
}