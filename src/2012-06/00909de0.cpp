// from server: 56% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    int *f();
    int *field18;
};

extern "C" S *__cdecl sub_909c50();

int *S::f()
{
    S *p = sub_909c50();
    EnterCriticalSection(p);
    int *result = p->field18;
    p->field18 = result;
    LeaveCriticalSection(p);
    return result;
}
