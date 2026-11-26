// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>

namespace RBX { class Instance; }
typedef bool (*Func)(RBX::Instance*);
union function_buffer {
    void *obj_ptr;
    struct { const std::type_info *type; bool const_qualified; bool volatile_qualified; } type;
    char data[8];
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
void manage(function_buffer &in_buffer, function_buffer &out_buffer, functor_manager_operation_type op)
{
    if (op == clone_functor_tag) {
        out_buffer.obj_ptr = in_buffer.obj_ptr;
    } else if (op == move_functor_tag) {
        out_buffer.obj_ptr = in_buffer.obj_ptr; in_buffer.obj_ptr = 0;
    } else if (op == destroy_functor_tag) {
        out_buffer.obj_ptr = 0;
    } else if (op == check_functor_type_tag) {
        const std::type_info &check_type = *out_buffer.type.type;
        out_buffer.obj_ptr = (check_type == typeid(Func)) ? &in_buffer.data : 0;
    } else {
        out_buffer.type.type = &typeid(Func);
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
