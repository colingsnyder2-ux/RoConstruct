// from server: 100% by nuck16
// roc 2009-12 0063d350  unit: RBX::Network::P8Player::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063d350
//
// 0063d350  c70104c49c00         mov dword ptr [ecx], 0x9cc404
// 0063d356  c74104f8c39c00       mov dword ptr [ecx + 4], 0x9cc3f8
// 0063d35d  c74118ecc39c00       mov dword ptr [ecx + 0x18], 0x9cc3ec
// 0063d364  c7411ce4c39c00       mov dword ptr [ecx + 0x1c], 0x9cc3e4
// 0063d36b  e990a7ffff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cc404;
    *(int *)((char *)this + 0x4) = 0x9cc3f8;
    *(int *)((char *)this + 0x18) = 0x9cc3ec;
    *(int *)((char *)this + 0x1c) = 0x9cc3e4;
    func_637b00();
}
