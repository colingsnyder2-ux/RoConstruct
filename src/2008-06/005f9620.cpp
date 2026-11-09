// from server: 100% by king_originala
extern void (__thiscall *deallocate_call)(void *, char *, unsigned int);
extern void (__thiscall *streambuf_destructor_call)(void *);

struct Allocator {
    Allocator();
    void deallocate(char *, unsigned int);
};

__forceinline Allocator::Allocator()
{
}

__forceinline void Allocator::deallocate(char *p, unsigned int n)
{
    deallocate_call(this, p, n);
}

struct Streambuf {
    char storage[0x44];
    ~Streambuf();
};

__forceinline Streambuf::~Streambuf()
{
    streambuf_destructor_call(this);
}

struct Flag {
    unsigned char active;
    ~Flag();
};

__forceinline Flag::~Flag()
{
    if (active)
        active = 0;
}

struct S : Streambuf {
    Flag flag;
    unsigned char padding[7];
    char *buffer;
    unsigned int capacity;

    ~S();
};

S::~S()
{
    if (buffer)
        Allocator().deallocate(buffer, capacity);
}
