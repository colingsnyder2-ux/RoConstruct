// from server: 52% by atomic.potato
struct S {
    virtual void *f();
};

void *S::f()
{
    void *p = f();
    if (p)
        return ((S *)p)->f();
    return 0;
}
