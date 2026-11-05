// from server: 100% by nuck16
// roc 2009-12 0075a620  unit: RBX::VTextLabel::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075a620
//
// 0075a620  c701f4619e00         mov dword ptr [ecx], 0x9e61f4
// 0075a626  c74104e8619e00       mov dword ptr [ecx + 4], 0x9e61e8
// 0075a62d  c74118dc619e00       mov dword ptr [ecx + 0x18], 0x9e61dc
// 0075a634  c7411cd4619e00       mov dword ptr [ecx + 0x1c], 0x9e61d4
// 0075a63b  c78194000000c4619e00 mov dword ptr [ecx + 0x94], 0x9e61c4
// 0075a645  c78198000000ac619e00 mov dword ptr [ecx + 0x98], 0x9e61ac
// 0075a64f  e93cd0ffff           jmp 0x757690

extern "C" void func_757690();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e61f4;
    *(int *)((char *)this + 0x4) = 0x9e61e8;
    *(int *)((char *)this + 0x18) = 0x9e61dc;
    *(int *)((char *)this + 0x1c) = 0x9e61d4;
    *(int *)((char *)this + 0x94) = 0x9e61c4;
    *(int *)((char *)this + 0x98) = 0x9e61ac;
    func_757690();
}
