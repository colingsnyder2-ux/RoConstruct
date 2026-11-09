// from server: 100% by king_originala
void __cdecl operator delete(void*) throw();
extern "C" void __cdecl release(void*);

struct Storage
{
    void* data;
    unsigned int reserved[2];
    ~Storage();
};

inline Storage::~Storage()
{
    operator delete(data);
}

struct S
{
    virtual ~S();
    void cleanup();

    Storage storage;
    void* first;
    void* last;
    void* limit;
    void* object;
    void* control;
};

S::~S()
{
    cleanup();
    release(control);

    if (first != 0)
        operator delete(first);

    first = 0;
    last = 0;
    limit = 0;
}
