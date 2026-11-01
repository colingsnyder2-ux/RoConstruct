// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*) throw();

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* volatile control;
    ~Shared();
};

struct Object {
    virtual ~Object();
};

struct OwnedObject {
    Object* volatile object;
    ~OwnedObject();
};

struct Node {
    ~Node();
};

struct OwnedNode {
    volatile unsigned long table;
    Node* object;
    ~OwnedNode();
};

struct Resource {
    volatile unsigned long table;
    void* volatile allocation;
    unsigned long reserved[2];
    void* buffer;
    unsigned long size;
    unsigned long capacity;
    unsigned long padding;
    ~Resource() throw();
};

struct Member {
    unsigned char storage[28];
    ~Member();
};

struct Base {
    volatile unsigned long table0;
    unsigned char padding04[12];
    volatile unsigned long table10;
    volatile unsigned long table14;
    unsigned char padding18[8];
    volatile unsigned long table20;
    volatile unsigned long table24;
    unsigned char padding28[28];
    volatile unsigned long table44;
    unsigned char padding48[28];
    volatile unsigned long table64;
    unsigned char padding68[28];
    volatile unsigned long table84;
    unsigned char padding88[28];
    volatile unsigned long tableA4;
    unsigned char paddingA8[28];
    volatile unsigned long tableC4;
    unsigned char paddingC8[104];
    ~Base();
};

#define SLOT(n) virtual void slot##n();
struct Callback {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34)
    SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44)
    SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54)
    SLOT(55) SLOT(56) SLOT(57) SLOT(58)
    virtual void notify(Object*);
};
#undef SLOT

struct S : Base {
    Resource resource130;
    Resource resource150;
    OwnedNode node170;
    Member member178;
    OwnedObject object194;
    Shared shared198;
    Shared shared1A0;
    Callback* volatile callback1A8;
    ~S();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline OwnedObject::~OwnedObject()
{
    Object* p = object;
    if (p)
        delete p;
}

__forceinline OwnedNode::~OwnedNode()
{
    if (object)
        delete object;
}

__forceinline Resource::~Resource() throw()
{
    if (buffer)
        operator delete(buffer);
    void* p = allocation;
    buffer = 0;
    size = 0;
    capacity = 0;
    operator delete(p);
}

S::~S()
{
    table0 = 0x8227bc;
    table10 = 0x8227b0;
    table14 = 0x8227a8;
    table20 = 0x8227a0;
    table24 = 0x822790;
    table44 = 0x822780;
    table64 = 0x822770;
    table84 = 0x822760;
    tableA4 = 0x822750;
    tableC4 = 0x822740;
    resource130.table = 0x822730;
    resource150.table = 0x822720;
    node170.table = 0x822714;

    Callback* p = callback1A8;
    if (p) {
        Object* argument = object194.object;
        p->notify(argument);
    }
    callback1A8 = 0;
}
