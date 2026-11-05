// from server: 73% by atomic.potato
struct S
{
    int f(void*);
};

int S::f(void* value)
{
    int count = *(int*)((char*)this + 0x50);
    if (count <= 0)
        return -1;

    int* current = *(int**)((char*)this + 0x54);
    for (int i = 0; i < count; ++i, ++current)
    {
        int* entry = (int*)*current;
        if (entry)
            entry = (int*)((char*)entry + 0x54);
        if (entry == value)
            return i;
    }
    return -1;
}
