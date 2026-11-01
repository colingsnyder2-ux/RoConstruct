// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class DescribedBase { public: virtual ~DescribedBase(); };
class Pad18 { public: virtual void p(); char x[0x14]; };
class Instance : public Pad18, public DescribedBase { };
}
struct BoolSetter {
    void* vptr_;
    int x;
    void (RBX::Instance::*set)(bool);
    void setValue(RBX::DescribedBase* obj, const bool& value) const;
};
void BoolSetter::setValue(RBX::DescribedBase* obj, const bool& value) const
{
    (static_cast<RBX::Instance*>(obj)->*set)(value);
}
