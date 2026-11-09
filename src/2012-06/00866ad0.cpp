// from server: 40% by Intel
struct PriorityThreadPoolData {
    PriorityThreadPoolData(int a2, int a3, int a4);
};

void* __cdecl operator new(unsigned int);
void __cdecl sub_865770(void* thisptr);
void __cdecl sub_866920(void* thisptr, int a2, int a3, int a4);

PriorityThreadPoolData::PriorityThreadPoolData(int a2, int a3, int a4) {
    void* allocated = operator new(0x58);
    void* constructed = 0;
    if (allocated) {
        constructed = allocated;
        sub_865770(constructed);
    }
    sub_866920(this, a2, a3, a4);
    *reinterpret_cast<int*>(this) = 0xBD4E84;
}
