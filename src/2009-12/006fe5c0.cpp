// from server: 100% by nuck16
// roc 2009-12 006fe5c0  unit: RBX::Soundscape::P8SoundChannel::?$GetSetImpl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fe5c0
//
// 006fe5c0  c7012cd69d00         mov dword ptr [ecx], 0x9dd62c
// 006fe5c6  c7410420d69d00       mov dword ptr [ecx + 4], 0x9dd620
// 006fe5cd  c7411814d69d00       mov dword ptr [ecx + 0x18], 0x9dd614
// 006fe5d4  c7411c0cd69d00       mov dword ptr [ecx + 0x1c], 0x9dd60c
// 006fe5db  c7819400000004d69d00 mov dword ptr [ecx + 0x94], 0x9dd604
// 006fe5e5  e91695f3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dd62c;
    *(int *)((char *)this + 0x4) = 0x9dd620;
    *(int *)((char *)this + 0x18) = 0x9dd614;
    *(int *)((char *)this + 0x1c) = 0x9dd60c;
    *(int *)((char *)this + 0x94) = 0x9dd604;
    func_637b00();
}
