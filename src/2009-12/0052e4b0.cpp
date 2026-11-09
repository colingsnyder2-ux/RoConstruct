// from server: 100% by nuck16
// roc 2009-12 0052e4b0  unit: RBX::Network::VServer::?$EventDesc  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052e4b0
//
// 0052e4b0  c70134cc9b00         mov dword ptr [ecx], 0x9bcc34
// 0052e4b6  c7410428cc9b00       mov dword ptr [ecx + 4], 0x9bcc28
// 0052e4bd  c741181ccc9b00       mov dword ptr [ecx + 0x18], 0x9bcc1c
// 0052e4c4  c7411c14cc9b00       mov dword ptr [ecx + 0x1c], 0x9bcc14
// 0052e4cb  e930961000           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9bcc34;
    *(int *)((char *)this + 0x4) = 0x9bcc28;
    *(int *)((char *)this + 0x18) = 0x9bcc1c;
    *(int *)((char *)this + 0x1c) = 0x9bcc14;
    func_637b00();
}
