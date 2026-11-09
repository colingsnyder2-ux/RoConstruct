// from server: 100% by atomic.potato
struct S_func_0079b210
{
    struct VTable
    {
        void* pad[4];
        char* (__thiscall *get)(S_func_0079b210*, int);
    };

    VTable* vtable;
    int f();
};

int S_func_0079b210::f()
{
    if (vtable->get(this, 0)[0x40])
    {
        if (vtable->get(this, 1)[0x40])
            return 1;
    }
    return 0;
}
