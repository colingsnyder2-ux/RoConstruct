// from server: 100% by Xemicl
// roc 2012-06 0074a2b0  unit: RBX::ContentProvider  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0074a2b0
//
// 0074a2b0  64a100000000         mov eax, dword ptr fs:[0]
// 0074a2b6  6aff                 push -1
// 0074a2b8  6838cfaa00           push 0xaacf38
// 0074a2bd  50                   push eax
// 0074a2be  64892500000000       mov dword ptr fs:[0], esp
// 0074a2c5  56                   push esi
// 0074a2c6  8bf1                 mov esi, ecx
// 0074a2c8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0074a2cc  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0074a2d4  c70600000000         mov dword ptr [esi], 0
// 0074a2da  85c0                 test eax, eax
// 0074a2dc  7418                 je 0x74a2f6
// 0074a2de  6a00                 push 0
// 0074a2e0  8d4e08               lea ecx, [esi + 8]
// 0074a2e3  51                   push ecx
// 0074a2e4  8d542424             lea edx, [esp + 0x24]
// 0074a2e8  8906                 mov dword ptr [esi], eax
// 0074a2ea  8b00                 mov eax, dword ptr [eax]
// 0074a2ec  52                   push edx
// 0074a2ed  ffd0                 call eax
// 0074a2ef  8b442420             mov eax, dword ptr [esp + 0x20]
// 0074a2f3  83c40c               add esp, 0xc
// 0074a2f6  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0074a2fe  85c0                 test eax, eax
// 0074a300  7415                 je 0x74a317
// 0074a302  8b00                 mov eax, dword ptr [eax]
// 0074a304  85c0                 test eax, eax
// 0074a306  740f                 je 0x74a317
// 0074a308  8d4c241c             lea ecx, [esp + 0x1c]
// 0074a30c  6a02                 push 2
// 0074a30e  51                   push ecx
// 0074a30f  8bd1                 mov edx, ecx
// 0074a311  52                   push edx
// 0074a312  ffd0                 call eax
// 0074a314  83c40c               add esp, 0xc
// 0074a317  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074a31b  8bc6                 mov eax, esi
// 0074a31d  64890d00000000       mov dword ptr fs:[0], ecx
// 0074a324  5e                   pop esi
// 0074a325  83c40c               add esp, 0xc
// 0074a328  c22000               ret 0x20
// copied from an identical function in another client (function ??0?$storage1@V?$value@V?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@@_bi@boost@@@_bi@boost@@QAE@V?$value@V?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@@12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
}
namespace boost {
namespace detail {
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    char data;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class A> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { assign_to_own(f); }
    ~function0() { clear(); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
    void clear()
    {
        if (this->vtable) {
            this->vtable->clear(this->functor);
            this->vtable = 0;
        }
    }
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct storage1 { A1 a1_; explicit storage1(A1 a1) : a1_(a1) {} };
}
}
namespace std { template<class T> class allocator; }
template struct boost::_bi::storage1<boost::_bi::value<boost::function0<void, std::allocator<boost::function_base> > > >;