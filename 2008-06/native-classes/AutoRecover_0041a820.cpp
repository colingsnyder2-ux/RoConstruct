// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the boost headers are not available here, so a minimal boost::function layout is reproduced locally.
// INFERRED: the vendor namespace nesting, template arguments and boost::function layout are guessed from the disassembly.
#include <new>

namespace RBX { class Instance; }

namespace boost {

template<class T> class shared_ptr;

namespace detail { namespace function {

union __declspec(align(8)) function_buffer {
    void* obj_ptr;
    char data[8];
};

enum functor_manager_operation_type { clone_functor_tag = 0, destroy_functor_tag = 2 };

struct vtable_base {
    void (*manager)(const function_buffer& in, function_buffer& out, functor_manager_operation_type op);
};

}}

struct function_base_impl {
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;

    function_base_impl() : vtable(0) {}
    ~function_base_impl() {
        if (vtable) {
            vtable->manager(functor, functor, detail::function::destroy_functor_tag);
            vtable = 0;
        }
    }
};

template<class Sig, class Alloc>
struct function : function_base_impl {
    function() {}
    function(const function& f) : function_base_impl() {
        this->assign_to_own(f);
    }
    void assign_to_own(const function& f) {
        if (f.vtable) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};

class any {
public:
    struct placeholder {
        virtual ~placeholder() {}
    };

    template<class ValueType>
    struct holder : placeholder {
        holder(const ValueType& value) : held(value) {}
        virtual ~holder() {}
        ValueType held;
    };
};

}

typedef boost::function<void(boost::shared_ptr<RBX::Instance>), void> FlagStandFn;
typedef boost::any::holder<FlagStandFn> FlagStandHolder;

extern "C" FlagStandHolder* __fastcall fn_0041a820(FlagStandHolder* self, int unusedEdx, const FlagStandFn* f)
{
    return new (self) FlagStandHolder(*f);
}
