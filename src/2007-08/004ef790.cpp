// from server: 47% by colin
struct VMaterial {
    int pad0;
    int pad4;
    void* ptr8;
    void* ptrC;
    void release();
};

extern "C" long __stdcall InterlockedDecrement(long volatile*);
extern "C" void __cdecl sub_457DD0(void*);

void VMaterial::release()
{
    if (ptrC) {
        if (InterlockedDecrement((long*)((char*)ptrC + 4)) == 0) {
            sub_457DD0(ptrC);
            if (ptrC) {
                void** vt = *(void***)ptrC;
                ((void (__thiscall*)(void*, int))vt[0])(ptrC, 1);
            }
        }
        ptrC = 0;
    }
    if (ptr8) {
        if (InterlockedDecrement((long*)((char*)ptr8 + 4)) == 0) {
            sub_457DD0(ptr8);
            if (ptr8) {
                void** vt = *(void***)ptr8;
                ((void (__thiscall*)(void*, int))vt[0])(ptr8, 1);
            }
        }
        ptr8 = 0;
    }
}
