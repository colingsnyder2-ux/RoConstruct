// from server: 48% by atomic.potato
extern "C" int __stdcall CloseHandle(void *);

struct S
{
    int f();
    long member_70;
};

int S::f()
{
    long value = member_70;
    member_70 = 0;
    if (value)
        CloseHandle((void *)value);
    return 0;
}
