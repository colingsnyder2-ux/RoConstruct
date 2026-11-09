// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Humanoid;
class StateBase { public: virtual ~StateBase(); };
class HitTestFilter { public: virtual int filterResult(const void* p) const; };
namespace HUMAN {
enum StateType { NONE };
class HumanoidState : public StateBase, public HitTestFilter {
public:
    HumanoidState(Humanoid* humanoid, StateType type);
    char pad[0x3c];
};
class Balancing : public HumanoidState {
    const float kP;
    const float kD;
public:
    Balancing(Humanoid* humanoid, StateType type);
    virtual int filterResult(const void* p) const;
};
Balancing::Balancing(Humanoid* humanoid, StateType type)
    : HumanoidState(humanoid, type), kP(300.0f), kD(50.0f)
{
}
}
}
