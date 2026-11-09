// from server: 100% by nuck16
// roc 2009-12 0057b370  unit: RBX::VCylinderMesh::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057b370
//
// 0057b370  c701e40b9c00         mov dword ptr [ecx], 0x9c0be4
// 0057b376  c74104dc0b9c00       mov dword ptr [ecx + 4], 0x9c0bdc
// 0057b37d  c74118d00b9c00       mov dword ptr [ecx + 0x18], 0x9c0bd0
// 0057b384  c7411cc80b9c00       mov dword ptr [ecx + 0x1c], 0x9c0bc8
// 0057b38b  e970c70b00           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9c0be4;
    *(int *)((char *)this + 0x4) = 0x9c0bdc;
    *(int *)((char *)this + 0x18) = 0x9c0bd0;
    *(int *)((char *)this + 0x1c) = 0x9c0bc8;
    func_637b00();
}
