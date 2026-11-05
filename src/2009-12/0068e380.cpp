// from server: 100% by atomic.potato
struct VHopperBin {
    void* vtbl0;
    void* vtbl4;
    char pad8[0x10];
    void* vtbl18;
    void* vtbl1c;
    void destroy();
    void* FactoryProduct(unsigned int flags);
};

extern "C" void __cdecl sub_637b00();
extern "C" void __cdecl sub_7f385a(void*);

void* VHopperBin::FactoryProduct(unsigned int flags)
{
    vtbl0 = (void*)0x9d114c;
    vtbl4 = (void*)0x9d1144;
    vtbl18 = (void*)0x9d1138;
    vtbl1c = (void*)0x9d1130;
    sub_637b00();
    if (flags & 1) {
        sub_7f385a(this);
    }
    return this;
}
