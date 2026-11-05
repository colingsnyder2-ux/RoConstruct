// from server: 100% by why2
struct S {
    char pad[0x4c];
    void* ptr;
    int get() const;
};

int S::get() const
{
    void* p = ptr;
    if (p != 0)
    {
        char* c = (char*)p;
        return (int)((*(int*)(c + 0x10) - *(int*)(c + 0xc)) >> 3);
    }
    return 0;
}
