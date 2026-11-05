// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
namespace RBX {
class A0 { public: virtual ~A0(); char a0[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual void a2(); char a2p[4]; };
class A3 { public: virtual void a3(); char a3p[0x68]; };
class Instance : public A0, public A1, public A2, public A3 {
public:
    Instance();
    virtual ~Instance();
    void setName(const std::string& name);
};
class __declspec(novtable) IListener { public: virtual void onEvent(); };
template<class T> class shared_ptr {
public:
    struct shared_count { void* pi_; shared_count() : pi_(0) {} ~shared_count(); };
    T* px; shared_count pn;
    shared_ptr() : px(0), pn() {}
};
class FilteredSelection : public Instance, public IListener {
public:
    FilteredSelection();
    shared_ptr<Instance> selection;
    std::vector<Instance*> items;
};
FilteredSelection::FilteredSelection()
{
    setName("FilteredSelection");
}
}
