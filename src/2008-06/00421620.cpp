// from server: 100% by king_originala
extern void __cdecl release_00432bd0(void*);
extern void __cdecl deallocate_006a067a(void*) throw();

struct Allocation
{
    void* pointer;
    ~Allocation() throw();
};

struct EventData
{
    virtual ~EventData();
    void cleanup();

    Allocation allocation;
    unsigned int reserved08;
    unsigned int reserved0C;
    void* first;
    void* last;
    void* limit;
    unsigned int reserved1C;
    void* reference;
};

inline Allocation::~Allocation() throw()
{
    deallocate_006a067a(pointer);
}

EventData::~EventData()
{
    cleanup();
    release_00432bd0(reference);
    if (first)
        deallocate_006a067a(first);
    first = 0;
    last = 0;
    limit = 0;
}
