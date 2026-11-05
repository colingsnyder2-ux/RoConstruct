// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class weak_ptr { public: T* px; void* pn; };
namespace mpl { template<bool C> struct bool_ { }; typedef bool_<false> false_; }
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2> struct storage2 { A1 a1_; A2 a2_; };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
	A3 a3_;
	storage3(const storage3& o);
	~storage3();
};
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> { A4 a4_; };
template<class A1, class A2, class A3, class A4> struct list4 : public storage4<A1, A2, A3, A4> { };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align_; char data[16]; };
struct function_obj_tag {};
inline bool has_empty_target(...) { return false; }
template<class R> struct basic_vtable0 {
	void* manager;
	void* invoker;
	template<class F> bool assign_to(F f, function_buffer& functor, function_obj_tag);
	template<class F> void assign_functor(F f, function_buffer& functor, mpl::false_);
};
template<class R> template<class F> bool basic_vtable0<R>::assign_to(F f, function_buffer& functor, function_obj_tag)
{
	if (!has_empty_target(&f)) {
		assign_functor(f, functor, mpl::false_());
		return true;
	} else {
		return false;
	}
}
}}
}
namespace RBX { class Instance; namespace Network { class Player; } }
typedef boost::_bi::bind_t<void, void (*)(), boost::_bi::list4<boost::_bi::value<boost::weak_ptr<RBX::Network::Player> >, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<std::string>, boost::_bi::value<bool> > > BindT;
template bool boost::detail::function::basic_vtable0<void>::assign_to<BindT>(BindT, boost::detail::function::function_buffer&, boost::detail::function::function_obj_tag);
