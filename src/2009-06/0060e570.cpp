// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005819a0  unit: RBX::CameraVerb  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005819a0
//
// 005819a0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 005819a3  6a0b                 push 0xb
// 005819a5  50                   push eax
// 005819a6  e805eeffff           call 0x5807b0
// 005819ab  83c404               add esp, 4
// 005819ae  8bc8                 mov ecx, eax
// 005819b0  e86bbe0300           call 0x5bd820
// 005819b5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005819b9  8b11                 mov edx, dword ptr [ecx]
// 005819bb  8b02                 mov eax, dword ptr [edx]
// 005819bd  c744240401000000     mov dword ptr [esp + 4], 1
// 005819c5  ffe0                 jmp eax

namespace RBX {
    class Instance;
    class ServiceProvider {
    public:
        void action(int);
    };
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct Callback {
    virtual void invoke(int);
};

struct CameraVerb {
    char padding[12];
    RBX::Instance* instance;
    void execute(Callback*);
};

void CameraVerb::execute(Callback* callback)
{
    func_005807b0(instance)->action(11);
    callback->invoke(1);
}
