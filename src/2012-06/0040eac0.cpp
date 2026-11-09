// from server: 57% by atomic.potato
struct S {
    char pad0[0x28];
    void* field28;
    void* field2c;
    int field30;
    int field34;
    int field38;
    void* field3c;
    S* init(void*);
};

extern "C" void __stdcall sub_40dc90(void*);

S* S::init(void* arg) {
    sub_40dc90(arg);
    field3c = (void*)0xb43c34;
    *(void**)this = (void*)0xb442d8;
    field28 = (void*)0xb442d0;
    field3c = (void*)0xb442c0;
    void* ebx;
    if (arg) {
        ebx = (char*)arg + 0x28;
    } else {
        ebx = 0;
    }
    void* ecx = field2c;
    void* edi = *(void**)((char*)ebx + 4);
    if (ecx) {
        void** vt = *(void***)ecx;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[4];
        fn(ecx);
    }
    field2c = edi;
    if (edi) {
        void** vt = *(void***)edi;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[3];
        fn(edi);
    }
    field30 = *(int*)((char*)ebx + 8);
    field34 = *(int*)((char*)ebx + 0xc);
    field38 = *(int*)((char*)ebx + 0x10);
    return this;
}
