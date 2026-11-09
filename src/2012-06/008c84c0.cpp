// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted {
    virtual ~Counted();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long useCount;
    long weakCount;
};

struct SharedPtr {
    void* px;
    Counted* pn;
    __forceinline ~SharedPtr() {
        Counted* p = pn;
        if (p != 0) {
            if (_InterlockedDecrement(&p->useCount) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weakCount) == 0) {
                    p->destroy();
                }
            }
        }
    }
};

struct StorageOps {
    void* unused;
    void (__cdecl* destroy)(void*);
};

struct Storage {
    StorageOps* ops;
    char data[0x3c];
    void assign(const SharedPtr& value);
};

struct Variant {
    const void* type;
    Storage value;
};

const void* singleton();

struct Tuple {
    char alloc;
    Variant* first;
    Variant* last;
    Variant* end;
    Tuple(int count);
    __forceinline ~Tuple() {
        if (first != 0) {
            Variant* e = last;
            for (Variant* p = first; p != e; ++p) {
                if (p->value.ops != 0) {
                    p->value.ops->destroy(p->value.data);
                }
            }
            ::operator delete(first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
};

struct S;

struct Receiver {
    virtual void slot0();
    virtual void fire(S* sender, Tuple& args);
};

struct S {
    void f(Receiver* receiver, SharedPtr a, SharedPtr b);
};

void S::f(Receiver* receiver, SharedPtr a, SharedPtr b) {
    Tuple args(2);
    Variant* v0 = args.first;
    v0->type = singleton();
    v0->value.assign(a);
    Variant* v1 = args.first + 1;
    v1->type = singleton();
    v1->value.assign(b);
    receiver->fire(this, args);
}
