// from server: 100% by Xemicl
// roc 2012-06 00446970  unit: AsyncResult  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00446970
//
// 00446970  56                   push esi
// 00446971  8bf1                 mov esi, ecx
// 00446973  8b4608               mov eax, dword ptr [esi + 8]
// 00446976  85c0                 test eax, eax
// 00446978  7419                 je 0x446993
// 0044697a  8b00                 mov eax, dword ptr [eax]
// 0044697c  8d4e10               lea ecx, [esi + 0x10]
// 0044697f  85c0                 test eax, eax
// 00446981  7409                 je 0x44698c
// 00446983  6a02                 push 2
// 00446985  51                   push ecx
// 00446986  51                   push ecx
// 00446987  ffd0                 call eax
// 00446989  83c40c               add esp, 0xc
// 0044698c  c7460800000000       mov dword ptr [esi + 8], 0
// 00446993  5e                   pop esi
// 00446994  c3                   ret 
// copied from an identical function in another client (function ??1Item@TimerService@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace boost {
namespace detail {
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
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0() {}
    function0(const function0& f);
    ~function0() { clear(); }
    void clear()
    {
        if (this->vtable) {
            this->vtable->clear(this->functor);
            this->vtable = 0;
        }
    }
};
}
namespace RBX {
class TimerService {
public:
	struct Item {
		__int64 time;
		boost::function0<void> func;
	};
};
}
template std::list<RBX::TimerService::Item>::iterator std::list<RBX::TimerService::Item>::erase(std::list<RBX::TimerService::Item>::const_iterator);