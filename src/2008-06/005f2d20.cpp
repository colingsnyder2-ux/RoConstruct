// from server: 100% by king_originala
struct S;

struct VTable
{
    void *unused[21];
    void (__thiscall *reset)(S *);
};

struct Buffer
{
    unsigned char storage[8];
    void resize(int);
};

struct S
{
    VTable *vtable;
    unsigned char padding04[0x38];
    unsigned char flag;
    unsigned char padding3D[3];
    int value;
    unsigned char active;
    unsigned char padding45[7];
    Buffer buffer;
    int putbackSize;
    volatile unsigned int flags;

    void f(const int &source, int capacity, int putback);
};

void S::f(const int &source, int capacity, int putback)
{
    if (capacity == -1)
        capacity = 4096;
    if (putback == -1)
        putback = 4;

    const int minimum = 2;
    putbackSize = *(putback > minimum ? &putback : &minimum);

    if (capacity == 0)
        capacity = 1;

    buffer.resize(putbackSize + capacity);
    vtable->reset(this);

    int incoming = source;
    if (active)
        active = 0;
    value = incoming;
    active = 1;
    flags |= 1;
    flag = 0;
}
