// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual void f();
};

struct Secondary {
    virtual void g();
};

struct Base : Primary, Secondary {
    char data[40];
    Base(void*, int, int);
};

struct Object : Base {
    Object(void*, int, int);
    virtual void f();
    virtual void g();
};

__forceinline Object::Object(void* owner, int value, int limit)
    : Base(owner, value, limit) {}

struct S {
    char padding[24];
    void* owner;
    Object* create();
};

Object* S::create()
{
    return new Object(owner, 0, 90);
}
