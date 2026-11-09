// from server: 77% by atomic.potato
extern "C" int __fastcall sub_0080A440(void *, void *);
extern "C" void __fastcall sub_00684840(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    if (!sub_0080A440(this, arg))
        sub_00684840(this, arg);
}
