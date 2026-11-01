// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive { public: void setValue(float v); };
class PartInstance { public: char pad[0x118]; Primitive* primitive; Primitive* getPrimitive() const { return primitive; } };
class Humanoid { public: PartInstance* getHead(); PartInstance* getTorso(); };
class A { public: virtual ~A(); };
class B { public: virtual ~B(); };
class Base : public A, public B {
public:
    virtual ~Base();
    Humanoid* getHumanoid();
    char pad[0x50 - 8];
};
class Derived : public Base {
public:
    float torsoValue;
    float headValue;
    virtual ~Derived();
};
Derived::~Derived()
{
    if (PartInstance* head = getHumanoid()->getHead()) {
        if (headValue > 0.0f)
            head->getPrimitive()->setValue(headValue);
    }
    if (PartInstance* torso = getHumanoid()->getTorso()) {
        if (torsoValue > 0.0f)
            torso->getPrimitive()->setValue(torsoValue);
    }
}
}
