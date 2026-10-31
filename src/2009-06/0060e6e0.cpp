// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00581b10  unit: RBX::CameraZoomInCommand  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581b10
//
// 00581b10  56                   push esi
// 00581b11  8bf1                 mov esi, ecx
// 00581b13  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581b16  8d8888020000         lea ecx, [eax + 0x288]
// 00581b1c  8b01                 mov eax, dword ptr [ecx]
// 00581b1e  8b5004               mov edx, dword ptr [eax + 4]
// 00581b21  ffd2                 call edx
// 00581b23  d9e8                 fld1 
// 00581b25  51                   push ecx
// 00581b26  d91c24               fstp dword ptr [esp]
// 00581b29  8bc8                 mov ecx, eax
// 00581b2b  e850b30400           call 0x5cce80
// 00581b30  84c0                 test al, al
// 00581b32  7428                 je 0x581b5c
// 00581b34  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581b37  6a0b                 push 0xb
// 00581b39  50                   push eax
// 00581b3a  e871ecffff           call 0x5807b0
// 00581b3f  83c404               add esp, 4
// 00581b42  8bc8                 mov ecx, eax
// 00581b44  e8d7bc0300           call 0x5bd820
// 00581b49  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581b4d  8b11                 mov edx, dword ptr [ecx]
// 00581b4f  5e                   pop esi
// 00581b50  c744240401000000     mov dword ptr [esp + 4], 1
// 00581b58  8b02                 mov eax, dword ptr [edx]
// 00581b5a  ffe0                 jmp eax
// 00581b5c  5e                   pop esi
// 00581b5d  c20400               ret 4

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        void notify(int);
    };
}

RBX::ServiceProvider* func_005807b0(RBX::Instance* p);

struct Camera {
    bool zoom(float amount);
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Owner : RBX::Instance {
    char padding[0x180];
    CameraProvider provider;
};

struct Callback {
    virtual void invoke(int value);
};

struct CameraZoomInCommand {
    char padding[12];
    Owner* owner;
    void execute(Callback* callback);
};

void CameraZoomInCommand::execute(Callback* callback) {
    Camera* camera = owner->provider.getCamera();
    if (camera->zoom(1.0f)) {
        func_005807b0(owner)->notify(11);
        callback->invoke(1);
    }
}
