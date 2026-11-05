// from server: 61% by atomic.potato
struct S
{
    int pad0[6];
    int field18;
    int pad1;
    int field20;
    int field24;
    int field28;
    int field2c;

    int field();
};

extern "C" void f574720(void *);
extern "C" int f982114(int);
extern "C" int f590f30(void *);

int S::field()
{
    f574720((char *)this + 0x2c);
    f982114(*(int *)((char *)this + 0x2c));
    return f590f30((void *)((char *)this + 0x18));
}
