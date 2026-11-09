// from server: 100% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);
extern "C" void * __cdecl sub_4509A0();

struct NormalBreakConnector
{
    NormalBreakConnector *next;
    NormalBreakConnector *filler[5];

    NormalBreakConnector *f(unsigned int);
};

void (__stdcall *g_leave)(CRITICAL_SECTION *) = LeaveCriticalSection;
void (__stdcall *g_enter)(CRITICAL_SECTION *) = EnterCriticalSection;

NormalBreakConnector *NormalBreakConnector::f(unsigned int flags)
{
    NormalBreakConnector *p = this;

    if (flags & 1)
    {
        NormalBreakConnector *q = (NormalBreakConnector *)sub_4509A0();
        g_enter((CRITICAL_SECTION *)q);
        p->next = q->filler[5];
        q->filler[5] = p;
        g_leave((CRITICAL_SECTION *)q);
    }

    return p;
}
