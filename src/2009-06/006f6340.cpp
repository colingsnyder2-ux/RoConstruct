// from server: 100% by colin
namespace ns_ROCX000002 {
// from server: 100% by atomic.potato
int fn_ROCX000002(void *p);

struct SpatialFilter {
    virtual void *getFilter(int index);
    virtual void *getFilter2(int index);
    virtual void *getFilter3(int index);
    virtual void *getFilter4(int index);
    virtual void *getFilter5(int index);
};

int fn_ROCX000002(void *a, void *b, int c, int d, int e, int f);

int fn_ROCX000002(SpatialFilter *self, int a, int b, int c)
{
    void *p0 = self->getFilter5(0);
    void *p1 = self->getFilter5(1);

    int n0;
    if (!p0)
        n0 = 0;
    else if (!*(void **)((char *)p0 + 4))
        n0 = 1;
    else
        n0 = fn_ROCX000002(*(void **)((char *)p0 + 4)) + 1;

    int n1;
    if (!p1)
        n1 = 0;
    else if (!*(void **)((char *)p1 + 4))
        n1 = 1;
    else
        n1 = fn_ROCX000002(*(void **)((char *)p1 + 4)) + 1;

    return fn_ROCX000002(p0, p1, n0, n1, a, b);
}
}
