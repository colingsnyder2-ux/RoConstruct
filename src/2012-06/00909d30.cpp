// from server: 76% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    int value;

    void f();
};

extern "C" S *__cdecl create_value();

void S::f()
{
    S *p = create_value();
    EnterCriticalSection((CRITICAL_SECTION *)p);
    int *out = (int *)((char *)p + 8);
    int old = *out;
    *out = 0;
    LeaveCriticalSection((CRITICAL_SECTION *)p);
    (void)old;
}
