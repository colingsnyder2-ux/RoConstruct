// from server: 100% by why2
extern "C" long (__stdcall *InterlockedExchange)(long volatile* Target, long Value);

struct RBX_VInstance_NonFactoryProduct {
    char pad[0x2dc];
    long field_2dc;
    void func();
};

void RBX_VInstance_NonFactoryProduct::func() {
    long* p = (long*)(*(char**)this + 0x2dc);
    InterlockedExchange(p, 0);
}
