// from server: 80% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VInstance {
    char pad0[0x10];
    void** array;
    int capacity;
    int index;
    int count;
    void release();
};

void VInstance::release() {
    if (count != 0) {
        void* p = array[index];
        void* obj = *(void**)((char*)p + 4);
        if (obj != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1) {
                ((void(__thiscall*)(void*))(*(void***)obj)[1])(obj);
                if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1) {
                    ((void(__thiscall*)(void*))(*(void***)obj)[2])(obj);
                }
            }
        }
        index++;
        if (capacity <= index) {
            index = 0;
        }
        count--;
        if (count == 0) {
            index = 0;
        }
    }
}
