// from server: 52% by atomic.potato
extern "C" int __stdcall CloseHandle(void *);

struct S
{
    int value;
    void f();
};

void S::f()
{
    void *p = (void *)value;
    value = 0;
    if (p)
        CloseHandle(p);
}
