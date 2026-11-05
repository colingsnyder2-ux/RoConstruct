// from server: 100% by EspClaude
// roc 2007-08 0048dae0  XmlNameValuePair::setValue(RBX::InstanceHandle) (openrbx v8xml/XmlElement.h; 2007 value union is 4 bytes)
// roc-flags: /O2 /GS /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
};
}
namespace RBX {
class Name;
class Instance;
class InstanceHandle {
    boost::shared_ptr<Instance> target;
};
}
class XmlNameValuePair {
public:
    enum ValueType { NONE = 0, NAME = 1, STRING = 2, CONTENTID = 3, BOOL = 4, INT = 5, UINT = 6, FLOAT = 7, HANDLE = 8 };
    void setValue(RBX::InstanceHandle value);
private:
    void clearValue() const;
    const RBX::Name& tag;
    mutable ValueType valueType;
    union {
        mutable int intValue;
        mutable RBX::InstanceHandle* handleValue;
    };
};
void XmlNameValuePair::setValue(RBX::InstanceHandle value)
{
    clearValue();
    handleValue = new RBX::InstanceHandle(value);
    valueType = HANDLE;
}
