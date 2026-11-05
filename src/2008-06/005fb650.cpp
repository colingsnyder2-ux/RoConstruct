// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern const char itemName[];
extern int kernelCount;

struct Base {
    void* owner;
    int value;

    Base(void*);
    virtual ~Base();
};

inline Base::Base(void* p) : owner(p), value(0) {}

struct Small {
    char storage[0x3c];
    Small();
};

struct Large {
    char storage[0xc048];
    Large(const char*);
};

struct Storage {
    void* first;
    void* last;
    void* end;

    Storage();
    ~Storage();
};

inline Storage::Storage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct Kernel : Base {
    bool enabled;
    Small* small;
    Storage storage;
    Large* large;

    Kernel(void*);
    virtual ~Kernel();
};

Kernel::Kernel(void* p)
    : Base(p),
      enabled(false),
      small(new Small),
      storage(),
      large(new Large(itemName))
{
    ++kernelCount;
}
