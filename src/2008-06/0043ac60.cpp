// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <map>
#include <intrin.h>

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
template <class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr() { if (pn) pn->release(); }
    T* get() const { return px; }
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class Script : public Instance {
};
template <class T> boost::shared_ptr<T> shared_from(T* p);
}


template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_(const T* p) { m_pszData = 0; }
    __declspec(noinline) CStringT_(const CStringT_& p) { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<wchar_t>;
typedef CStringT_<wchar_t> CString;

struct KeyBase { int x; };
struct KeyDerived : KeyBase {};
typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;
typedef std::map<KeyBase*, Instances> InstanceMap;

class CXTPPropertyGridItem {
public:
    virtual ~CXTPPropertyGridItem();
    void SetValue(CString value);
    void SetHidden(int hidden);
};

class HVCXTPPropertyGridItemEnum : public CXTPPropertyGridItem {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); 
    
    virtual void setValue(const int& value);
    virtual bool same(const int& a, const int& b);
    int getValue(RBX::Instance* instance);

    class XItem {
    public:
        void* vptr;
        std::vector<KeyDerived*> keys;
        void update(InstanceMap& instances);
    };
    char pad[0x100];
    XItem m_xItem;
};

#define OUTER ((HVCXTPPropertyGridItemEnum*)((char*)this - 0x10c))

void HVCXTPPropertyGridItemEnum::XItem::update(InstanceMap& instances)
{
    bool found = false;
    InstanceMap::iterator mapEnd = instances.end();
    int value;
    for (std::vector<KeyDerived*>::iterator it = keys.begin(), end = keys.end(); it != end; ++it) {
        InstanceMap::iterator f = instances.find(*it);
        if (f != mapEnd) {
            for (Instances::iterator j = f->second.begin(), jEnd = f->second.end(); j != jEnd; ++j) {
                if (!found) {
                    value = OUTER->getValue(j->get());
                    OUTER->setValue(value);
                } else {
                    int other = OUTER->getValue(j->get());
                    if (!OUTER->same(value, other)) {
                        OUTER->SetValue(CString(L""));
                        OUTER->SetHidden(0);
                        return;
                    }
                }
                found = true;
            }
        }
    }
    OUTER->SetHidden(!found);
}
