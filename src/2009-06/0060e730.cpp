// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00581b60  unit: RBX::CameraZoomOutCommand  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581b60
//
// 00581b60  56                   push esi
// 00581b61  8bf1                 mov esi, ecx
// 00581b63  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581b66  8d8888020000         lea ecx, [eax + 0x288]
// 00581b6c  8b01                 mov eax, dword ptr [ecx]
// 00581b6e  8b5004               mov edx, dword ptr [eax + 4]
// 00581b71  ffd2                 call edx
// 00581b73  d905b8c38100         fld dword ptr [0x81c3b8]
// 00581b79  51                   push ecx
// 00581b7a  8bc8                 mov ecx, eax
// 00581b7c  d91c24               fstp dword ptr [esp]
// 00581b7f  e8fcb20400           call 0x5cce80
// 00581b84  84c0                 test al, al
// 00581b86  7428                 je 0x581bb0
// 00581b88  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581b8b  6a0b                 push 0xb
// 00581b8d  50                   push eax
// 00581b8e  e81decffff           call 0x5807b0
// 00581b93  83c404               add esp, 4
// 00581b96  8bc8                 mov ecx, eax
// 00581b98  e883bc0300           call 0x5bd820
// 00581b9d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581ba1  8b11                 mov edx, dword ptr [ecx]
// 00581ba3  5e                   pop esi
// 00581ba4  c744240401000000     mov dword ptr [esp + 4], 1
// 00581bac  8b02                 mov eax, dword ptr [edx]
// 00581bae  ffe0                 jmp eax
// 00581bb0  5e                   pop esi
// 00581bb1  c20400               ret 4

extern float zoomAmount;

struct Camera {
    bool zoom(float amount);
};

struct CameraProvider {
    virtual void reserved();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[0x118];
    CameraProvider provider;
};

struct ServiceProvider {
    void notify(int event);
};

extern ServiceProvider* __cdecl func_005807b0(Owner* owner);

struct Completion {
    virtual void complete(int result);
};

struct CameraZoomOutCommand {
    char padding[0x0C];
    Owner* owner;
    void execute(Completion* completion);
};

void CameraZoomOutCommand::execute(Completion* completion) {
    Camera* camera = owner->provider.getCamera();
    if (camera->zoom(zoomAmount)) {
        func_005807b0(owner)->notify(11);
        completion->complete(1);
    }
}
