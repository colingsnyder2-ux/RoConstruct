// from server: 100% by nuck16
// roc 2009-12 006bb6a0  unit: RBX::VDecal::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bb6a0
//
// 006bb6a0  c701ac679d00         mov dword ptr [ecx], 0x9d67ac
// 006bb6a6  c74104a0679d00       mov dword ptr [ecx + 4], 0x9d67a0
// 006bb6ad  c7411894679d00       mov dword ptr [ecx + 0x18], 0x9d6794
// 006bb6b4  c7411c8c679d00       mov dword ptr [ecx + 0x1c], 0x9d678c
// 006bb6bb  c7819400000074679d00 mov dword ptr [ecx + 0x94], 0x9d6774
// 006bb6c5  e936ffffff           jmp 0x6bb600

extern "C" void func_6bb600();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d67ac;
    *(int *)((char *)this + 0x4) = 0x9d67a0;
    *(int *)((char *)this + 0x18) = 0x9d6794;
    *(int *)((char *)this + 0x1c) = 0x9d678c;
    *(int *)((char *)this + 0x94) = 0x9d6774;
    func_6bb600();
}
