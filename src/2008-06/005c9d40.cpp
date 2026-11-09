// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
void __cdecl operator delete(void*);

struct Item {
    char storage[0x178];

    Item(int);
    static void* operator new(unsigned int size)
    {
        return malloc(size);
    }
    static void operator delete(void* p)
    {
        ::operator delete(p);
    }
};

struct Tag {
    union {
        int value;
        char byte;
    };

    Tag() : value(0)
    {
        byte = 0;
    }
};

struct Result {
    Result(Item*, Tag);
};

Result makeItem(int argument)
{
    Tag tag;
    return Result(new Item(argument), tag);
}
