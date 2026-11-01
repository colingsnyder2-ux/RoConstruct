// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
struct function_base {
	void* vtable;
	union { __declspec(align(8)) char buf[0x18]; } functor;
	function_base() : vtable(0) {}
};
template<class Sig> struct function : function_base {
	template<class F> function(F f) { assign_to(f); }
	template<class F> void assign_to(F f) throw();
};
struct Functor { void* a; void* b; };
template<class Sig> class signal {
public:
	class slot : public connection::slot {
	public:
		slot(Functor f, void* owner) : connection::slot(owner), func(f), a(0), b(0), c(0), d(0) {}
		virtual ~slot();
		function<Sig> func;
		int a, b, c, d;
	};
};
namespace Ref { class PropertyDescriptor; }
template class signal<void(const Ref::PropertyDescriptor*)>::slot;
} }
