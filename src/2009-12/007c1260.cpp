// from server: 31% by atomic.potato
struct Point
{
    void f();
};

extern "C" void __cdecl sub_77e890(int *, int *);

void Point::f()
{
    int *p = *(int **)((char *)this + 0x0c);
    p = *(int **)((char *)p + 0x2c);
    if (*(int **)((char *)p + 0x34))
        sub_77e890((int *)((char *)this + 0x28), (int *)((char *)this + 0x1c));
}
