// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive {
public:
    char pad[0xf4];
    float friction;
    float getFriction() const { return friction; }
    void setFriction(float f);
};
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    Primitive* getPrimitive() const { return primitive; }
};
class Humanoid {
public:
    PartInstance* getHead();
    PartInstance* getTorso();
};
class B1 { public: virtual ~B1(); };
class B2 { public: virtual void b2(); };
class HumanoidState : public B1, public B2 {
public:
    HumanoidState(Humanoid* h, int a);
    virtual ~HumanoidState();
    char pad[0x48];
};
class State : public HumanoidState {
public:
    State(Humanoid* h, int a);
    virtual void b2();
    float torsoFriction;
    float headFriction;
    struct V3 { float x, y, z; V3() : x(0), y(0), z(0) {} } v;
};
State::State(Humanoid* h, int a) : HumanoidState(h, a), torsoFriction(0), headFriction(0)
{
    if (PartInstance* head = h->getHead()) {
        headFriction = head->getPrimitive()->getFriction();
        head->getPrimitive()->setFriction(0.0f);
    }
    if (PartInstance* torso = h->getTorso()) {
        torsoFriction = torso->getPrimitive()->getFriction();
        torso->getPrimitive()->setFriction(0.0f);
    }
}
}
