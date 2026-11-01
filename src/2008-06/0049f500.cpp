// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
void __cdecl operator delete(void*);

struct Client
{
    char storage[0x2d68];

    Client(void*, void*, void*);

    static void* operator new(unsigned int size)
    {
        return malloc(size);
    }

    static void operator delete(void* p)
    {
        ::operator delete(p);
    }
};

struct Shared
{
    Client* pointer;
    void* count;

    Shared(Client*, int);
};

Shared __cdecl createClient(void* a, void* b, void* c)
{
    int tag = 0;
    *reinterpret_cast<volatile char*>(&tag) = 0;
    return Shared(new Client(a, b, c), tag);
}
