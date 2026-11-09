// from server: 44% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    S *next;
    S *f(int);
};

S *CreateS();

S *S::f(int flag)
{
    S *p = this;
    if (flag & 1)
    {
        S *q = CreateS();
        EnterCriticalSection((CRITICAL_SECTION *)0x9ea374);
        p->next = q->next;
        q->next = p;
        LeaveCriticalSection((CRITICAL_SECTION *)0x9ea370);
    }
    return p;
}
