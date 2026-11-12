// from server: 86% by EspClaude
// roc 2007-08 00586e70  unit: RBX::FillTool  size: 402 bytes
// Rewritten from the target disassembly (thiscall, 1 stack arg, returns 0).
#include <string>

namespace RBX {

struct Name {
    int id;                 // string at +4 (target: add eax, 4 before copy-ctor)
    std::string str;
};

struct Descriptor;
extern Descriptor propDesc;     // pushed as data address
extern int someGlobal;          // [0x8a2838] value
extern int defaultField14;      // copied into new object +0x14
extern Name toolName;           // pushed as data address

struct DescribedBase { virtual void db(); };

struct Property {
    const Descriptor* desc;
    DescribedBase* instance;
    Property(const Descriptor& d, DescribedBase* i) : desc(&d), instance(i) {}
};

struct InstanceA { virtual void ia(); };
struct Target : public InstanceA, public DescribedBase {
    void setSomething(int v);
};

struct VBase {
    VBase() {}
    virtual void vb();
};

struct Ptr2 {
    void* px;
    void* pn;
    Ptr2() : px(0), pn(0) {}
};

struct ActionBase : virtual public VBase {
    ActionBase() : f10(0), f14(defaultField14), f18(0) {}
    virtual void ab();
    void bind(const Property& p);
    Ptr2 f8;
    int f10;
    int f14;
    int f18;
    int f1c;
    Ptr2 f20;
};

struct ActionA : public ActionBase {
    ActionA() {}
    virtual void ab();
};

struct ActionB : public ActionBase {
    ActionB() {}
    virtual void ab();
};

struct Runner {
    virtual void r0();
    virtual void run(bool b);
    void add(std::string name, ActionBase* a, ActionBase* b);
};

struct Camera {
    void step(int n);
};

struct Workspace;
struct View {
    char pad[0x310];
    Runner* runner;
};

Camera* getCamera(View* v);

class FillTool {
public:
    virtual const Name& getName();
    Target* find(Workspace* w, int flags, const Name& name);
    int doIt(Workspace* workspace);
    char pad[0x14];
    View* view;
};

int FillTool::doIt(Workspace* workspace)
{
    Target* p = find(workspace, 0, toolName);
    if (p == 0)
        return 0;

    ActionA* a = new ActionA();
    a->bind(Property(propDesc, p));
    p->setSomething(someGlobal);
    getCamera(view)->step(10);

    ActionB* b = new ActionB();
    b->bind(Property(propDesc, p));

    Runner* r = view->runner;
    const Name& n = getName();
    r->add(n.str, a, b);
    view->runner->run(true);
    return 0;
}

}
