// from server: 100% by nuck16
// roc 2009-12 006d9cf0  unit: RBX::Controller  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d9cf0
//
// 006d9cf0  c701b4969d00         mov dword ptr [ecx], 0x9d96b4
// 006d9cf6  c74104ac969d00       mov dword ptr [ecx + 4], 0x9d96ac
// 006d9cfd  c74118a0969d00       mov dword ptr [ecx + 0x18], 0x9d96a0
// 006d9d04  c7411c98969d00       mov dword ptr [ecx + 0x1c], 0x9d9698
// 006d9d0b  c781940000008c969d00 mov dword ptr [ecx + 0x94], 0x9d968c
// 006d9d15  e986ffffff           jmp 0x6d9ca0

extern "C" void func_6d9ca0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d96b4;
    *(int *)((char *)this + 0x4) = 0x9d96ac;
    *(int *)((char *)this + 0x18) = 0x9d96a0;
    *(int *)((char *)this + 0x1c) = 0x9d9698;
    *(int *)((char *)this + 0x94) = 0x9d968c;
    func_6d9ca0();
}
