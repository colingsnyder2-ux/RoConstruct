// from server: 100% by nuck16
// roc 2009-12 006a2540  unit: RBX::Lua::VWeakFunctionRef::?$holder  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a2540
//
// 006a2540  c701ac2a9d00         mov dword ptr [ecx], 0x9d2aac
// 006a2546  c74104a02a9d00       mov dword ptr [ecx + 4], 0x9d2aa0
// 006a254d  c74118942a9d00       mov dword ptr [ecx + 0x18], 0x9d2a94
// 006a2554  c7411c8c2a9d00       mov dword ptr [ecx + 0x1c], 0x9d2a8c
// 006a255b  e9a055f9ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d2aac;
    *(int *)((char *)this + 0x4) = 0x9d2aa0;
    *(int *)((char *)this + 0x18) = 0x9d2a94;
    *(int *)((char *)this + 0x1c) = 0x9d2a8c;
    func_637b00();
}
