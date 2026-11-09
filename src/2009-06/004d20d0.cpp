// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace boost { template<class T> class shared_ptr { T* p; void* c; }; namespace noncopyable_ { class noncopyable { protected: noncopyable() {} }; } }
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
		slot() : connected(true), def(gDefault) {}
		virtual ~slot();
		volatile bool connected;
		NP next;
		void* def;
	};
};
union function_buffer { void* obj_ptr; double align_; char data[0x18]; };
typedef void (*manager_type)(const function_buffer&, function_buffer&, int);
struct vtable_base { manager_type manager; };
struct function_base {
	vtable_base* vtable;
	mutable function_buffer functor;
	function_base() : vtable(0) {}
};
template<class Sig> struct function : function_base {
	__forceinline function(const function& f) { if (f.vtable) { vtable = f.vtable; f.vtable->manager(f.functor, functor, 0); } }
	~function() { if (vtable) { manager_type m = vtable->manager; if (m) m(functor, functor, 2); } }
};
template<class Sig> class signal {
public:
	class slot : public connection::slot {
	public:
		slot(function<Sig> f, void* o) : owner(o), func(f), a(0), b(0), c(0), d(0) {}
		virtual ~slot();
		void* owner;
		function<Sig> func;
		int a, b, c, d;
	};
};
template class signal<void(int)>::slot;
} }
