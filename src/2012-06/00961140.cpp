// from server: 100% by Xemicl
// roc 2012-06 00961140  unit: RBX::HUMAN::Jumping  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00961140
//
// 00961140  d905d485b600         fld dword ptr [0xb685d4]
// 00961146  8b442408             mov eax, dword ptr [esp + 8]
// 0096114a  56                   push esi
// 0096114b  83ec08               sub esp, 8
// 0096114e  d95c2404             fstp dword ptr [esp + 4]
// 00961152  8bf1                 mov esi, ecx
// 00961154  d9052053b600         fld dword ptr [0xb65320]
// 0096115a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096115e  d91c24               fstp dword ptr [esp]
// 00961161  50                   push eax
// 00961162  51                   push ecx
// 00961163  8bce                 mov ecx, esi
// 00961165  e8e6990000           call 0x96ab50
// 0096116a  c706284fc000         mov dword ptr [esi], 0xc04f28
// 00961170  c746041c4fc000       mov dword ptr [esi + 4], 0xc04f1c
// 00961177  8bc6                 mov eax, esi
// 00961179  5e                   pop esi
// 0096117a  c20800               ret 8
// copied from an identical function in another client (function ??0GettingUp@HUMAN@RBX@@QAE@PAVHumanoid@2@W4StateType@12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Humanoid;
class INamed { public: virtual const char* name() const = 0; };
class HitTestFilter { public: virtual int filterResult(void* p) const = 0; };
namespace HUMAN {
enum StateType { A, B };
class HumanoidState : public INamed, public HitTestFilter {
public:
    HumanoidState(Humanoid* h, StateType prior);
    virtual ~HumanoidState();
};
class Balancing : public HumanoidState {
public:
    float kP, kD;
    Balancing(Humanoid* h, StateType prior, float kP, float kD);
};
extern const char* const sGettingUp;
}
template<class Base, const char* const& Name> class Named : public Base {
public:
    Named(Humanoid* h, HUMAN::StateType prior, float a, float b) : Base(h, prior, a, b) {}
    virtual const char* name() const { return Name; }
};
namespace HUMAN {
class GettingUp : public Named<Balancing, sGettingUp> {
public:
    GettingUp(Humanoid* h, StateType prior);
    virtual ~GettingUp() {}
};
GettingUp::GettingUp(Humanoid* h, StateType prior)
    : Named<Balancing, sGettingUp>(h, prior, 5000.0f, 300.0f)
{}
}
}