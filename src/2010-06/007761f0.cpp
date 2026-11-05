// from server: 37% by atomic.potato
typedef struct _CRITICAL_SECTION
{
    long reserved[6];
} CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    S *f(int);
    S *next;
};

S *S::f(int value)
{
    S *p;
    if (value & 1)
    {
        p = (S *)0x775ef0;
        EnterCriticalSection((CRITICAL_SECTION *)0x9ea374);
        next = p->next;
        p->next = this;
        LeaveCriticalSection((CRITICAL_SECTION *)0x9ea370);
    }
    return this;
}
