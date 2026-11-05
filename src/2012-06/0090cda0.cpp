// from server: 91% by atomic.potato
typedef struct
{
    long value;
} CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    char padding[24];
    int value;
};

extern "C" S *__cdecl func_0090ccc0();
extern "C" void __stdcall func_00b221b8(S *);
extern "C" void __stdcall func_00b221b4(S *);

void func_0090cda0(int *p)
{
    S *q = func_0090ccc0();
    func_00b221b8(q);
    *p = q->value;
    q->value = (int)p;
    func_00b221b4(q);
}
