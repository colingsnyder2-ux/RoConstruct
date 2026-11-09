// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
union function_buffer { void* obj_ptr; double align; char buf[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
	void (*manager)(const function_buffer& in, function_buffer& out, functor_manager_operation_type op);
};
struct function_base {
	vtable_base* vtable;
	mutable function_buffer functor;
	function_base() : vtable(0) {}
};
struct function : function_base {
	~function() {
		if (vtable) {
			void (*m)(const function_buffer&, function_buffer&, functor_manager_operation_type) = vtable->manager;
			if (m) m(functor, functor, destroy_functor_tag);
		}
	}
	function(const function& f) {
		if (f.vtable) {
			vtable = f.vtable;
			vtable->manager(f.functor, functor, clone_functor_tag);
		}
	}
};
struct Item { int id; function f; };
struct Tag {};
class Owner {
public:
	bool doIt(Item item, int x, Tag t);
	bool run(Item item, int x);
};
bool Owner::run(Item item, int x)
{
	return doIt(item, x, Tag());
}
