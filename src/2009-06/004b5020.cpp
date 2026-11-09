// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance;
template<class T> class ExeVector {
public:
    void* aux[3];
    T* first; T* last; T* end_;
    unsigned size() const { return last - first; }
    const T& operator[](unsigned i) const { if (!(i < size())) _invalid_parameter_noinfo(); return first[i]; }
};
class Instance {
public:
    virtual ~Instance();
    char pad[0x48];
    ExeVector<boost::shared_ptr<Instance> >* children;
    unsigned numChildren() const;
    Instance* getChild(unsigned i) { return (*children)[i].get(); }
    boost::shared_ptr<Instance> shared_from_this();
    void setParent(Instance* p);
};
void moveChildren(Instance* from, Instance* to)
{
    for (unsigned i = 0; i < from->numChildren(); ++i)
    {
        boost::shared_ptr<Instance> c = from->getChild(i)->shared_from_this();
        c->setParent(to);
    }
}
}
