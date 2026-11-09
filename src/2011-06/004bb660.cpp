// from server: 62% by atomic.potato
struct S
{
    struct VTable
    {
        int (__thiscall *compare)(void*, void*);
    };

    void* value;
    void* padding[7];

    bool f(void* first, void* second);
};

bool S::f(void* first, void* second)
{
    VTable* table = *(VTable**)value;
    int left = table->compare(value, first);
    int right = table->compare(value, second);
    return left == right;
}
