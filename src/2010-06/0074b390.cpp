// from server: 100% by tester
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
    if (vtable->get(this, 0)[0x3c])
    {
        if (vtable->get(this, 1)[0x3c])
            return 1;
    }
    return 0;
}
