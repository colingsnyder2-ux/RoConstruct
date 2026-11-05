// from server: 70% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct VTable
    {
        int (**table)();
    };

    struct Object
    {
        VTable *vtable;
    };

    struct Holder
    {
        Object *object;
    };

    Holder *holder = *(Holder **)((char *)this + 12);
    Object *object = *(Object **)((char *)holder + 288);
    int result = object->vtable->table[1]();
    return *(int *)((char *)result + 324) == 3;
}
