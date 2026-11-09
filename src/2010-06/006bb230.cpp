// from server: 55% by atomic.potato
extern "C" int CallProperty(void *, void *);

extern "C" int __cdecl Function0060F9A0(int, int);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    void *p = *(void **)((char *)this + 0x1c);
    int v = CallProperty(*(void **)p, p);
    return Function0060F9A0(b, v);
}
