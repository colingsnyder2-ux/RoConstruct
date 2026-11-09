// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    void release();
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    sp_counted_base* pi_;
};
}
template<class T> class shared_ptr {
public:
    shared_ptr() : px(0), pn() {}
    T* px;
    detail::shared_count pn;
};
}
namespace RBX {
class Holder { public: Holder() : p(0) {} ~Holder(); void* p; };
struct ExeVA { virtual ~ExeVA(); char a[0x10]; };
struct ExeVB { virtual ~ExeVB(); };
struct ExeVC { virtual ~ExeVC(); int c; };
struct ExeVD { virtual ~ExeVD(); char d[0x68]; };
class Instance : public ExeVA, public ExeVB, public ExeVC, public ExeVD {
public:
    void setName(const std::string& value);
};
class ValueBase : public Instance {
public:
    ValueBase();
    ~ValueBase();
};
class ObjectValue : public ValueBase {
public:
    ObjectValue();
    ~ObjectValue();
private:
    boost::shared_ptr<Instance> value;
    Holder unk;
};
ObjectValue::ObjectValue()
{
    setName("Value");
}
}
