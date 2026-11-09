// from server: 84% by Intel
struct VModelInstance {
    void FactoryProduct();
};

extern "C" void __stdcall sub_7B6250();

void VModelInstance::FactoryProduct() {
    int* vtable = reinterpret_cast<int*>(this);
    int* base = reinterpret_cast<int*>(this + 0x84);
    int value = base[1];
    vtable[0] = 0x00B8FFB4;
    vtable[1] = 0x00B8FFAC;
    vtable[6] = 0x00B8FFA0;
    vtable[7] = 0x00B8FF94;
    reinterpret_cast<int*>(this + 0x80)[0] = 0x00B8FF8C;
    reinterpret_cast<int*>(base + value + 0x84)[0] = 0x00B8FF84;
    sub_7B6250();
}
