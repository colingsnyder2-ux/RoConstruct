// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00581a20  unit: RBX::CameraPanRightCommand  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581a20
//
// 00581a20  56                   push esi
// 00581a21  8bf1                 mov esi, ecx
// 00581a23  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581a26  8d8888020000         lea ecx, [eax + 0x288]
// 00581a2c  8b01                 mov eax, dword ptr [ecx]
// 00581a2e  8b5004               mov edx, dword ptr [eax + 4]
// 00581a31  6a01                 push 1
// 00581a33  ffd2                 call edx
// 00581a35  8bc8                 mov ecx, eax
// 00581a37  e8f4ae0400           call 0x5cc930
// 00581a3c  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581a3f  6a0b                 push 0xb
// 00581a41  50                   push eax
// 00581a42  e869edffff           call 0x5807b0
// 00581a47  83c404               add esp, 4
// 00581a4a  8bc8                 mov ecx, eax
// 00581a4c  e8cfbd0300           call 0x5bd820
// 00581a51  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00581a55  8b11                 mov edx, dword ptr [ecx]
// 00581a57  5e                   pop esi
// 00581a58  c744240401000000     mov dword ptr [esp + 4], 1
// 00581a60  8b02                 mov eax, dword ptr [edx]
// 00581a62  ffe0                 jmp eax

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

class ServiceProvider : public Instance {
public:
    void apply(int);
};
}

struct Camera {
    void panRight();
};

struct CameraAccess {
    virtual void slot0();
    virtual Camera* get(int);
};

struct Parent : RBX::Instance {
    char pad[0x10];
    CameraAccess access;
};

struct Callback {
    virtual void invoke(int);
};

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct CameraPanRightCommand {
    char pad[12];
    Parent* parent;
    void execute(Callback*);
};

void CameraPanRightCommand::execute(Callback* callback)
{
    parent->access.get(1)->panRight();
    func_005807b0(parent)->apply(11);
    callback->invoke(1);
}
