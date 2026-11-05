// from server: 100% by nuck16
// roc 2009-12 006e28a0  unit: RBX::VScriptInformationProvider::?$BoundFuncDesc  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e28a0
//
// 006e28a0  c701d4a89d00         mov dword ptr [ecx], 0x9da8d4
// 006e28a6  c74104c8a89d00       mov dword ptr [ecx + 4], 0x9da8c8
// 006e28ad  c74118bca89d00       mov dword ptr [ecx + 0x18], 0x9da8bc
// 006e28b4  c7411cb4a89d00       mov dword ptr [ecx + 0x1c], 0x9da8b4
// 006e28bb  e94052f5ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9da8d4;
    *(int *)((char *)this + 0x4) = 0x9da8c8;
    *(int *)((char *)this + 0x18) = 0x9da8bc;
    *(int *)((char *)this + 0x1c) = 0x9da8b4;
    func_637b00();
}
