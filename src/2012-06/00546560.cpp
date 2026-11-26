// from server: 100% by Xemicl
// roc 2012-06 00546560  unit: rbx::signals::Z::$$A6AX_NH::?$signal::Vslot::?$callable  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00546560
//
// 00546560  6aff                 push -1
// 00546562  6881ceaa00           push 0xaace81
// 00546567  64a100000000         mov eax, dword ptr fs:[0]
// 0054656d  50                   push eax
// 0054656e  64892500000000       mov dword ptr fs:[0], esp
// 00546575  51                   push ecx
// 00546576  56                   push esi
// 00546577  c744240400000000     mov dword ptr [esp + 4], 0
// 0054657f  8d44241c             lea eax, [esp + 0x1c]
// 00546583  50                   push eax
// 00546584  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0054658c  e86fdfffff           call 0x544500
// 00546591  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00546595  83c404               add esp, 4
// 00546598  8906                 mov dword ptr [esi], eax
// 0054659a  85c0                 test eax, eax
// 0054659c  740c                 je 0x5465aa
// 0054659e  83c004               add eax, 4
// 005465a1  b901000000           mov ecx, 1
// 005465a6  f00fc108             lock xadd dword ptr [eax], ecx
// 005465aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005465ae  c744240401000000     mov dword ptr [esp + 4], 1
// 005465b6  c644241000           mov byte ptr [esp + 0x10], 0
// 005465bb  85c0                 test eax, eax
// 005465bd  7415                 je 0x5465d4
// 005465bf  8b00                 mov eax, dword ptr [eax]
// 005465c1  85c0                 test eax, eax
// 005465c3  740f                 je 0x5465d4
// 005465c5  8d542424             lea edx, [esp + 0x24]
// 005465c9  6a02                 push 2
// 005465cb  52                   push edx
// 005465cc  8bca                 mov ecx, edx
// 005465ce  51                   push ecx
// 005465cf  ffd0                 call eax
// 005465d1  83c40c               add esp, 0xc
// 005465d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005465d8  8bc6                 mov eax, esi
// 005465da  5e                   pop esi
// 005465db  64890d00000000       mov dword ptr fs:[0], ecx
// 005465e2  83c410               add esp, 0x10
// 005465e5  c3                   ret 
// copied from an identical function in another client (function ?createY@@YA?AV?$intrusive_ptr@UY@@@boost@@V?$function0@X@2@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
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
    double align;
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
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f)
    {
        this->vtable = 0;
        this->assign_to_own(f);
    }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
struct Y { virtual ~Y(); long refcount; };
inline void intrusive_ptr_add_ref(Y* p) { _InterlockedIncrement(&p->refcount); }
inline void intrusive_ptr_release(Y* p);
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(T* p, bool add_ref = true) : px(p) { if (px != 0 && add_ref) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
    T* px;
};
}
Y* newY(const boost::function0<void>& f);
boost::intrusive_ptr<Y> createY(boost::function0<void> f)
{
    return boost::intrusive_ptr<Y>(newY(f));
}