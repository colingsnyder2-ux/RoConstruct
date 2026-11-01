// from server: 100% by king_originala
extern void (__cdecl *invalid_parameter)();
void __cdecl operator delete(void *) throw();

struct Object {
    virtual ~Object();
};

struct Allocator {
    __forceinline void deallocate(void *, unsigned int);
};

struct Allocation {
    void *pointer;
    __forceinline ~Allocation();
};

struct Vector {
    Allocation allocation;
    unsigned int reserved[2];
    void *first;
    void *last;
    void *limit;
    __forceinline ~Vector();
};

struct Container {
    Allocation allocation;
    unsigned int reserved[5];
    void clear();
    __forceinline ~Container();
};

struct String {
    unsigned char data[32];
    ~String();
};

struct Base {
    virtual ~Base();
    unsigned char reserved[24];
    Object **first;
    Object **last;
    Object **limit;
    unsigned int tail[2];
};

struct S : Base {
    String name;
    String description;
    Vector entries;
    Container container;
    Vector values;
    Vector defaults;
    Vector attributes;
    virtual ~S();
};

__forceinline void Allocator::deallocate(void *p, unsigned int)
{
    operator delete(p);
}

__forceinline Allocation::~Allocation()
{
    Allocator allocator;
    allocator.deallocate(pointer, 1);
}

__forceinline Vector::~Vector()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
}

__forceinline Container::~Container()
{
    clear();
}

S::~S()
{
    Object **finish = last;
    void (__cdecl *check)() = invalid_parameter;
    if (first > finish)
        check();

    Object **current = first;
    if (current > last)
        check();

    while (current != finish) {
        if (*current)
            delete *current;
        ++current;
    }
}
