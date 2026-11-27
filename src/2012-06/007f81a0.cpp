// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace mpl { template<bool C> struct bool_ {}; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align_; char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
};
} }
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { this->assign_to_own(f); }
    ~function0() { clear(); }
    void clear() {
        if (vtable) {
            if (vtable->manager)
                vtable->manager(this->functor, this->functor, detail::function::destroy_functor_tag);
            vtable = 0;
        }
    }
    void assign_to_own(const function0& f) {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct storage1 { A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; };
template<class A1, class A2> class list2 : private storage2<A1, A2> {};
template<class R, class F, class L> class bind_t {
public:
    F f_;
    L l_;
};
}
namespace detail { namespace function {
template<class R> struct basic_vtable0 {
    template<typename FunctionObj>
    void assign_functor(FunctionObj f, function_buffer& functor, mpl::bool_<false>)
    {
        functor.obj_ptr = new FunctionObj(f);
    }
};
} }
}
struct BoundFirst { double storage[5]; BoundFirst(const BoundFirst& other); ~BoundFirst(); };
typedef boost::_bi::list2<boost::_bi::value<BoundFirst>, boost::_bi::value<boost::function0<int> > > BoundList;
typedef boost::_bi::bind_t<void, void (*)(), BoundList> BT;
template void boost::detail::function::basic_vtable0<void>::assign_functor<BT>(BT, boost::detail::function::function_buffer&, boost::mpl::bool_<false>);