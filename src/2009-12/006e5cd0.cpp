// from server: 23% by atomic.potato
struct VTableObject
{
    int (__thiscall *method)(VTableObject *, void *);
};

struct RefPropDescriptor
{
    char pad0[0x20];
    VTableObject *object;
    unsigned char f(void *);
};

unsigned char RefPropDescriptor::f(void *a)
{
    VTableObject *o = object;
    int x = o->method(o, a);
    int y = o->method(o, *(void **)((char *)this + 0x24));
    return x == y;
}
