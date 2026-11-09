// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Humanoid;
namespace HUMAN {
class HumanoidState { public: virtual ~HumanoidState(); char pad[0x9c]; };
class FallingDown : public HumanoidState { public: FallingDown(Humanoid* h); char pad2[0x0]; };
class Ragdoll : public HumanoidState { public: Ragdoll(Humanoid* h); char pad2[0x8]; };
class GettingUp : public HumanoidState { public: GettingUp(Humanoid* h); char pad2[0x8]; };
class Jumping : public HumanoidState { public: Jumping(Humanoid* h); char pad2[0x20]; };
class Swimming : public HumanoidState { public: Swimming(Humanoid* h); char pad2[0x8]; };
class Freefall : public HumanoidState { public: Freefall(Humanoid* h); char pad2[0x2c]; };
class Flying : public HumanoidState { public: Flying(Humanoid* h); char pad2[0x2c]; };
class Running : public HumanoidState { public: Running(Humanoid* h); char pad2[0x74]; };
class RunningNoPhysics : public HumanoidState { public: RunningNoPhysics(Humanoid* h); char pad2[0x74]; };
class StrafingNoPhysics : public HumanoidState { public: StrafingNoPhysics(Humanoid* h); char pad2[0x2c]; };
class Climbing : public HumanoidState { public: Climbing(Humanoid* h); char pad2[0x0]; };
class Dead : public HumanoidState { public: Dead(Humanoid* h); char pad2[0x0]; };
class Landed : public HumanoidState { public: Landed(Humanoid* h); char pad2[0x2c]; };
HumanoidState* create(int type, Humanoid* h)
{
    switch (type) {
    case 0: return new FallingDown(h);
    case 1: return new Ragdoll(h);
    case 2: return new GettingUp(h);
    case 3: return new Jumping(h);
    case 4: return new Swimming(h);
    case 5: return new Freefall(h);
    case 6: return new Landed(h);
    case 7: return new Running(h);
    case 8: return new RunningNoPhysics(h);
    case 9: return new StrafingNoPhysics(h);
    case 10: return new Climbing(h);
    case 11: return new Dead(h);
    default: return new Landed(h);
    }
}
}
}
