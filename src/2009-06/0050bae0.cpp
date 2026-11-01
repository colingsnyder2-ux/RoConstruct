// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Mechanism { public: ~Mechanism(); char pad[4]; };
class Body {
public:
    virtual ~Body();
    char pad[0x24];
};
class __declspec(novtable) Assembly : public Body {
public:
    Mechanism mechanism;
    virtual ~Assembly() {}
    Assembly* scalarDeletingDestructor(unsigned int flags);
};
Assembly* Assembly::scalarDeletingDestructor(unsigned int flags)
{
    this->Assembly::~Assembly();
    if (flags & 1)
        operator delete(this);
    return this;
}
}
