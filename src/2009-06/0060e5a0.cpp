// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005819d0  unit: RBX::CameraPanLeftCommand  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005819d0
//
// 005819d0  56                   push esi
// 005819d1  8bf1                 mov esi, ecx
// 005819d3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005819d6  8d8888020000         lea ecx, [eax + 0x288]
// 005819dc  8b01                 mov eax, dword ptr [ecx]
// 005819de  8b5004               mov edx, dword ptr [eax + 4]
// 005819e1  6aff                 push -1
// 005819e3  ffd2                 call edx
// 005819e5  8bc8                 mov ecx, eax
// 005819e7  e844af0400           call 0x5cc930
// 005819ec  8b460c               mov eax, dword ptr [esi + 0xc]
// 005819ef  6a0b                 push 0xb
// 005819f1  50                   push eax
// 005819f2  e8b9edffff           call 0x5807b0
// 005819f7  83c404               add esp, 4
// 005819fa  8bc8                 mov ecx, eax
// 005819fc  e81fbe0300           call 0x5bd820
// 00581a01  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581a05  8b11                 mov edx, dword ptr [ecx]
// 00581a07  5e                   pop esi
// 00581a08  c744240401000000     mov dword ptr [esp + 4], 1
// 00581a10  8b02                 mov eax, dword ptr [edx]
// 00581a12  ffe0                 jmp eax

struct Camera {
    void panLeft();
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera(int index);
};

struct Completion {
    virtual void complete(int value);
};

namespace RBX {
    struct Instance {
        char padding[0x288];
        CameraSource source;
    };

    struct ServiceProvider {
        void activate(int command);
    };
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance* instance);

struct CameraPanLeftCommand {
    char padding[12];
    RBX::Instance* instance;

    void execute(Completion* completion);
};

void CameraPanLeftCommand::execute(Completion* completion)
{
    instance->source.getCamera(-1)->panLeft();
    func_005807b0(instance)->activate(11);
    completion->complete(1);
}
