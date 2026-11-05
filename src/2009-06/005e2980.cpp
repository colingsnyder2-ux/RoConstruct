// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
union function_buffer { void* obj; __declspec(align(8)) char data[0x18]; };
typedef void (*manager_type)(const function_buffer&, function_buffer&, int);
struct vtable_base {
	manager_type manager;
	void clear(function_buffer& functor) { if (manager) manager(functor, functor, 2); }
};
struct function_base {
	vtable_base* vtable;
	function_buffer functor;
	~function_base() { if (vtable) { vtable->clear(functor); vtable = 0; } }
};
struct Item {
	std::string name;
	function_base func;
	~Item();
};
Item::~Item() {}
