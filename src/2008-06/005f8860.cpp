// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern void* ios_base_vtable;
extern void* basic_ios_vtable;

struct __declspec(novtable) IosBase {
    IosBase();
    virtual ~IosBase();
};

struct __declspec(novtable) BasicIos : IosBase {
    BasicIos();
    virtual ~BasicIos();
};

inline IosBase::IosBase()
{
    *(void* volatile*)this = ios_base_vtable;
}

inline BasicIos::BasicIos()
{
    *(void* volatile*)this = basic_ios_vtable;
}

struct Ostream : virtual BasicIos {
    __declspec(dllimport) Ostream(void*, bool);
    virtual ~Ostream();
};

struct StreamBuffer {
    void* volatile state;
    unsigned int reserved;
    StreamBuffer();
    ~StreamBuffer();
};

struct BufferHolder {
    void* volatile buffer;
    BufferHolder();
};

inline BufferHolder::BufferHolder() : buffer(0)
{
}

struct StreamBase : BufferHolder {
    StreamBase();
    virtual ~StreamBase();
};

inline StreamBase::StreamBase()
{
}

struct S : StreamBase, Ostream {
    StreamBuffer storage;
    S();
    virtual ~S();
};

S::S() : Ostream(0, false)
{
    buffer = &storage;
    *(S**)((char*)storage.state + 28) = this;
}
