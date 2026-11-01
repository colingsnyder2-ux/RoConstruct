// from server: 100% by colin
struct Vec {
    float x, y, z;
};

struct Impl {};

void __cdecl operator delete(void*);

struct Owner {
    Impl* p;
    ~Owner();
    Impl* release();
};

inline Owner::~Owner() {
    if (p)
        delete p;
}

inline Impl* Owner::release() {
    Impl* result = p;
    p = 0;
    return result;
}

extern void* __cdecl descriptor1();
extern void* __cdecl descriptor2();
extern Owner __cdecl createImpl(Vec, Vec);

struct __declspec(novtable) Primary {
    virtual void primary();
    unsigned char padding[20];
};

struct __declspec(novtable) Secondary {
    virtual void secondary();
};

struct __declspec(novtable) Base : Primary, Secondary {
    Base(int, int, int);
    void initialize(void*, void*, int, int, int);
    virtual ~Base();
};

__forceinline Base::Base(int a, int b, int c) {
    void* first = descriptor1();
    void* second = descriptor2();
    initialize(second, first, a, b, c);
}

struct S : Base {
    Impl* impl;
    S(int, int, Vec, Vec, int);
    virtual ~S();
};

S::S(int a, int b, Vec first, Vec second, int c)
    : Base(a, b, c)
{
    impl = createImpl(first, second).release();
}
