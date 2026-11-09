// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_533290(void*, void*, void*, void*);
extern "C" void __cdecl sub_78FC20(void*, int, int, void*, void*);

struct VKeyframeSequenceProvider {
    char pad0[0x30];
    int field30;
    int field34;
    char pad38[4];
    void BoundFuncDesc(int* a, int* b);
};

void VKeyframeSequenceProvider::BoundFuncDesc(int* a, int* b) {
    int local[2];
    sub_533290(local, a, &this->pad38[0], 0);
    int* p = (int*)local[0];
    int* q = 0;
    if (p) q = (int*)((char*)p - 0x1c);
    sub_78FC20(q, this->field30, this->field34, b + 1, local);
    int* r = (int*)local[0];
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            (*(void(__thiscall**)(int*))(*((int*)r) + 4))(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                (*(void(__thiscall**)(int*))(*((int*)r) + 8))(r);
            }
        }
    }
}
