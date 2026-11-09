// from server: 30% by colin
struct RBX_VDebrisService_FactoryProduct_Creator {
    void construct();
};

extern "C" void* __stdcall malloc(unsigned int size);
extern "C" void __stdcall sub_5FAE40(void* p, int flag);
extern "C" void __stdcall sub_590980(void* self, void* a, void* b, void* c);

void RBX_VDebrisService_FactoryProduct_Creator::construct()
{
    void* mem = malloc(0x2dc);
    if (mem != 0) {
        sub_5FAE40(mem, 1);
    } else {
        mem = 0;
    }
    sub_590980(this, mem, 0, 0);
}
