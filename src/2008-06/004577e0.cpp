// from server: 100% by king_originala
extern "C" void __cdecl release(void*);
extern "C" void __cdecl deallocate(void*);

struct Storage
{
    void* first;
    unsigned int reserved[2];
    void* begin;
    void* end;
    void* limit;
    unsigned int extra;
    void* last;

    ~Storage();
};

inline Storage::~Storage()
{
    release(last);
    if (begin)
        deallocate(begin);
    begin = 0;
    end = 0;
    limit = 0;
    deallocate(first);
}

struct S : Storage
{
    virtual ~S();
    void cleanup();
};

S::~S()
{
    cleanup();
}
