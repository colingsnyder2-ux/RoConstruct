// from server: 100% by nuck16
// roc 2009-12 006df530  unit: RBX::VFileMesh::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006df530
//
// 006df530  c701f4a29d00         mov dword ptr [ecx], 0x9da2f4
// 006df536  c74104e8a29d00       mov dword ptr [ecx + 4], 0x9da2e8
// 006df53d  c74118dca29d00       mov dword ptr [ecx + 0x18], 0x9da2dc
// 006df544  c7411cd4a29d00       mov dword ptr [ecx + 0x1c], 0x9da2d4
// 006df54b  e9b085f5ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9da2f4;
    *(int *)((char *)this + 0x4) = 0x9da2e8;
    *(int *)((char *)this + 0x18) = 0x9da2dc;
    *(int *)((char *)this + 0x1c) = 0x9da2d4;
    func_637b00();
}
