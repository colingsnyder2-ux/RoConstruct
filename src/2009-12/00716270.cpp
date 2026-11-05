// from server: 100% by nuck16
// roc 2009-12 00716270  unit: RBX::VRotate::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00716270
//
// 00716270  c70174ee9d00         mov dword ptr [ecx], 0x9dee74
// 00716276  c7410468ee9d00       mov dword ptr [ecx + 4], 0x9dee68
// 0071627d  c741185cee9d00       mov dword ptr [ecx + 0x18], 0x9dee5c
// 00716284  c7411c54ee9d00       mov dword ptr [ecx + 0x1c], 0x9dee54
// 0071628b  c781940000003cee9d00 mov dword ptr [ecx + 0x94], 0x9dee3c
// 00716295  e9f6f6ffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dee74;
    *(int *)((char *)this + 0x4) = 0x9dee68;
    *(int *)((char *)this + 0x18) = 0x9dee5c;
    *(int *)((char *)this + 0x1c) = 0x9dee54;
    *(int *)((char *)this + 0x94) = 0x9dee3c;
    func_715990();
}
