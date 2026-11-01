// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a55aecb973e21b7f.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/bind.hpp>
namespace RBX {
class Instance {
public:
    template<class F> void visitDescendants(F f);
};
class Humanoid {
public:
    Instance* getTorso() const { return torso; }
private:
    char pad[0x234];
    Instance* torso;
};
class HitTestFilter { public: virtual int filterResult(int) const = 0; };
namespace HUMAN {
enum StateType { RUNNING_NO_PHYSICS = 8 };
class HumanoidState { public: virtual ~HumanoidState(); };
class MovingNoPhysicsBase : public HumanoidState, public HitTestFilter {
public:
    MovingNoPhysicsBase(Humanoid* humanoid, StateType priorState);
    virtual ~MovingNoPhysicsBase();
    virtual int filterResult(int) const;
    int pad[0x20];
};
void setPartTransparency(Instance* i, float t);
struct TransparencySetter {
    void (*fn)(Instance*, float);
    float value;
    TransparencySetter(void (*f)(Instance*, float), float v) : fn(f), value(v) {}
    void operator()(Instance* i) const { fn(i, value); }
};
inline TransparencySetter makeSetter(void (*f)(Instance*, float), float v) { return TransparencySetter(f, v); }
template<class F> inline void visitTorso(Humanoid* h, F f)
{
    if (Instance* t = h->getTorso())
        t->visitDescendants(f);
}
inline void setTransparency(Humanoid* humanoid, float t)
{
    visitTorso(humanoid, boost::bind(&setPartTransparency, _1, t));
}
class RunningNoPhysics : public MovingNoPhysicsBase {
public:
    RunningNoPhysics(Humanoid* humanoid, StateType priorState);
    virtual ~RunningNoPhysics();
};
RunningNoPhysics::RunningNoPhysics(Humanoid* humanoid, StateType priorState)
    : MovingNoPhysicsBase(humanoid, priorState)
{
    setTransparency(humanoid, 0.0f);
}
}
}
