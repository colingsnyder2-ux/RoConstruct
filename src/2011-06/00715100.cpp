// from server: 64% by atomic.potato
struct S
{
    char padding[0x2f4];
    void *field;
    bool f();
};

bool S::f()
{
    if (field != 0)
        return *(void **)((char *)field + 4) != 0;
    return false;
}
