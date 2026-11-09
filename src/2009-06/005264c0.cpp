// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
struct SharedCount {
    sp_counted_base* pi_;
    ~SharedCount() { if (pi_ != 0) pi_->release(); }
};
struct Shared { void* px; SharedCount pn; };
class connection {
public:
    void disconnect() const;
    ~connection();
    int a; void* b;
};
class scoped_connection : public connection {
public:
    ~scoped_connection() { disconnect(); }
};
void __cdecl operator delete(void*);
extern unsigned long thirdTable[];

struct First {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual ~First();
};

struct Second {
    virtual ~Second();
};

struct Third {
    unsigned long* vtable;
    void cleanup();
};

struct Fourth {
    ~Fourth();
};

struct Counter {
    virtual ~Counter();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct FirstOwner {
    First* pointer;
    ~FirstOwner();
};

struct SecondOwner {
    Second* pointer;
    ~SecondOwner();
};

struct ThirdOwner {
    Third* pointer;
    ~ThirdOwner();
};

struct FourthOwner {
    Fourth* pointer;
    ~FourthOwner();
};

struct Container {
    unsigned char storage[20];
    ~Container();
};

struct S {
    virtual ~S();
    FirstOwner first;
    SecondOwner second;
    ThirdOwner third;
    FourthOwner fourth;
    Shared shared;
    scoped_connection c1;
    scoped_connection c2;
};

__forceinline FirstOwner::~FirstOwner() {
    delete pointer;
}

__forceinline SecondOwner::~SecondOwner() {
    delete pointer;
}

__forceinline ThirdOwner::~ThirdOwner() {
    Third* p = pointer;
    if (p) {
        p->vtable = thirdTable;
        p->cleanup();
        operator delete(p);
    }
}

__forceinline FourthOwner::~FourthOwner() {
    delete pointer;
}

S::~S() {
}

