// from server: 100% by nuck16
// roc 2009-12 00774a90  unit: RBX::VerbWidget  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00774a90
//
// 00774a90  c701f48e9e00         mov dword ptr [ecx], 0x9e8ef4
// 00774a96  c74104ec8e9e00       mov dword ptr [ecx + 4], 0x9e8eec
// 00774a9d  c74118e08e9e00       mov dword ptr [ecx + 0x18], 0x9e8ee0
// 00774aa4  c7411cd88e9e00       mov dword ptr [ecx + 0x1c], 0x9e8ed8
// 00774aab  c78194000000d08e9e00 mov dword ptr [ecx + 0x94], 0x9e8ed0
// 00774ab5  e9b6abc9ff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e8ef4;
    *(int *)((char *)this + 0x4) = 0x9e8eec;
    *(int *)((char *)this + 0x18) = 0x9e8ee0;
    *(int *)((char *)this + 0x1c) = 0x9e8ed8;
    *(int *)((char *)this + 0x94) = 0x9e8ed0;
    func_40f670();
}
