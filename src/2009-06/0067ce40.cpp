// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Joint { public: virtual ~Joint(); };
class GlueJoint : public Joint { public: GlueJoint(); char pad[0x100 - 4]; };
struct B0 { virtual ~B0(); char pad[0x10]; };
struct B1 { virtual ~B1(); };
struct B2 { virtual ~B2(); int x; };
struct B3 { virtual ~B3(); char pad[0x68]; };
struct B4 { virtual ~B4(); };
class JointInstance : public B0, public B1, public B2, public B3, public B4 {
public:
    JointInstance(Joint* joint);
};
class Glue : public JointInstance {
public:
    Glue();
    virtual ~Glue();
};
Glue::Glue() : JointInstance(new GlueJoint())
{
}
}
