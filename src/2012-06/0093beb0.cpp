// from server: 31% by atomic.potato
extern "C" void __cdecl sub_892f90(void *, void *);

struct Point
{
    int pad0[3];
    void *field0c;
    int pad10[3];
    int field1c;
    int pad20[2];
    int field28;
    int pad2c;
    int field30;
    int pad34;
    int field38;

    void f();
};

void Point::f()
{
    void *p = field0c;
    void *q = *(void **)((char *)p + 0x30);
    if (*(void **)((char *)q + 0x38))
        sub_892f90((char *)this + 0x28, (char *)this + 0x1c);
}
