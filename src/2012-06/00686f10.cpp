// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /GR
namespace RBX {
class Instance { public: virtual ~Instance(); };
class ICharacterSubject { public: virtual ~ICharacterSubject(); bool g(); };
}
struct S
{
    char padding[0x14c];
    RBX::Instance *subject;
    bool f();
};
bool S::f()
{
    RBX::Instance *i = subject;
    if (RBX::ICharacterSubject *c = dynamic_cast<RBX::ICharacterSubject *>(i))
        return c->g();
    return false;
}