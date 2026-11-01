// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class weak_count {
public:
	sp_counted_base* pi_;
	weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2> struct storage2 { A1 a1_; A2 a2_; };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
	A3 a3_;
	storage3(const storage3& o);
};
template<class A1, class A2, class A3> storage3<A1,A2,A3>::storage3(const storage3& o) : storage2<A1, A2>(o), a3_(o.a3_) {}
}
}
namespace RBX { class Instance; namespace Network { class Player; } }
template struct boost::_bi::storage3<boost::_bi::value<boost::weak_ptr<RBX::Network::Player> >, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<std::string> >;
