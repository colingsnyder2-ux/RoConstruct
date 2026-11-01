// from server: 100% by king_originala
extern "C" void __cdecl deallocate(void*);

struct S
{
    unsigned char padding[0x110];
    void* first;
    unsigned char gap[8];
    void* buffer;
    unsigned int size;
    unsigned int capacity;

    void cleanup();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    if (buffer)
        deallocate(buffer);

    buffer = 0;
    size = 0;
    capacity = 0;
    deallocate(first);

    cleanup();

    if (flags & 1)
        deallocate(this);

    return this;
}
