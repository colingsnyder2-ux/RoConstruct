// from server: 90% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace boost { class Instance; template<class T> class shared_ptr { T* p; void* c; }; namespace noncopyable_ { class noncopyable { protected: noncopyable() {} }; } }
namespace RBX {
class Instance;
template<class T> class Countable {
	static long count;
public:
	Countable() { InterlockedIncrement(&count); }
};
}
extern void* const gDefault;
struct NP { void* p; NP() : p(0) {} };
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[0x18]; double d; };
struct vtable_base { void* manager; };
template<class R, class Alloc> struct basic_vtable1 {
    vtable_base base;
    void* invoker;
    template<class F> bool assign_to(F f, function_buffer& functor) throw();
};
}}
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base()  {}
};
template<class R, class T0> class function1 : public function_base {
public:
    typedef detail::function::basic_vtable1<R, std::allocator<void> > vtable_type;
    template<class Functor> function1(Functor f, int = 0) : function_base() { this->assign_to(f); }
    template<class Functor> void assign_to(Functor f) {
        static vtable_type stored_vtable = { { 0 }, 0 };
        if (stored_vtable.assign_to(f, functor)) vtable = &stored_vtable.base;
        else vtable = 0;
    }
};
template<class Sig> class function;
template<class R, class A> class function<R(A)> : public function1<R, A> {
public:
    template<class Functor> function(Functor f, int = 0) : function1<R, A>(f) {}
};
}
namespace rbx { namespace signals {
class connection {
public:
	class slot : boost::noncopyable_::noncopyable, RBX::Countable<slot> {
	public:
		slot(void* owner) : connected(true), def(gDefault), owner(owner) {}
		virtual ~slot();
		bool connected;
		NP next;
		void* def;
		void* owner;
	};
};
struct Functor { int a, b, c, d; };
template<class Sig> class signal {
public:
	class slot : public connection::slot {
	public:
		slot(Functor f, void* owner) : connection::slot(owner), func(f), a(0), b(0), c(0), d(0) {}
		virtual ~slot();
		boost::function<Sig> func;
		int a, b, c, d;
	};
};
template class signal<void(boost::shared_ptr<RBX::Instance>)>::slot;
} }
