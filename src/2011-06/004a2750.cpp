// from server: 70% by atomic.potato
typedef struct _CRITICAL_SECTION {
    int data[6];
} CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S_func_004a2750 {
    char pad0[80];
    int m_value;
    char pad1[4];
    CRITICAL_SECTION m_lock;
    int f();
};

int S_func_004a2750::f()
{
    EnterCriticalSection(&m_lock);
    LeaveCriticalSection(&m_lock);
    return m_value;
}
