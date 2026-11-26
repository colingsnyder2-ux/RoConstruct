// from server: 100% by Xemicl
// roc 2012-06 00431110  unit: CSelectionTreeCtrl  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00431110
//
// 00431110  6aff                 push -1
// 00431112  6840c9a900           push 0xa9c940
// 00431117  64a100000000         mov eax, dword ptr fs:[0]
// 0043111d  50                   push eax
// 0043111e  64892500000000       mov dword ptr fs:[0], esp
// 00431125  83ec28               sub esp, 0x28
// 00431128  53                   push ebx
// 00431129  56                   push esi
// 0043112a  6a00                 push 0
// 0043112c  83ec24               sub esp, 0x24
// 0043112f  8bf1                 mov esi, ecx
// 00431131  89642434             mov dword ptr [esp + 0x34], esp
// 00431135  8bdc                 mov ebx, esp
// 00431137  56                   push esi
// 00431138  83ec1c               sub esp, 0x1c
// 0043113b  8bc4                 mov eax, esp
// 0043113d  89642454             mov dword ptr [esp + 0x54], esp
// 00431141  50                   push eax
// 00431142  89742454             mov dword ptr [esp + 0x54], esi
// 00431146  e8b5f9ffff           call 0x430b00
// 0043114b  83c404               add esp, 4
// 0043114e  6820104300           push 0x431020
// 00431153  53                   push ebx
// 00431154  e867fbffff           call 0x430cc0
// 00431159  83c428               add esp, 0x28
// 0043115c  8d4c2438             lea ecx, [esp + 0x38]
// 00431160  e83bfeffff           call 0x430fa0
// 00431165  6824f3b400           push 0xb4f324
// 0043116a  8d4c2414             lea ecx, [esp + 0x14]
// 0043116e  51                   push ecx
// 0043116f  8bce                 mov ecx, esi
// 00431171  c744244000000000     mov dword ptr [esp + 0x40], 0
// 00431179  e892335400           call 0x974510
// 0043117e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00431182  c644243802           mov byte ptr [esp + 0x38], 2
// 00431187  85c0                 test eax, eax
// 00431189  741d                 je 0x4311a8
// 0043118b  8b00                 mov eax, dword ptr [eax]
// 0043118d  85c0                 test eax, eax
// 0043118f  740f                 je 0x4311a0
// 00431191  8d542418             lea edx, [esp + 0x18]
// 00431195  6a02                 push 2
// 00431197  52                   push edx
// 00431198  8bca                 mov ecx, edx
// 0043119a  51                   push ecx
// 0043119b  ffd0                 call eax
// 0043119d  83c40c               add esp, 0xc
// 004311a0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004311a8  6a00                 push 0
// 004311aa  6a01                 push 1
// 004311ac  8d4e14               lea ecx, [esi + 0x14]
// 004311af  e83cfaffff           call 0x430bf0
// 004311b4  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004311b8  8bc6                 mov eax, esi
// 004311ba  5e                   pop esi
// 004311bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004311c2  5b                   pop ebx
// 004311c3  83c434               add esp, 0x34
// 004311c6  c3                   ret 
// copied from an identical function in another client (function ??0LoginRenewer@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
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
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    template<class F> function0(F f, int = 0);
    ~function0() { clear(); }
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
template<class A1, class A2> struct list2 { A1 a1_; A2 a2_; };
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
template<class R, class B1, class B2, class A1, class A2>
_bi::bind_t<R, R (*)(B1, B2), _bi::list2<_bi::value<A1>, _bi::value<A2> > > bind(R (*f)(B1, B2), A1 a1, A2 a2);
}
namespace RBX {
class worker_thread {
public:
    enum work_result { done, more };
    worker_thread(const boost::function0<work_result>& work_function, const char* name);
    ~worker_thread();
    void join();
private:
    char data[0x14];
};
class Event {
    void* handle;
public:
    Event(bool manualReset, bool initialState);
    ~Event();
};
class LoginRenewer {
    worker_thread thread;
    Event event;
    static std::string getUrl();
    static worker_thread::work_result renew(std::string url, LoginRenewer* self);
public:
    LoginRenewer();
};
LoginRenewer::LoginRenewer()
    : thread(boost::bind(&LoginRenewer::renew, getUrl(), this), "LoginRenewer"), event(true, false)
{
}
}