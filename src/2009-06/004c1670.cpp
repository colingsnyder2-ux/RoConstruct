// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[12]; };
}}
struct Member { char d[0x2c]; Member(const Member&); ~Member(); };
struct List { Member a1_; bool a2_; };
struct Bound { void* f_; List l_; };
class function_base { public: void* vtable; detail::function::function_buffer functor; };
template<class R> class function0 : public function_base {
public:
    template<class Functor> function0(Functor f, int = 0);
};
template<class Sig> class function;
template<class R> class function<R()> : public function0<R> {
public:
    template<class Functor> function(Functor f, int = 0) : function0<R>(f) {}
};
typedef function<void()> F0;
template F0::function(Bound, int);
}
