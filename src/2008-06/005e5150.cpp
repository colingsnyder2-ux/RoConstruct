// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    volatile unsigned long table;
    void *buffer;
    unsigned long reserved[2];
    void * volatile begin;
    void *end;
    void *capacity;

    void destroy();
};

void S::destroy()
{
    table = 0x0083F72C;
    void *p = begin;
    if (p)
        release(p);
    begin = 0;
    end = 0;
    capacity = 0;
    release(buffer);
}
