// from server: 100% by nuck16
// roc 2009-12 0074f820  unit: RBX::LocalBackpackTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074f820
//
// 0074f820  c70154429e00         mov dword ptr [ecx], 0x9e4254
// 0074f826  c7410448429e00       mov dword ptr [ecx + 4], 0x9e4248
// 0074f82d  c741183c429e00       mov dword ptr [ecx + 0x18], 0x9e423c
// 0074f834  c7411c34429e00       mov dword ptr [ecx + 0x1c], 0x9e4234
// 0074f83b  c781940000002c429e00 mov dword ptr [ecx + 0x94], 0x9e422c
// 0074f845  e926fecbff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e4254;
    *(int *)((char *)this + 0x4) = 0x9e4248;
    *(int *)((char *)this + 0x18) = 0x9e423c;
    *(int *)((char *)this + 0x1c) = 0x9e4234;
    *(int *)((char *)this + 0x94) = 0x9e422c;
    func_40f670();
}
