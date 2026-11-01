// from server: 100% by king_originala
extern void* (__cdecl *allocate)(unsigned int);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(unsigned int size)
{
    return allocate(size);
}

struct Empty
{
    unsigned int value;
};

struct Item
{
    unsigned char storage[0x178];
    Item(const char* name);
};

struct Result
{
    Item* object;
    void* control;

    Result(Item* p, Empty tag);
};

Result f(const char* name)
{
    Empty tag = {0};
    *(volatile unsigned char*)&tag = 0;
    return Result(new Item(name), tag);
}
