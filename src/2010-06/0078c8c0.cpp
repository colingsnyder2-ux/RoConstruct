// from server: 100% by atomic.potato
int func_009639a0(void *p);

struct SpatialFilter {
    virtual void *getFilter(int index);
    virtual void *getFilter2(int index);
    virtual void *getFilter3(int index);
    virtual void *getFilter4(int index);
    virtual void *getFilter5(int index);
};

int func_0078c7d0(void *a, void *b, int c, int d, int e, int f);

int func_0078c8c0(SpatialFilter *self, int a, int b, int c)
{
    void *p0 = self->getFilter5(0);
    void *p1 = self->getFilter5(1);

    int n0;
    if (!p0)
        n0 = 0;
    else if (!*(void **)((char *)p0 + 4))
        n0 = 1;
    else
        n0 = func_009639a0(*(void **)((char *)p0 + 4)) + 1;

    int n1;
    if (!p1)
        n1 = 0;
    else if (!*(void **)((char *)p1 + 4))
        n1 = 1;
    else
        n1 = func_009639a0(*(void **)((char *)p1 + 4)) + 1;

    return func_0078c7d0(p0, p1, n0, n1, a, b);
}
