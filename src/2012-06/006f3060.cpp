// from server: 75% by atomic.potato
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

    V* p = *(V**)((char*)this + 12);
    V* q = *(V**)((char*)p + 0x150);
    int r = q->vtable[1]();
    return *(int*)((char*)r + 0x148) == 0;
}
