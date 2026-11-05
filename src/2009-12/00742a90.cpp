// from server: 100% by nuck16
// roc 2009-12 00742a90  unit: RBX::VHole::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00742a90
//
// 00742a90  c701742d9e00         mov dword ptr [ecx], 0x9e2d74
// 00742a96  c741046c2d9e00       mov dword ptr [ecx + 4], 0x9e2d6c
// 00742a9d  c74118602d9e00       mov dword ptr [ecx + 0x18], 0x9e2d60
// 00742aa4  c7411c582d9e00       mov dword ptr [ecx + 0x1c], 0x9e2d58
// 00742aab  c78194000000402d9e00 mov dword ptr [ecx + 0x94], 0x9e2d40
// 00742ab5  e9f6f7ffff           jmp 0x7422b0

extern "C" void func_7422b0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e2d74;
    *(int *)((char *)this + 0x4) = 0x9e2d6c;
    *(int *)((char *)this + 0x18) = 0x9e2d60;
    *(int *)((char *)this + 0x1c) = 0x9e2d58;
    *(int *)((char *)this + 0x94) = 0x9e2d40;
    func_7422b0();
}
