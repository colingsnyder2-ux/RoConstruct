// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 004b96b0  unit: RBX::Network::VIdSerializer::?$NonFactoryProduct  size: 877 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b96b0
//

#include <intrin.h>

void __cdecl operator delete(void*) throw();

struct Object {
    virtual ~Object();
};

struct Owner {
    Object* p;
    ~Owner();
};

__forceinline Owner::~Owner()
{
    if (p) delete p;
}

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* p;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* c = control;
    if (c && _InterlockedDecrement(&c->strong) == 0) {
        c->dispose();
        if (_InterlockedDecrement(&c->weak) == 0)
            c->destroy();
    }
}

struct I00 { virtual void f00(); unsigned char data[0xc]; };
struct I10 { virtual void f10(); };
struct I14 { virtual void f14(); unsigned char data[0x8]; };
struct I20 { virtual void f20(); };
struct I24 { virtual void f24(); unsigned char data[0x1c]; };
struct I44 { virtual void f44(); unsigned char data[0x1c]; };
struct I64 { virtual void f64(); unsigned char data[0x1c]; };
struct I84 { virtual void f84(); unsigned char data[0x1c]; };
struct Ia4 { virtual void fa4(); unsigned char data[0x1c]; };
struct Ic4 { virtual void fc4(); unsigned char data[0x2b74 - 0xc8]; };

struct Base : I00, I10, I14, I20, I24, I44, I64, I84, Ia4, Ic4 {
    ~Base();
};

struct Sub {
    virtual void f0();
    char data[8];
    ~Sub();
};

struct Container32 {
    char data[32];
    ~Container32();
};

struct Container44 {
    char data[44];
    ~Container44();
};

struct Container28 {
    char data[28];
    ~Container28();
};

struct Other32 {
    char data[32];
    ~Other32();
};

struct Head {
    void* p;
    ~Head();
};

__forceinline Head::~Head()
{
    void* d = p;
    operator delete(d);
}

struct Tree {
    Head head;
    char data[28];
    void clear();
    ~Tree();
};

__forceinline Tree::~Tree()
{
    clear();
}

struct Buffer {
    void* storage;
    unsigned long a;
    unsigned long b;
    void* first;
    void* last;
    void* limit;
    unsigned long c;
    ~Buffer();
};

__forceinline Buffer::~Buffer()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
    void* st = storage;
    operator delete(st);
}

struct ContainerBase {
    char data[36];
    ~ContainerBase();
};

struct LargeContainer : ContainerBase {
    void* storage;
    unsigned long a;
    unsigned long b;
    void* first;
    void* last;
    void* limit;
    char tail[8];
    ~LargeContainer();
};

__forceinline LargeContainer::~LargeContainer()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
    void* st = storage;
    operator delete(st);
}

struct Callback {
    typedef void (__thiscall *Function)(Callback*, Sub*);
    Function* table;
};

struct S : Base, Sub {
    Owner owner2b80;
    Owner owner2b84;
    Shared shared;
    Container32 container2b90;
    LargeContainer container2bb0;
    LargeContainer container2bf4;
    Other32 container2c38;
    Buffer buffer2c58;
    Container28 container2c74;
    Container32 container2c90;
    Container44 container2cb0;
    Tree tree2cdc;
    Container32 container2cfc;
    Owner owner2d1c;
    Owner owner2d20;
    Owner owner2d24;
    Owner owner2d28;
    Owner owner2d2c;
    Owner owner2d30;
    Owner owner2d34;
    Owner owner2d38;
    Owner owner2d3c;
    Owner owner2d40;
    Owner owner2d44;
    Owner owner2d48;
    unsigned long padding2d4c;
    Callback* volatile callback;
    ~S();
};

S::~S()
{
    Sub* s = this;
    Callback* c = callback;
    if (c)
        c->table[59](c, s);
}
