// from server: 100% by king_originala
extern "C" void __cdecl release(void *);
extern "C" void __cdecl deallocate(void *) throw();

struct Storage {
    void *allocation;
    unsigned int reserved[2];
    void *begin;
    void *end;
    void *capacity;
    unsigned int reserved2;
    void *object;

    ~Storage() throw();
};

struct S {
    Storage storage;

    virtual ~S();
    void detach();
};

inline Storage::~Storage() throw()
{
    if (begin)
        deallocate(begin);

    begin = 0;
    end = 0;
    capacity = 0;
    deallocate(allocation);
}

S::~S()
{
    detach();
    release(storage.object);
}
