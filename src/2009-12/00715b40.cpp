// from server: 100% by nuck16
// roc 2009-12 00715b40  unit: RBX::VGlue::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00715b40
//
// 00715b40  c70164ed9d00         mov dword ptr [ecx], 0x9ded64
// 00715b46  c7410458ed9d00       mov dword ptr [ecx + 4], 0x9ded58
// 00715b4d  c741184ced9d00       mov dword ptr [ecx + 0x18], 0x9ded4c
// 00715b54  c7411c44ed9d00       mov dword ptr [ecx + 0x1c], 0x9ded44
// 00715b5b  c781940000002ced9d00 mov dword ptr [ecx + 0x94], 0x9ded2c
// 00715b65  e926feffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9ded64;
    *(int *)((char *)this + 0x4) = 0x9ded58;
    *(int *)((char *)this + 0x18) = 0x9ded4c;
    *(int *)((char *)this + 0x1c) = 0x9ded44;
    *(int *)((char *)this + 0x94) = 0x9ded2c;
    func_715990();
}
