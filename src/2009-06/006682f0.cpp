// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
namespace boost {
namespace detail { class shared_count { public: void* pi_; shared_count() : pi_(0) {} ~shared_count(); }; }
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    ~shared_ptr();
};
}
namespace RBX {
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class DescribedBase { public: virtual ~DescribedBase(); int descriptor; };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public DescribedBase, public Debugable {
public:
    Instance();
    virtual ~Instance();
    void setName(const std::string&);
    char pad[0x8c - 0x28];
};
class __declspec(novtable) SecondBase { public: virtual void onChanged() = 0; };
class Selection;
class PartInstance;
template<class T> class FilteredSelection : public Instance, public SecondBase {
    boost::shared_ptr<Selection> selection;
    std::vector<T*> items;
public:
    FilteredSelection() { setName("FilteredSelection"); }
};
template class FilteredSelection<PartInstance>;
}
