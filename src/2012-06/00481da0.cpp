// from server: 99% by tajop
class type_info {
public:
    bool operator==(const type_info& rhs) const;
};

typedef bool (type_info::*type_info_eq_fn)(const type_info& rhs) const;
extern type_info_eq_fn imp_type_info_eq;

struct Inner {
    Inner(const Inner& o);
    ~Inner();
    int d[0x12];
};

struct Empty {};

struct Functor {
    int fn;
    Empty e;
    Inner args;
};

union function_buffer {
    void* obj_ptr;
    struct {
        const type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
};

enum functor_manager_operation_type {
    clone_functor_tag,
    move_functor_tag,
    destroy_functor_tag,
    check_functor_type_tag,
    get_functor_type_tag
};

struct functor_manager {
    static void manage(const function_buffer& in_buffer, function_buffer& out_buffer,
                       functor_manager_operation_type op);
};

void functor_manager::manage(const function_buffer& in_buffer, function_buffer& out_buffer,
                             functor_manager_operation_type op)
{
    if (op == clone_functor_tag) {
        const Functor* f = static_cast<const Functor*>(in_buffer.obj_ptr);
        Functor* new_f = new Functor(*f);
        out_buffer.obj_ptr = new_f;
    } else if (op == move_functor_tag) {
        out_buffer.obj_ptr = in_buffer.obj_ptr;
        const_cast<function_buffer&>(in_buffer).obj_ptr = 0;
    } else if (op == destroy_functor_tag) {
        Functor* f = static_cast<Functor*>(out_buffer.obj_ptr);
        delete f;
        out_buffer.obj_ptr = 0;
    } else if (op == check_functor_type_tag) {
        if (((*out_buffer.type.type).*imp_type_info_eq)(typeid(Functor)))
            out_buffer.obj_ptr = in_buffer.obj_ptr;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &typeid(Functor);
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
