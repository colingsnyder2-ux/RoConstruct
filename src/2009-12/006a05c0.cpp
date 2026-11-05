// from server: 100% by atomic.potato
struct S
{
    int f();
    char padding[152];
    void* field;
};

int S::f()
{
    void* p = field;
    if (p)
        return **(int**)((char*)p - 40);
    return 0;
}
