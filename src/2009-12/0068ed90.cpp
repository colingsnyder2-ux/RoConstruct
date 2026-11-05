// from server: 100% by nuck16
// roc 2009-12 0068ed90  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068ed90
//
// 0068ed90  c701dc119d00         mov dword ptr [ecx], 0x9d11dc
// 0068ed96  c74104d4119d00       mov dword ptr [ecx + 4], 0x9d11d4
// 0068ed9d  c74118c8119d00       mov dword ptr [ecx + 0x18], 0x9d11c8
// 0068eda4  c7411cc0119d00       mov dword ptr [ecx + 0x1c], 0x9d11c0
// 0068edab  c78194000000b8119d00 mov dword ptr [ecx + 0x94], 0x9d11b8
// 0068edb5  e9b608d8ff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d11dc;
    *(int *)((char *)this + 0x4) = 0x9d11d4;
    *(int *)((char *)this + 0x18) = 0x9d11c8;
    *(int *)((char *)this + 0x1c) = 0x9d11c0;
    *(int *)((char *)this + 0x94) = 0x9d11b8;
    func_40f670();
}
