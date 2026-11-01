// from server: 100% by king_originala
struct Base {
    virtual ~Base();
    char storage[0xF8];
};

struct Member {
    char storage[0x20];
    ~Member();
};

struct Buffer {
    char storage[0x1A8];
    void cleanup();
};

struct Interface {
    virtual long __stdcall QueryInterface(void *, void **) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

extern void (__thiscall *destroyLock)(void *);

struct S : Base {
    Member member;
    Buffer buffer;
    Interface *connection;
    unsigned long reserved;
    char lock[4];

    virtual ~S();
};

S::~S()
{
    destroyLock(lock);
    if (connection)
        connection->Release();
    buffer.cleanup();
}
