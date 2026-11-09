// from server: 69% by atomic.potato
struct S
{
    char pad[0x84];
    void* field84;
    void* get();
};

void* S::get()
{
    struct VTable
    {
        char pad[0x18];
        void* (*func)();
    };

    VTable* table = *(VTable**)field84;
    return table->func();
}
