// from server: 100% by king_originala
extern void (__cdecl *free_memory)(void *);
extern unsigned char object_table[];

struct Buffer
{
    void *first;
    void *second;
    unsigned int count;

    void clear();
};

struct S
{
    void *table;
    Buffer buffer;

    void destroy();
};

void S::destroy()
{
    Buffer *b = &buffer;
    table = object_table;
    b->clear();
    b->clear();

    void (__cdecl *release)(void *) = free_memory;

    if (b->first)
    {
        release(b->first);
        b->first = 0;
    }

    if (b->second)
    {
        release(b->second);
        b->second = 0;
    }

    b->count = 0;
}
