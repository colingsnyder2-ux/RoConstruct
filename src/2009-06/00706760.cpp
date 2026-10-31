// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { template<class T> class allocator; }
namespace boost {
namespace mpl { template<bool B> struct bool_ { }; typedef bool_<false> false_; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; void (*func_ptr)(); char data; };
template<class R, class Allocator> struct basic_vtable0 {
private:
    template<typename FunctionObj>
    void assign_functor(FunctionObj f, function_buffer& functor, mpl::false_)
    {
        functor.obj_ptr = new FunctionObj(f);
    }
};
}}
class function_base { public: int vtable; };
template<class T> class shared_ptr;
template<class R, class A> class function0;
namespace _bi {
template<class T> class value;
template<class A1, class A2> struct storage2 {
    storage2(const storage2&);
    ~storage2();
    double d[5];
};
template<class A1, class A2> class list2 : private storage2<A1, A2> {
};
template<class R, class F, class L> class bind_t {
public:
    F f_;
    L l_;
};
}
}
namespace RBX { class worker_thread { public: enum work_result { done, more }; struct data; }; }
typedef boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> > WF;
typedef boost::shared_ptr<RBX::worker_thread::data> DP;
typedef boost::_bi::bind_t<void, void (*)(DP, const WF&), boost::_bi::list2<boost::_bi::value<DP>, boost::_bi::value<WF> > > BT;
template void boost::detail::function::basic_vtable0<void, std::allocator<boost::function_base> >::assign_functor<BT>(BT, boost::detail::function::function_buffer&, boost::mpl::false_);
