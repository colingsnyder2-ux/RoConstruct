// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 0041a250  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::V?$function::?$holder  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041a250
//

// from server: 90% by king_originala
// roc 2008-06 0041a250  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::V?$function::?$holder  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041a250
//

extern "C" void __cdecl release(void *);
int __stdcall closeHandle(void *);

struct Handle
{
    void *value;
    __forceinline ~Handle();
};

struct Storage
{
    void *data;
    unsigned char reserved[28];
    __forceinline ~Storage();
};

struct Entries : Storage
{
    void clear();
    __forceinline ~Entries();
};

struct Lock
{
    void *object;
    bool criticalSection;
    ~Lock();
};

struct S
{
    unsigned char reserved0[16];
    Handle handle;
    unsigned char reserved1[20];
    Entries entries;
    Lock lock;
    virtual ~S();
};

__forceinline Handle::~Handle()
{
    if (value)
        closeHandle(value);
}

__forceinline Storage::~Storage()
{
    void* d = data;
    release(d);
}

__forceinline Entries::~Entries()
{
    clear();
}

S::~S()
{
}

