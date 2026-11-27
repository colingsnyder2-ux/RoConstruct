// from server: 100% by Xemicl
// roc 2012-06 006e1d40  unit: RBX::VDataModel::?$RefPropDescriptor  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006e1d40
//

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted {
    virtual void destructor_slot();
    virtual void dispose();
    virtual void destroy();
    long use;
    long weak;
    void weakRelease() {
        if (_InterlockedDecrement(&weak) == 0) destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            weakRelease();
        }
    }
};

struct S;

struct Child {
    S* p;
    Counted* c;
};

struct Vec {
    void* alval;
    Child* first;
    Child* last;
};

struct ChildRef {
    Vec* px;
    Counted* pn;
    ~ChildRef() {
        if (pn) pn->release();
    }
};

struct Holder {
    Vec* px;
    Counted* pn;
    ChildRef read() const;
};

struct Descriptor {
    bool isA(const void* other) const;
};

const void* classDescriptor();
struct First { char a[4]; };
struct Base { char pad0[0x24]; Descriptor* desc;
template<class T> T* cast() { Descriptor* d = desc; return d->isA(classDescriptor()) ? static_cast<T*>(this) : 0; }
};
struct S : First, Base {
    char pad1[0x10];
    Holder children;
    int count();
};
int S::count() {
    int n = cast<S>() != 0 ? 1 : 0;
    if (children.px) {
        ChildRef r = children.read();
        Child* e = r.px->last;
        Child* it = r.px->first;
        for (; it != e; ++it) {
            n += it->p->count();
        }
    }
    return n;
}
