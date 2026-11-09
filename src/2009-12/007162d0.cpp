// from server: 100% by nuck16
// roc 2009-12 007162d0  unit: RBX::VRotateP::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007162d0
//
// 007162d0  c701fcee9d00         mov dword ptr [ecx], 0x9deefc
// 007162d6  c74104f0ee9d00       mov dword ptr [ecx + 4], 0x9deef0
// 007162dd  c74118e4ee9d00       mov dword ptr [ecx + 0x18], 0x9deee4
// 007162e4  c7411cdcee9d00       mov dword ptr [ecx + 0x1c], 0x9deedc
// 007162eb  c78194000000c4ee9d00 mov dword ptr [ecx + 0x94], 0x9deec4
// 007162f5  e996f6ffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9deefc;
    *(int *)((char *)this + 0x4) = 0x9deef0;
    *(int *)((char *)this + 0x18) = 0x9deee4;
    *(int *)((char *)this + 0x1c) = 0x9deedc;
    *(int *)((char *)this + 0x94) = 0x9deec4;
    func_715990();
}
