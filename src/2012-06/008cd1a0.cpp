// from server: 95% by atomic.potato
typedef unsigned char BYTE;

struct VTable
{
    void (__thiscall *f)(void *, void *, BYTE *);
};

struct Global
{
    VTable *vtable;
};

extern Global *g_global;

struct BodyMover
{
    void f();
};

void BodyMover::f()
{
    BYTE value = 0;
    void *object = 0;

    if (this != 0)
        object = (char *)this + 0x1c;

    g_global->vtable->f(g_global, object, &value);
}
