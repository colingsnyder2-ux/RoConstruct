// from server: 100% by nuck16
// roc 2009-12 006c6500  unit: RBX::Network::VPlayer::?$BoundPropGetSet  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c6500
//
// 006c6500  c70194729d00         mov dword ptr [ecx], 0x9d7294
// 006c6506  c7410488729d00       mov dword ptr [ecx + 4], 0x9d7288
// 006c650d  c741187c729d00       mov dword ptr [ecx + 0x18], 0x9d727c
// 006c6514  c7411c74729d00       mov dword ptr [ecx + 0x1c], 0x9d7274
// 006c651b  e9e015f7ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d7294;
    *(int *)((char *)this + 0x4) = 0x9d7288;
    *(int *)((char *)this + 0x18) = 0x9d727c;
    *(int *)((char *)this + 0x1c) = 0x9d7274;
    func_637b00();
}
