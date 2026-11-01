// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared() {
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Shared __cdecl convert(const Shared&);

struct Node {
    char padding[0x44];
    int flag;
    char tail[0x68];

    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
    Node(Shared, Shared);
};

struct Frame;

struct FrameTable {
    void* slots[83];
    void (__thiscall* attach)(Frame*, Node*);
};

struct Frame {
    FrameTable* table;
};

struct Owner;

struct OwnerTable {
    void* slots[101];
    Frame* (__thiscall* getFrame)(Owner*);
};

struct Owner {
    OwnerTable* table;
};

struct S {
    char padding[0x4c];
    Shared context;

    void f(int, Shared);
};

void S::f(int, Shared argument) {
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x378);
    Frame* frame = owner->table->getFrame(owner);
    Shared converted = convert(argument);
    if (!converted.pointer)
        return;

    Node* node = new Node(converted, context);
    node->flag = 1;
    frame->table->attach(frame, node);
}
