// from server: 75% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct VTable
    {
        int (*call)(void *, int);
        int (*next)(void *, int);
        int (*target)(void *, int);
    };

    struct Object
    {
        char pad[0x120];
        VTable *vtable;
    };

    typedef int (__thiscall *Target)(void *, int);

    Object *object = *(Object **)((char *)this + 0x0c);
    void *target = (char *)object + 0x120;
    Target function = (Target)object->vtable->target;
    return function(target, 1);
}
