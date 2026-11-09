// from server: 100% by colin
// from server: 75% by king_originala
// roc 2008-06 00581ac0  unit: RBX::CameraTiltDownCommand  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581ac0
//
// 00581ac0  56                   push esi
// 00581ac1  8bf1                 mov esi, ecx
// 00581ac3  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581ac6  8d8888020000         lea ecx, [eax + 0x288]
// 00581acc  8b01                 mov eax, dword ptr [ecx]
// 00581ace  8b5004               mov edx, dword ptr [eax + 4]
// 00581ad1  ffd2                 call edx
// 00581ad3  6a01                 push 1
// 00581ad5  8bc8                 mov ecx, eax
// 00581ad7  e8b4ad0400           call 0x5cc890
// 00581adc  84c0                 test al, al
// 00581ade  7428                 je 0x581b08
// 00581ae0  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581ae3  6a0b                 push 0xb
// 00581ae5  50                   push eax
// 00581ae6  e8c5ecffff           call 0x5807b0
// 00581aeb  83c404               add esp, 4
// 00581aee  8bc8                 mov ecx, eax
// 00581af0  e82bbd0300           call 0x5bd820
// 00581af5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581af9  8b11                 mov edx, dword ptr [ecx]
// 00581afb  5e                   pop esi
// 00581afc  c744240401000000     mov dword ptr [esp + 4], 1
// 00581b04  8b02                 mov eax, dword ptr [edx]
// 00581b06  ffe0                 jmp eax
// 00581b08  5e                   pop esi
// 00581b09  c20400               ret 4

#include <intrin.h>

namespace RBX {
    struct Instance;
    struct ServiceProvider {
        void tilt(int);
    };
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct Camera {
    bool canTilt(int);
};

struct CameraAccess {
    virtual void reserved();
    virtual Camera* get();
};

struct Completion {
    virtual void complete(int);
};

struct CameraTiltDownCommand {
    char padding[12];
    RBX::Instance* instance;

    void execute(Completion*);
};

void CameraTiltDownCommand::execute(Completion* completion)
{
    _ReadWriteBarrier();
    Camera* camera =
        reinterpret_cast<CameraAccess*>(
            reinterpret_cast<char*>(instance) + 0x288)->get();

    if (camera->canTilt(1)) {
        func_005807b0(instance)->tilt(11);
        completion->complete(1);
    }
}
