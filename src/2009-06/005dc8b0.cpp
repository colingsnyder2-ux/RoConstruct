// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer {
    void* obj_ptr;
    void (*func_ptr)();
    double align;
    char data[0x18];
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}}
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { assign_to_own(f); }
    ~function0() { if (vtable) vtable->clear(functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
namespace RBX {
struct Tag {};
struct Item {
    int key;
    boost::function0<void> f;
};
class Queue {
public:
    void create(Item item, Item** out, Tag);
};
void Queue::create(Item item, Item** out, Tag)
{
    *out = new Item(item);
}
}
