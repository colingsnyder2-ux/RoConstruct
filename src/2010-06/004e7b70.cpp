// from server: 57% by atomic.potato
struct S
{
    int f(void*, void*);
};

int S::f(void*, void* b)
{
    struct V
    {
        int (**call)(void*, void*);
    };

    V* v = *(V**)((char*)this + 0x1c);
    return v->call[3](v, b);
}
