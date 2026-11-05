// from server: 74% by atomic.potato
extern "C" void sub_005728D0(void *);
extern "C" int sub_0071F070(void *);
extern "C" void sub_00720C40(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    sub_005728D0((char *)this + 0x1d0);
    int value = sub_0071F070(this);
    sub_00720C40((char *)this + 0x1c8, (void *)value);
    return 0;
}
