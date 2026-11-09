// from server: 100% by king_originala
struct S {
    char padding[0x104];
    S* parent;
    bool f(S* node);
};

bool S::f(S* node)
{
    S* p = parent;
    while (node != p) {
        if (!p)
            return false;
        p = p->parent;
    }
    return true;
}
