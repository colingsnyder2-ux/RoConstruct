// from server: 80% by atomic.potato
struct Job
{
    unsigned char pad0[8];
    unsigned char enabled;
    unsigned char pad1[3];
    struct Object
    {
        struct VTable
        {
            void* pad[24];
            unsigned char (__thiscall *check)(Object*, int);
        };
        VTable* vtable;
    };
    Object* object;
    int f(void* value);
};

int Job::f(void* value)
{
    if (enabled)
    {
        if (!object->vtable->check(object, *(int*)value))
            return 0;
    }
    return 1;
}
