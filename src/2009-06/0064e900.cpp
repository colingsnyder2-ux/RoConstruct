// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
struct BT { bool b; BT() : b(true) {} };
struct NP { void* p; NP() : p(0) {} };
namespace rbx { namespace signals {
class connection {
public:
	class slot : boost::noncopyable_::noncopyable, RBX::Countable<slot> {
	public:
		slot() : def(gDefault) {}
		virtual ~slot();
		BT connected;
		NP next;
		void* def;
	};
};
union function_buffer { void* obj_ptr; double align; char buf[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
	void (*manager)(const function_buffer& in, function_buffer& out, functor_manager_operation_type op);
};
struct function_base {
	vtable_base* vtable;
	function_buffer functor;
	function_base() : vtable(0) {}
};
template<class Sig> struct function : function_base {
	~function() {
		if (vtable) {
			void (*m)(const function_buffer&, function_buffer&, functor_manager_operation_type) = vtable->manager;
			if (m) m(functor, functor, destroy_functor_tag);
		}
	}
	__forceinline function(const function& f) {
		if (f.vtable) {
			vtable = f.vtable;
			vtable->manager(f.functor, functor, clone_functor_tag);
		}
	}
};
template<class Sig> class signal {
public:
	class slot : public connection::slot {
	public:
		slot(function<Sig> f, void* owner) : connection::slot(), owner(owner), func(f), a(0), b(0), c(0), d(0) {}
		virtual ~slot();
		void* owner;
		function<Sig> func;
		int a, b, c, d;
	};
};
template class signal<void(boost::shared_ptr<RBX::Instance>, float)>::slot;
} }
