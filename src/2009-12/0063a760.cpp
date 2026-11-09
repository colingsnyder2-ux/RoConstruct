// from server: 100% by nuck16
// roc 2009-12 0063a760  unit: RBX::Selection  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063a760
//
// 0063a760  c7012cc29c00         mov dword ptr [ecx], 0x9cc22c
// 0063a766  c7410424c29c00       mov dword ptr [ecx + 4], 0x9cc224
// 0063a76d  c7411818c29c00       mov dword ptr [ecx + 0x18], 0x9cc218
// 0063a774  c7411c10c29c00       mov dword ptr [ecx + 0x1c], 0x9cc210
// 0063a77b  e980d3ffff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cc22c;
    *(int *)((char *)this + 0x4) = 0x9cc224;
    *(int *)((char *)this + 0x18) = 0x9cc218;
    *(int *)((char *)this + 0x1c) = 0x9cc210;
    func_637b00();
}
