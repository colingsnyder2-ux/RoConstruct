// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00581a70  unit: RBX::CameraTiltUpCommand  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581a70
//
// 00581a70  56                   push esi
// 00581a71  8bf1                 mov esi, ecx
// 00581a73  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581a76  8d8888020000         lea ecx, [eax + 0x288]
// 00581a7c  8b01                 mov eax, dword ptr [ecx]
// 00581a7e  8b5004               mov edx, dword ptr [eax + 4]
// 00581a81  ffd2                 call edx
// 00581a83  6aff                 push -1
// 00581a85  8bc8                 mov ecx, eax
// 00581a87  e804ae0400           call 0x5cc890
// 00581a8c  84c0                 test al, al
// 00581a8e  7428                 je 0x581ab8
// 00581a90  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581a93  6a0b                 push 0xb
// 00581a95  50                   push eax
// 00581a96  e815edffff           call 0x5807b0
// 00581a9b  83c404               add esp, 4
// 00581a9e  8bc8                 mov ecx, eax
// 00581aa0  e87bbd0300           call 0x5bd820
// 00581aa5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581aa9  8b11                 mov edx, dword ptr [ecx]
// 00581aab  5e                   pop esi
// 00581aac  c744240401000000     mov dword ptr [esp + 4], 1
// 00581ab4  8b02                 mov eax, dword ptr [edx]
// 00581ab6  ffe0                 jmp eax
// 00581ab8  5e                   pop esi
// 00581ab9  c20400               ret 4

struct Camera {
    bool tilt(int direction);
};

struct CameraAccess {
    virtual void reserved();
    virtual Camera* get();
};

struct Callback {
    virtual void notify(int value);
};

namespace RBX {
    class Instance {
    public:
        char padding[0x118];
        CameraAccess access;
    };

    class ServiceProvider {
    public:
        void command(int value);
    };
}

RBX::ServiceProvider* func_005807b0(RBX::Instance* instance);

struct S {
    char padding[12];
    RBX::Instance* instance;
    void f(Callback* callback);
};

void S::f(Callback* callback)
{
    Camera* camera = instance->access.get();
    if (camera->tilt(-1)) {
        func_005807b0(instance)->command(11);
        callback->notify(1);
    }
}
