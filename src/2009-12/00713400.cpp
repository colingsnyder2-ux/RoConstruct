// from server: 100% by nuck16
// roc 2009-12 00713400  unit: RBX::P8Smoke::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00713400
//
// 00713400  c7019ce49d00         mov dword ptr [ecx], 0x9de49c
// 00713406  c7410490e49d00       mov dword ptr [ecx + 4], 0x9de490
// 0071340d  c7411884e49d00       mov dword ptr [ecx + 0x18], 0x9de484
// 00713414  c7411c7ce49d00       mov dword ptr [ecx + 0x1c], 0x9de47c
// 0071341b  e9e046f2ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9de49c;
    *(int *)((char *)this + 0x4) = 0x9de490;
    *(int *)((char *)this + 0x18) = 0x9de484;
    *(int *)((char *)this + 0x1c) = 0x9de47c;
    func_637b00();
}
