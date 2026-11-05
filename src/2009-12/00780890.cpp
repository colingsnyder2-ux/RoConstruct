// from server: 91% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" long __stdcall InterlockedDecrement(long*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct P_00780890
{
    long m_ref;
    char pad[20];
    long m_value;
};

extern "C" P_00780890* __cdecl f_0044f480();
extern "C" void __cdecl f_0098b204(P_00780890*);
extern "C" void __cdecl f_0098b200(P_00780890*);
extern "C" void __cdecl f_0098b208(const void*);

struct S_00780890
{
    void __cdecl f(long*);
};

void S_00780890::f(long* p)
{
    P_00780890* x = f_0044f480();
    f_0098b204(x);
    *p = x->m_value;
    x->m_value = (long)p;
    f_0098b200(x);
    f_0098b208((const void*)0xb98830);
}
