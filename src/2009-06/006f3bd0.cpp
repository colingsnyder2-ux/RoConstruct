// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Humanoid;
class INamed { public: virtual const char* getName() const = 0; virtual ~INamed() {} };
class HitTestFilter { public: virtual int filterResult(const void* p) const = 0; };
template<class Base, const char* sName>
class __declspec(novtable) Named : public Base {
public:
    template<class A, class B> Named(A a, B b) : Base(a, b) {}
    virtual const char* getName() const { return sName; }
};
namespace HUMAN {
extern const char sDead[];
class HumanoidState : public INamed, public HitTestFilter {
public:
    HumanoidState(Humanoid* humanoid, HumanoidState* prior);
    virtual ~HumanoidState();
    virtual int filterResult(const void* p) const;
    virtual void onStep();
    float time;
};
class Dead : public Named<HumanoidState, sDead> {
public:
    Dead(Humanoid* humanoid, HumanoidState* prior);
    virtual void onStep();
};
Dead::Dead(Humanoid* humanoid, HumanoidState* prior)
    : Named<HumanoidState, sDead>(humanoid, prior)
{
}
}
}
