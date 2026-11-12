// from server: 87% by EspClaude
// from server: 50% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_6f90b88611fad3e5.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 0x4b8190: boost::weak_ptr<T>::lock() (boost 1.34 shape),
// returned through the hidden result pointer (ret 4). weak_ptr layout px +0, pn +4;
// sp_counted_base::use_count_ at +4 (read off the target's [eax + 4] test).
#include <exception>

namespace roc_boost {

class bad_weak_ptr : public std::exception
{
public:
    virtual char const * what() const throw() { return "tr1::bad_weak_ptr"; }
};

class sp_counted_base
{
    long use_count_;
    long weak_count_;
public:
    sp_counted_base();
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    long use_count() const { return static_cast<long const volatile &>( use_count_ ); }
};

class weak_count;

class shared_count
{
    sp_counted_base * pi_;
    friend class weak_count;
public:
    shared_count(): pi_(0) {}
    explicit shared_count(weak_count const & r);
    ~shared_count();
};

class weak_count
{
    sp_counted_base * pi_;
    friend class shared_count;
public:
    long use_count() const { return pi_ != 0? pi_->use_count(): 0; }
};

template<class T> class weak_ptr;

template<class T> class shared_ptr
{
public:
    shared_ptr(): px(0), pn() {}
    template<class Y> explicit shared_ptr(weak_ptr<Y> const & r): pn(r.pn)
    {
        px = r.px;
    }
    T * px;
    shared_count pn;
};

template<class T> class weak_ptr
{
public:
    shared_ptr<T> lock() const
    {
        if(expired())
        {
            return shared_ptr<T>();
        }
        try
        {
            return shared_ptr<T>(*this);
        }
        catch(bad_weak_ptr const &)
        {
            return shared_ptr<T>();
        }
    }
    bool expired() const { return pn.use_count() == 0; }
    T * px;
    weak_count pn;
};

}

struct RocExposed04b8190;
template class roc_boost::weak_ptr<RocExposed04b8190>;
