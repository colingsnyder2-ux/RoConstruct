// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were supplied, so the boost::function / boost::any layouts below are
// reconstructed from the disassembly. The holder vptr is at +0, the function object at +8
// (8-byte aligned), its vtable pointer at held+0 and its functor buffer at held+8.
// INFERRED: the target is reached through an extern "C" fn_ wrapper that placement-news the
// holder into 'self'. The holder constructor is expected to be inlined into it.

namespace RBX { class Instance; }

namespace boost {

template <class T> class shared_ptr { T* px; void* pn; };

namespace detail { namespace function {

enum functor_manager_operation_type { clone_functor_tag };

union __declspec(align(8)) function_buffer {
    void* obj_ptr;
    char data[16];
};

struct vtable_base {
    void (*manager)(const function_buffer& in, function_buffer& out,
                    functor_manager_operation_type op);
    // INFERRED: invoker lives in the vtable (not touched by the copy)
    void* invoker;
};

}}

template <class Sig, class Alloc> class function;

template <class Alloc>
class function<void(shared_ptr<RBX::Instance>), Alloc> {
public:
    __forceinline function(const function& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, detail::function::clone_functor_tag);
        }
    }
    ~function()
    {
        if (vtable) {
            vtable->manager(functor, functor, (detail::function::functor_manager_operation_type)0);
            vtable = 0;
        }
    }
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
};

}

namespace std { template <class T> class allocator; template <> class allocator<void> {}; }

void* operator new(unsigned int);

// local placement form without a null check (no throw() spec)
inline void* operator new(unsigned int, void* p, int) { return p; }

namespace boost {

class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
        virtual placeholder* clone() const = 0;
    };

    template <class ValueType>
    class holder : public placeholder {
    public:
        __forceinline holder(const ValueType& value) : held(value) {}
        virtual placeholder* clone() const { return new holder(held); }
        ValueType held;
    };
};

}

typedef boost::function<void(boost::shared_ptr<RBX::Instance>), std::allocator<void> > FlagStandFunction;
typedef boost::any::holder<FlagStandFunction> FlagStandHolder;

extern "C" FlagStandHolder* __fastcall fn_0048dc30(FlagStandHolder* self, int unusedEdx, const FlagStandFunction* f)
{
    return new (self, 0) FlagStandHolder(*f);
}
