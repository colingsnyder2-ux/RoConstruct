// from server: 29% by atomic.potato
struct S
{
    void* field50;
    int f();
};

int S::f()
{
    if (field50 == 0)
        return 0;

    int count = (*(int*)((char*)field50 + 0x10) -
                 *(int*)((char*)field50 + 0x0c)) >> 3;
    return count >= 0 ? 1 : 0;
}
