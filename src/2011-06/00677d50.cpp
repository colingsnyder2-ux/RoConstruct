// from server: 63% by atomic.potato
struct S
{
    int f();
};

extern "C" int __fastcall Function46F050(void *);
extern "C" int __fastcall Function612070(void *);

int S::f()
{
    void *p = (char *)this + 0x90;
    if (Function46F050(p))
        return 0;
    if (Function612070(p))
        return 0;
    return 1;
}
