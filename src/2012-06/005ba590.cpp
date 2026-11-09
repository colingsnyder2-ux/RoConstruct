// from server: 61% by atomic.potato
struct S
{
    virtual ~S();
    int f();
};

struct T
{
    unsigned short a;
    unsigned short b;
    int c;
    int f(T* other);
};

extern "C" int Check(void*, void*);
extern "C" int Compare(T*, T*);

int S::f()
{
    if (Check(this, (void*)0xd915f8))
        if (Compare((T*)((char*)this + 0x10), (T*)0xe2694c))
            return 1;
    return 0;
}
