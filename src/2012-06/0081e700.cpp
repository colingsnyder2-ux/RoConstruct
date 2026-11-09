// from server: 29% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SharedPtrControlBlock {
    long refCount;
    long weakCount;
    void* vptr;
    void (*deleter)(void*);
    void* managedObject;
};

struct SharedPtr {
    void* managedObject;
    SharedPtrControlBlock* controlBlock;
};

struct UTuple {
    char pad[172];
    SharedPtr* m_p;

    bool f(SharedPtr* a1);
};

extern "C" void __cdecl free(void*);
extern "C" void __stdcall SetEvent(void*);

void __cdecl sub_4015a0(int, int);
void __cdecl sub_40b9c0();
void __cdecl sub_40c750(int);
void __cdecl sub_413890(void*);
void __cdecl sub_6d31d0(void*);
void __cdecl sub_9831f5(int);

void* g_pEvent = (void*)0xB1E530;
volatile long* g_pRefCount = (volatile long*)0xE505B4;
volatile long* g_pWeakCount = (volatile long*)0xE505B8;
volatile char* g_pInitFlag = (volatile char*)0xE505BC;
void (__stdcall* g_pSetEvent)(void*) = (void (__stdcall*)(void*))0xB2230C;
void (__cdecl* g_pFree)(void*) = (void (__cdecl*)(void*))0xB229C8;

bool UTuple::f(SharedPtr* a1)
{
    SharedPtrControlBlock* edi = a1 ? a1->controlBlock : 0;
    SharedPtr* ebp = this->m_p;
    int ebx = 0;

    if (edi) {
        sub_40c750((int)edi + 5);
    }

    sub_4015a0(0x816020, 0xE505CC);
    *g_pRefCount = 0;
    *g_pWeakCount = 0;

    if (!(*g_pInitFlag & 1)) {
        *g_pInitFlag |= 1;
        sub_9831f5((int)g_pEvent);
    }

    char localFlag = 0;
    sub_413890(&g_pRefCount);

    void* esiManaged = ebp ? ebp->managedObject : 0;
    localFlag = 1;

    void* arg;
    if (!esiManaged) {
        arg = ebp;
    } else {
        arg = (char*)esiManaged + 12;
    }
    sub_6d31d0(arg);
    localFlag = 0;

    if (!ebp->managedObject) {
        if (localFlag) {
            volatile long* ecx = g_pRefCount;
            long oldVal = _InterlockedExchangeAdd(ecx, 0x80000000);
            if (!(oldVal & 0x40000000)) {
                if (oldVal > 0x80000000) {
                    _InterlockedExchangeAdd(ecx, 0x40000000);
                    sub_40b9c0();
                    g_pSetEvent(0);
                }
            }
        }

        if (edi) {
            int eax = (int)edi + 5;
            SharedPtrControlBlock* esiBlock;
            if (eax) {
                esiBlock = (SharedPtrControlBlock*)(eax - 5);
            } else {
                esiBlock = 0;
            }

            volatile long* edx = &esiBlock->refCount;
            long oldVal = _InterlockedExchangeAdd(edx, -1);
            if (oldVal == 1) {
                void (*deleter)(void*) = esiBlock->deleter;
                deleter(0);
                volatile long* ecx2 = &esiBlock->weakCount;
                long oldVal2 = _InterlockedExchangeAdd(ecx2, -1);
                if (oldVal2 == 1) {
                    g_pFree(esiBlock);
                }
            }
        }
        return false;
    } else {
        if (localFlag) {
            volatile long* ecx = g_pRefCount;
            long oldVal = _InterlockedExchangeAdd(ecx, 0x80000000);
            if (!(oldVal & 0x40000000)) {
                if (oldVal > 0x80000000) {
                    _InterlockedExchangeAdd(ecx, 0x40000000);
                    sub_40b9c0();
                    g_pSetEvent(0);
                }
            }
        }

        if (edi) {
            int eax = (int)edi + 5;
            SharedPtrControlBlock* esiBlock;
            if (eax) {
                esiBlock = (SharedPtrControlBlock*)(eax - 5);
            } else {
                esiBlock = 0;
            }

            volatile long* edx = &esiBlock->refCount;
            long oldVal = _InterlockedExchangeAdd(edx, -1);
            if (oldVal == 1) {
                void (*deleter)(void*) = esiBlock->deleter;
                deleter(0);
                volatile long* ecx2 = &esiBlock->weakCount;
                long oldVal2 = _InterlockedExchangeAdd(ecx2, -1);
                if (oldVal2 == 1) {
                    g_pFree(esiBlock);
                }
            }
        }
        return true;
    }
}
