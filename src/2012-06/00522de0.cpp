// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct CountedBase {
    virtual void slot0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void add_ref()
    {
        _InterlockedIncrement(&use_count);
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count) == 0)
                destroy();
        }
    }
};

struct SharedCount {
    CountedBase* pi;
    SharedCount(const SharedCount& r) : pi(r.pi)
    {
        if (pi)
            pi->add_ref();
    }
    ~SharedCount()
    {
        if (pi)
            pi->release();
    }
};

template <typename T>
struct SharedPtr {
    T* px;
    SharedCount pn;
};

struct Target;
struct Element;

struct ElementIter {
    Element* ptr;
    ElementIter(Element* p) : ptr(p) {}
};

struct ElementList {
    int alloc;
    Element* first;
    Element* last;
    ElementIter begin() { return ElementIter(first); }
    ElementIter end() { return ElementIter(last); }
};

struct Arg1 {
};

typedef void (__cdecl *Callback)(SharedPtr<Target>, Element&);

template <typename T>
struct Value {
    T t;
};

struct Storage {
    Value<SharedPtr<Target> > a1;
};

struct BindList : Storage {
};

struct Bound {
    Callback fn;
    BindList list;
};

extern Arg1 g_arg1;

void __cdecl callback(SharedPtr<Target>, Element&);
Bound __cdecl bindCallback(Callback, SharedPtr<Target>, Arg1);
Bound __cdecl forEachElement(ElementIter, ElementIter, Bound);

void __cdecl onEvent(SharedPtr<Target> target, int kind, SharedPtr<ElementList> list)
{
    if (kind == 1) {
        forEachElement(list.px->begin(), list.px->end(), bindCallback(callback, target, g_arg1));
    }
}
