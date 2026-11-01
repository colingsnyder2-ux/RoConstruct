// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Joint;
struct ExeB0 { virtual void f0(); char p[0x10]; };
struct ExeB14 { virtual void f1(); };
struct ExeB18 { virtual void f2(); int x; };
struct ExeB20 { virtual void f3(); char p[0x68]; };
struct ExeB8c { virtual void f4(); };
class JointInstance : public ExeB0, public ExeB14, public ExeB18, public ExeB20, public ExeB8c {
public:
    JointInstance(Joint* joint);
    ~JointInstance();
    void setName(const std::string& name);
};
class Snap : public JointInstance {
public:
    Snap(Joint* joint);
};
Snap::Snap(Joint* joint) : JointInstance(joint)
{
    setName("Snap");
}
}
