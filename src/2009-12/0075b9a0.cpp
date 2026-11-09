// from server: 100% by nuck16
// roc 2009-12 0075b9a0  unit: RBX::VTextBox::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075b9a0
//
// 0075b9a0  c7018c669e00         mov dword ptr [ecx], 0x9e668c
// 0075b9a6  c7410480669e00       mov dword ptr [ecx + 4], 0x9e6680
// 0075b9ad  c7411874669e00       mov dword ptr [ecx + 0x18], 0x9e6674
// 0075b9b4  c7411c6c669e00       mov dword ptr [ecx + 0x1c], 0x9e666c
// 0075b9bb  c781940000005c669e00 mov dword ptr [ecx + 0x94], 0x9e665c
// 0075b9c5  c7819800000044669e00 mov dword ptr [ecx + 0x98], 0x9e6644
// 0075b9cf  e9bcbcffff           jmp 0x757690

extern "C" void func_757690();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e668c;
    *(int *)((char *)this + 0x4) = 0x9e6680;
    *(int *)((char *)this + 0x18) = 0x9e6674;
    *(int *)((char *)this + 0x1c) = 0x9e666c;
    *(int *)((char *)this + 0x94) = 0x9e665c;
    *(int *)((char *)this + 0x98) = 0x9e6644;
    func_757690();
}
