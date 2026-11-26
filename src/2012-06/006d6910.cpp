// from server: 100% by Xemicl
// roc 2012-06 006d6910  unit: RBX::VInstance::?$NonFactoryProduct  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d6910
//
// 006d6910  6aff                 push -1
// 006d6912  68d896ac00           push 0xac96d8
// 006d6917  64a100000000         mov eax, dword ptr fs:[0]
// 006d691d  50                   push eax
// 006d691e  64892500000000       mov dword ptr fs:[0], esp
// 006d6925  51                   push ecx
// 006d6926  56                   push esi
// 006d6927  8bf1                 mov esi, ecx
// 006d6929  83ec20               sub esp, 0x20
// 006d692c  8bc4                 mov eax, esp
// 006d692e  c70000000000         mov dword ptr [eax], 0
// 006d6934  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 006d6938  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006d6940  89642424             mov dword ptr [esp + 0x24], esp
// 006d6944  85c9                 test ecx, ecx
// 006d6946  7418                 je 0x6d6960
// 006d6948  8908                 mov dword ptr [eax], ecx
// 006d694a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 006d694e  8b11                 mov edx, dword ptr [ecx]
// 006d6950  83c008               add eax, 8
// 006d6953  6a00                 push 0
// 006d6955  50                   push eax
// 006d6956  8d442450             lea eax, [esp + 0x50]
// 006d695a  50                   push eax
// 006d695b  ffd2                 call edx
// 006d695d  83c40c               add esp, 0xc
// 006d6960  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 006d6964  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006d6968  50                   push eax
// 006d6969  51                   push ecx
// 006d696a  8bce                 mov ecx, esi
// 006d696c  e8ffe5ffff           call 0x6d4f70
// 006d6971  8b442420             mov eax, dword ptr [esp + 0x20]
// 006d6975  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006d697d  85c0                 test eax, eax
// 006d697f  7415                 je 0x6d6996
// 006d6981  8b00                 mov eax, dword ptr [eax]
// 006d6983  85c0                 test eax, eax
// 006d6985  740f                 je 0x6d6996
// 006d6987  8d542428             lea edx, [esp + 0x28]
// 006d698b  6a02                 push 2
// 006d698d  52                   push edx
// 006d698e  8bca                 mov ecx, edx
// 006d6990  51                   push ecx
// 006d6991  ffd0                 call eax
// 006d6993  83c40c               add esp, 0xc
// 006d6996  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d699a  8bc6                 mov eax, esi
// 006d699c  64890d00000000       mov dword ptr fs:[0], ecx
// 006d69a3  5e                   pop esi
// 006d69a4  83c410               add esp, 0x10
// 006d69a7  c22800               ret 0x28
// copied from an identical function in another client (function ??0Derived@@QAE@PAVA@@PAVB@@V?$function0@X@boost@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail {
namespace function {
union function_buffer {
    void* obj_ptr;
    double d;
    char data[0x18];
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
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { this->assign_to_own(f); }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (f.vtable) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
class A; class B;
class Base {
public:
    Base(A* a, B* b, boost::function0<void> fn);
};
class Derived : public Base {
public:
    Derived(A* a, B* b, boost::function0<void> fn);
};
Derived::Derived(A* a, B* b, boost::function0<void> fn) : Base(a, b, fn) {}