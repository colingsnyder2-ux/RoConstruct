// from server: 100% by Xemicl
// roc 2012-06 006a6210  unit: RBX::Lua::WeakThreadRef  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a6210
//
// 006a6210  6aff                 push -1
// 006a6212  68281caa00           push 0xaa1c28
// 006a6217  64a100000000         mov eax, dword ptr fs:[0]
// 006a621d  50                   push eax
// 006a621e  64892500000000       mov dword ptr fs:[0], esp
// 006a6225  83ec20               sub esp, 0x20
// 006a6228  56                   push esi
// 006a6229  8bf1                 mov esi, ecx
// 006a622b  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006a622f  8b01                 mov eax, dword ptr [ecx]
// 006a6231  c744240400000000     mov dword ptr [esp + 4], 0
// 006a6239  85c0                 test eax, eax
// 006a623b  7416                 je 0x6a6253
// 006a623d  6a00                 push 0
// 006a623f  8d542410             lea edx, [esp + 0x10]
// 006a6243  52                   push edx
// 006a6244  83c108               add ecx, 8
// 006a6247  8944240c             mov dword ptr [esp + 0xc], eax
// 006a624b  8b00                 mov eax, dword ptr [eax]
// 006a624d  51                   push ecx
// 006a624e  ffd0                 call eax
// 006a6250  83c40c               add esp, 0xc
// 006a6253  56                   push esi
// 006a6254  8d4c2408             lea ecx, [esp + 8]
// 006a6258  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006a6260  e8ebf4ffff           call 0x6a5750
// 006a6265  8b442404             mov eax, dword ptr [esp + 4]
// 006a6269  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 006a6271  85c0                 test eax, eax
// 006a6273  7415                 je 0x6a628a
// 006a6275  8b00                 mov eax, dword ptr [eax]
// 006a6277  85c0                 test eax, eax
// 006a6279  740f                 je 0x6a628a
// 006a627b  8d4c240c             lea ecx, [esp + 0xc]
// 006a627f  6a02                 push 2
// 006a6281  51                   push ecx
// 006a6282  8bd1                 mov edx, ecx
// 006a6284  52                   push edx
// 006a6285  ffd0                 call eax
// 006a6287  83c40c               add esp, 0xc
// 006a628a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006a628e  8bc6                 mov eax, esi
// 006a6290  5e                   pop esi
// 006a6291  64890d00000000       mov dword ptr fs:[0], ecx
// 006a6298  83c42c               add esp, 0x2c
// 006a629b  c20400               ret 4
// copied from an identical function in another client (function ??4?$function@$$A6AX_N@ZV?$allocator@X@std@@@boost@@QAEAAV01@ABV01@@Z)

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// boost::function<void(bool)>::operator= with boost >= 1.35 function_buffer/manager (destroy_functor_tag = 2)
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
template<class R, class T0, class Allocator> class function1 : public function_base {
public:
    function1(const function1& f) : function_base() { assign_to_own(f); }
    ~function1() { clear(); }
    void swap(function1& other);
    void assign_to_own(const function1& f)
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
template<typename Signature, typename Allocator> class function;
template<typename Allocator>
class function<void(bool), Allocator> : public function1<void, bool, Allocator> {
    typedef function1<void, bool, Allocator> base_type;
    typedef function self_type;
public:
    function(const self_type& f) : base_type(static_cast<const base_type&>(f)) {}
    self_type& operator=(const self_type& f)
    {
        self_type(f).swap(*this);
        return *this;
    }
};
}
namespace std { template<class T> class allocator; }
template class boost::function<void(bool), std::allocator<void> >;