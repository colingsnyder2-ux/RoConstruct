// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct A
    {
        char pad[0xd0];
        void* p;
    };

    struct B
    {
        char pad[0x24];
        void* p;
    };

    struct C
    {
        char pad[0x98];
        int value;
    };

    return ((C*)((B*)((A*)this)->p)->p)->value;
}
