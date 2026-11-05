// from server: 100% by atomic.potato
struct S
{
    float f();
};

float S::f()
{
    struct T
    {
        char pad[160];
        float value;
    };

    T* p = *(T**)((char*)this + 0xb4);
    return p->value;
}
