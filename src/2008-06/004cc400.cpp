// from server: 100% by king_originala
extern void* __cdecl allocate(unsigned int);

struct Cleanup {
    unsigned char storage[4];
    ~Cleanup();
};

struct Range {
    unsigned char storage[0x24];
    Range(void*, void**);
};

struct S {
    unsigned int reserved;
    void* buffer;
    Cleanup cleanup;
    Range range;
    unsigned int count;

    S(void*, void*);
};

S::S(void* first, void* last)
    : buffer(allocate(0x78)),
      range(first, &first),
      count(0)
{
}
