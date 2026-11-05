// from server: 100% by atomic.potato
struct S
{
    unsigned char f();
};

extern "C" int sub_54A920(S *);
extern "C" unsigned char sub_71EFD0(S *);

unsigned char S::f()
{
    if (sub_71EFD0(this))
    {
        if (sub_54A920(this))
            return *((unsigned char *)this + 0xc74);
        return 0;
    }
    return 1;
}
