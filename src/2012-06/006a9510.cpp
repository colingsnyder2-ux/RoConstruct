// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl f_00424d70(void*);
extern "C" void __cdecl f_006a4750(void*);

struct T4_004026a0 {
    void f_004026a0(void*);
};
struct T4_006a5a00 {
    void f_006a5a00();
};

struct T4_006a9510 {
    char pad0[0x10];
    void** m_10;
    int m_14;
    int m_18;
    int m_1c;
    char m_20;
    bool f_006a9510(void* arg);
};

bool T4_006a9510::f_006a9510(void* arg)
{
    char* edi = &m_20;
    void* eax = f_00424d70(edi);
    char saved = (char)(int)eax;
    if (m_1c == 0) {
        if (edi)
            *edi = saved;
        return false;
    }
    void* p = *(void**)this;
    int ecx = m_18;
    void* edx;
    if (p) edx = *(void**)p; else edx = 0;
    if (*(int*)((char*)edx + 0x14) <= ecx) {
        if (p) edx = *(void**)p; else edx = 0;
        ecx -= *(int*)((char*)edx + 0x14);
    }
    if (p) eax = *(void**)p; else eax = 0;
    eax = *(void**)((char*)eax + 0x10);
    void* ebp = *(void**)((char*)eax + ecx * 4);
    void* eax2 = *(void**)ebp;
    if (eax2) {
        _InterlockedExchangeAdd((volatile long*)eax2, 1);
    }
    void** edi2 = (void**)arg;
    void* ecx2 = *edi2;
    *edi2 = eax2;
    if (ecx2)
        f_006a4750(ecx2);
    int eax3 = *(int*)((char*)ebp + 4);
    ebp = (char*)ebp + 8;
    *(int*)((char*)edi2 + 4) = eax3;
    ((T4_004026a0*)((char*)edi2 + 8))->f_004026a0(ebp);
    if (m_1c != 0) {
        int ecx3 = m_18;
        void** edx2 = (void**)m_10;
        ((T4_006a5a00*)edx2[ecx3])->f_006a5a00();
        m_18++;
        if (m_14 <= m_18)
            m_18 = 0;
        if (--m_1c == 0)
            m_18 = 0;
    }
    if (edi)
        *edi = saved;
    return true;
}
