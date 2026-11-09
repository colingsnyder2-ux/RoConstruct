// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void helper_0072ca80();

struct FileMeshDataV2 {
    void construct(int a, int b, int c, void* d);
};

void FileMeshDataV2::construct(int a, int b, int c, void* d) {
    *(int*)this = 0;
    int local[3];
    local[0] = a;
    local[1] = b;
    local[2] = c;
    if (d) {
        _InterlockedExchangeAdd((volatile long*)((char*)d + 8), 1);
    }
    helper_0072ca80();
    if (d) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)d + 8), -1) == 1) {
            (*(void(**)(void*))d)(d);
        }
    }
}
