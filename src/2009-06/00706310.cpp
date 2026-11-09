// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost { namespace detail { namespace function {
union function_buffer { void* obj_ptr; struct { void* a; void* b; void* c; } bound; __declspec(align(8)) char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
	void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
	void clear(function_buffer& functor) { if (manager) manager(functor, functor, destroy_functor_tag); }
};
} }
class function_base {
public:
	detail::function::vtable_base* vtable;
	mutable detail::function::function_buffer functor;
};
class function0 : public function_base {
public:
	~function0() { clear(); }
	void clear() { if (vtable) { vtable->clear(this->functor); vtable = 0; } }
};
}
struct S {
	boost::function0 f;
	std::string s;
	~S();
};
S::~S() {}
