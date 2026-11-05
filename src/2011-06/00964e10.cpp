// from server: 46% by atomic.potato
struct S_func_0092b620 {
    char pad0[2120];
    int m_x;
    int f();
};
int S_func_0092b620::f() {
    return m_x;
}

extern "C" int __stdcall func_0092b620();
extern "C" int __stdcall func_0096e220();

int RBX_RbxParticleEmitter_func_00964e10(void* thisptr) {
    if (*((int*)((char*)thisptr + 4)) != 0) {
        if (*((int*)((char*)thisptr + 0x1c)) != 0) {
            int eax = *((int*)((char*)thisptr - 0x54));
            int edx = *((int*)((char*)eax + 0x4880));
            int eax2 = (int)((char*)thisptr - 0x1c4);
            eax2 = -eax2;
            eax2 = eax2 - eax2;
            eax2 = eax2 & (int)thisptr;
            int ecx = edx;
            int eax3 = func_0092b620();
            ecx = eax3;
            int eax4 = func_0096e220();
            return eax4;
        }
    }
    return 0;
}
