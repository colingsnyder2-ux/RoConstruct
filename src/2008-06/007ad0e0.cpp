// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long*);

struct Object {
    virtual ~Object();
    volatile long references;
    void dispose();
};

struct Pointer {
    Object* value;
    ~Pointer();
    Pointer& assign(Object*);
};

__forceinline Pointer::~Pointer()
{
    if (value && InterlockedDecrement(&value->references) == 0) {
        value->dispose();
        delete value;
    }
}

struct S {
    unsigned char padding[12];
    Pointer member;
    void f(Pointer p);
};

void S::f(Pointer p)
{
    Pointer& destination = member;
    destination.assign(p.value);
}
