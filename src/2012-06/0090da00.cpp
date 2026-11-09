// from server: 91% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
};

S *CreateS();

void __cdecl f(int *p)
{
    S *q = CreateS();
    EnterCriticalSection(q);
    int *r = *(int **)((char *)q + 24);
    *p = (int)r;
    *(int **)((char *)q + 24) = p;
    LeaveCriticalSection(q);
}
