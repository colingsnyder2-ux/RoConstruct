// from server: 100% by colin
struct VStockSound_FactoryProduct {
    void* field0;
    void* field4;
    void* field8;
    void construct(void* a, void* b);
};

extern "C" char __cdecl sub_004879d0(void* p);
extern "C" void* __cdecl sub_0062fef6(unsigned int size);

void VStockSound_FactoryProduct::construct(void* a, void* b)
{
    void* local[2];
    local[0] = a;
    local[1] = b;
    if (!sub_004879d0(local)) {
        field8 = (void*)0x589420;
        field0 = (void*)0x588e30;
        void* p = sub_0062fef6(8);
        if (p != 0) {
            *(void**)p = local[0];
            *(void**)((char*)p + 4) = local[1];
        }
        field4 = p;
    }
}
