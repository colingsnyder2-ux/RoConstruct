// from server: 89% by atomic.potato
struct CriticalSection
{
    long data[6];
};

extern "C" void __stdcall EnterCriticalSection(CriticalSection*);
extern "C" void __stdcall LeaveCriticalSection(CriticalSection*);

struct S
{
    CriticalSection* getCriticalSection();
    int f(int*);
};

int S::f(int* value)
{
    CriticalSection* cs = getCriticalSection();
    EnterCriticalSection(cs);
    *value = *reinterpret_cast<int*>(reinterpret_cast<char*>(cs) + 24);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(cs) + 24) = reinterpret_cast<int>(value);
    LeaveCriticalSection(cs);
    return 0;
}
