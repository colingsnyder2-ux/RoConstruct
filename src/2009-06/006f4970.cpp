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
