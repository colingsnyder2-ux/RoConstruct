// from server: 56% by atomic.potato
extern "C" void* __stdcall sub_9ea40c(void*, void*);

struct X_005948f0 {
    char pad_0[8];
    void* f_8;
    char pad_c[4];
    void* f_c;
    void* run(void* a, void* b);
};

void* X_005948f0::run(void* a, void* b) {
    void* p = a;
    if (p != 0) {
        p = (char*)p - 0x1c;
    } else {
        p = 0;
    }
    void* ecx = (char*)f_c + (int)p;
    void* fn = f_8;
    void* r = ((void* (__thiscall*)(void*, void*))fn)(ecx, b);
    sub_9ea40c((void*)0, r);
    return b;
}
