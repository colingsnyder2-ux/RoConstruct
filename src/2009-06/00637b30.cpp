// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class any;
template<typename ValueType> ValueType any_cast(any& operand);
template<typename ValueType> inline ValueType any_cast(const any& operand)
{
    return any_cast<const ValueType&>(const_cast<any&>(operand));
}
}
namespace RBX { class ScriptContext; }
template boost::shared_ptr<RBX::ScriptContext> boost::any_cast<boost::shared_ptr<RBX::ScriptContext> >(const boost::any&);
