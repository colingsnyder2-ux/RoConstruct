// from server: 91% by atomic.potato
typedef long LONG;
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" LONG __stdcall InterlockedDecrement(LONG*);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

struct P_0044f420
{
    char pad[24];
};

extern "C" P_0044f420* __cdecl func_0044f420();
extern "C" void __cdecl func_0098b204(P_0044f420*);
extern "C" void __cdecl func_0098b200(P_0044f420*);
extern "C" void __cdecl func_0098b208(void*);

struct S_007807d0
{
    void __cdecl f(void**);
};

void S_007807d0::f(void** p)
{
    P_0044f420* q = func_0044f420();
    func_0098b204(q);
    *p = *(void**)((char*)q + 24);
    *(void**)((char*)q + 24) = p;
    func_0098b200(q);
    func_0098b208((void*)0x00b9882c);
}
