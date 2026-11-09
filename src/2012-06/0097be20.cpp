// from server: 100% by tester
extern "C" unsigned long (__stdcall *WaitForSingleObject)(void *, unsigned long);

struct S
{
    int f(unsigned long);
};

int S::f(unsigned long a)
{
    return !WaitForSingleObject(*(void **)this, a);
}
