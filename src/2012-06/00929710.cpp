// from server: 64% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

extern "C" void * __cdecl sub_00929570();

struct MovingAssemblyStage {
    int *swapValue();
};

int *MovingAssemblyStage::swapValue() {
    MovingAssemblyStage *stage = reinterpret_cast<MovingAssemblyStage *>(sub_00929570());
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION *>(stage));
    int *value = reinterpret_cast<int *>(reinterpret_cast<char *>(stage) + 0x18);
    int *result = reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 8);
    *result = *value;
    *value = reinterpret_cast<int>(result);
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION *>(stage));
    return result;
}
