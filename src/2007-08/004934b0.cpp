// from server: 48% by colin
struct NonFactoryProduct {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void destroy();
};

extern "C" void __cdecl free_mem(void*);

void NonFactoryProduct::destroy()
{
    field0 = (void*)0x79b894;
    if (field8) {
        free_mem(field8);
    }
    field8 = 0;
    fieldC = 0;
    field10 = 0;
}
