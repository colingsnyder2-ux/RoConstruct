// from server: 15% by Viper
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
extern "C" void* __cdecl sub_68eb40(void*, int, int, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_64ef10(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_68e920(void*, void*, void*, void*, void*, void*);

void* VHopperBin::FactoryProduct(unsigned int flags)
{
    vtbl0 = (void*)0x9d16a0;
    sub_637b00();
    if (flags & 1) {
        sub_7f385a(this);
    }
    return this;
}
