// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Joint { public: virtual ~Joint(); char jpad[0x1c]; };
class Second { public: virtual void s(); };
class RotateJoint : public Joint, public Second { public: RotateJoint(); char pad2[0xd4 - 0x24]; };
class __declspec(novtable) MidJoint : public RotateJoint {
public:
    int value;
    float angle;
    MidJoint() { angle = 0.0f; value = 0; }
};
class RotateVJoint : public MidJoint {
public:
    virtual ~RotateVJoint();
};
struct B0 { virtual ~B0(); char pad[0x10]; };
struct B1 { virtual ~B1(); };
struct B2 { virtual ~B2(); int x; };
struct B3 { virtual ~B3(); char pad[0x68]; };
struct B4 { virtual ~B4(); };
class JointInstance : public B0, public B1, public B2, public B3, public B4 {
public:
    JointInstance(Joint* joint);
};
class RotateV : public JointInstance {
public:
    RotateV();
    virtual ~RotateV();
};
RotateV::RotateV() : JointInstance(new RotateVJoint())
{
}
}
