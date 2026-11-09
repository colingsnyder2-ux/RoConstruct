// from server: 69% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" CRITICAL_SECTION* __cdecl sub_472A10();
extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

struct RBX_BlockBlockContact {
    void __cdecl f(int*);

    int field18;
};

void RBX_BlockBlockContact::f(int* value) {
    CRITICAL_SECTION* lock = sub_472A10();
    EnterCriticalSection(lock);
    *value = field18;
    field18 = (int)value;
    LeaveCriticalSection(lock);
}
