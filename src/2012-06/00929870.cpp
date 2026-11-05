// from server: 47% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct MovingAssemblyStage {
    int getValue();
};

int MovingAssemblyStage::getValue() {
    int* value = reinterpret_cast<int*>(0);
    int* esi = reinterpret_cast<int*>(reinterpret_cast<char*>(this) - 0x40);
    EnterCriticalSection(esi);
    *value = esi[6];
    esi[6] = reinterpret_cast<int>(value);
    LeaveCriticalSection(esi);
    return 0;
}
