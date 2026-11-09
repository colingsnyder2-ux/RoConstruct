// from server: 81% by atomic.potato
struct VTable
{
    void (__thiscall *f)(void *, void *);
};

struct Object
{
    VTable *vtable;
};

struct SpatialFilter
{
    int unused;
    Object *value;
    void f(Object *);
};

void SpatialFilter::f(Object *stage)
{
    value->vtable->f(value, stage);
    stage->vtable->f(stage, this);
}
