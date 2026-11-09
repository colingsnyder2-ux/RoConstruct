// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_4026a0(void*, void*);

struct HitTestFilter {
    void* vptr;
    int field_4;
    void* field_8;
    void* field_C;
    void init(int, void*);
};

void HitTestFilter::init(int a, void* b) {
    void* local;
    field_4 = a;
    sub_4026a0(&field_8, &local);
    if (local) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local + 4), -1) == 1) {
            void** vtbl = *(void***)local;
            ((void(__thiscall*)(void*))vtbl[1])(local);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local + 8), -1) == 1) {
                ((void(__thiscall*)(void*))vtbl[2])(local);
            }
        }
    }
}
