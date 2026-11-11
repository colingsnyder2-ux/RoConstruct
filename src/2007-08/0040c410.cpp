// from server: 100% by EspClaude
// roc 2007-08 0040c410  unit: CBrowserView  size: 176 bytes
// target (2007-08 exe): base ctor 0x461c60; [esi+0xf4]=0; list-like member at +0xf8 (head +0xfc, size +0x100);
// count +0x104; buffer +0x108 (0x1a8); connection +0x2b0; flags +0x2b4/+0x2b5; lock +0x2b8 (dllimport ctor)
struct Base {
    virtual ~Base();
    char storage[0xF0];
    Base();
};

struct Parent : Base {
    unsigned long reserved;
    Parent();
};

inline Parent::Parent() : reserved(0)
{
}

// 2007-08: member at +0xf8 is 0xc bytes, ctor inlined: head = buynode() (0x40b550, thiscall), size = 0
struct Member {
    char alloc[4];
    void *head;
    unsigned int size;
    void *buynode();
    Member() : head(buynode()), size(0) {}
    ~Member();
};

struct Buffer {
    char storage[0x1A8];
    Buffer();
    ~Buffer();
};

struct Connection {
    void *pointer;
    Connection();
    ~Connection();
};

inline Connection::Connection() : pointer(0)
{
}

struct Lock {
    unsigned long storage;
    __declspec(dllimport) Lock() throw();
    ~Lock();
};

extern void * __cdecl getContext();
extern void __cdecl registerContext(void *);

struct S : Parent {
    Member member;
    unsigned long count;
    Buffer buffer;
    Connection connection;
    bool flag1;
    bool flag2;
    Lock lock;

    S();
    virtual ~S();
};

S::S()
    : count(0),
      flag1(false),
      flag2(false)
{
    registerContext(getContext());
}
