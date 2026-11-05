// from server: 43% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct V
    {
        int (**vtable)();
    };

    V* object = 0;
    int value = 0;
    int result = object->vtable[0]();
    value = result;
    return 1;
}
