// from server: 100% by king_originala
struct S {
    char padding[0x2e4];
    void* value;
    bool f(S* node);
};

extern S* func_00491e50(S* p);

void* func_005a3390(S* p)
{
    S* q = func_00491e50(p);
    if (q && (p == q || p->f(q)))
        return q->value;
    return 0;
}
