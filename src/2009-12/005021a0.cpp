// from server: 100% by nuck16
// roc 2009-12 005021a0  unit: RBX::VShirt::?$FactoryProduct  size: 42 bytes
//
// 005021a0  c7013ca69b00         mov dword ptr [ecx], 0x9ba63c
// 005021a6  c7410434a69b00       mov dword ptr [ecx + 4], 0x9ba634
// 005021ad  c7411828a69b00       mov dword ptr [ecx + 0x18], 0x9ba628
// 005021b4  c7411c20a69b00       mov dword ptr [ecx + 0x1c], 0x9ba620
// 005021bb  c7819400000018a69b00 mov dword ptr [ecx + 0x94], 0x9ba618
// 005021c5  e916fdffff           jmp 0x501ee0

extern "C" void func_501ee0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9ba63c;
    *(int *)((char *)this + 0x4) = 0x9ba634;
    *(int *)((char *)this + 0x18) = 0x9ba628;
    *(int *)((char *)this + 0x1c) = 0x9ba620;
    *(int *)((char *)this + 0x94) = 0x9ba618;
    func_501ee0();
}
