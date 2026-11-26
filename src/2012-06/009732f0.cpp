// from server: 100% by Xemicl
// roc 2012-06 009732f0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009732f0
//
// 009732f0  6aff                 push -1
// 009732f2  6828aead00           push 0xadae28
// 009732f7  64a100000000         mov eax, dword ptr fs:[0]
// 009732fd  50                   push eax
// 009732fe  64892500000000       mov dword ptr fs:[0], esp
// 00973305  83ec08               sub esp, 8
// 00973308  56                   push esi
// 00973309  8bf1                 mov esi, ecx
// 0097330b  57                   push edi
// 0097330c  89742408             mov dword ptr [esp + 8], esi
// 00973310  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00973314  83ec08               sub esp, 8
// 00973317  8bc4                 mov eax, esp
// 00973319  8908                 mov dword ptr [eax], ecx
// 0097331b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0097331f  895004               mov dword ptr [eax + 4], edx
// 00973322  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00973326  c744242001000000     mov dword ptr [esp + 0x20], 1
// 0097332e  89642414             mov dword ptr [esp + 0x14], esp
// 00973332  85c0                 test eax, eax
// 00973334  740c                 je 0x973342
// 00973336  83c004               add eax, 4
// 00973339  b901000000           mov ecx, 1
// 0097333e  f00fc108             lock xadd dword ptr [eax], ecx
// 00973342  8bce                 mov ecx, esi
// 00973344  e827f8c1ff           call 0x592b70
// 00973349  8b442428             mov eax, dword ptr [esp + 0x28]
// 0097334d  c644241802           mov byte ptr [esp + 0x18], 2
// 00973352  c7460800000000       mov dword ptr [esi + 8], 0
// 00973359  85c0                 test eax, eax
// 0097335b  7419                 je 0x973376
// 0097335d  6a00                 push 0
// 0097335f  8d5610               lea edx, [esi + 0x10]
// 00973362  52                   push edx
// 00973363  8d4c2438             lea ecx, [esp + 0x38]
// 00973367  894608               mov dword ptr [esi + 8], eax
// 0097336a  8b10                 mov edx, dword ptr [eax]
// 0097336c  51                   push ecx
// 0097336d  ffd2                 call edx
// 0097336f  8b442434             mov eax, dword ptr [esp + 0x34]
// 00973373  83c40c               add esp, 0xc
// 00973376  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0097337a  c644241800           mov byte ptr [esp + 0x18], 0
// 0097337f  85ff                 test edi, edi
// 00973381  742e                 je 0x9733b1
// 00973383  8d4704               lea eax, [edi + 4]
// 00973386  83c9ff               or ecx, 0xffffffff
// 00973389  f00fc108             lock xadd dword ptr [eax], ecx
// 0097338d  751e                 jne 0x9733ad
// 0097338f  8b17                 mov edx, dword ptr [edi]
// 00973391  8b4204               mov eax, dword ptr [edx + 4]
// 00973394  8bcf                 mov ecx, edi
// 00973396  ffd0                 call eax
// 00973398  8d4f08               lea ecx, [edi + 8]
// 0097339b  83caff               or edx, 0xffffffff
// 0097339e  f00fc111             lock xadd dword ptr [ecx], edx
// 009733a2  7509                 jne 0x9733ad
// 009733a4  8b07                 mov eax, dword ptr [edi]
// 009733a6  8b5008               mov edx, dword ptr [eax + 8]
// 009733a9  8bcf                 mov ecx, edi
// 009733ab  ffd2                 call edx
// 009733ad  8b442428             mov eax, dword ptr [esp + 0x28]
// 009733b1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 009733b9  85c0                 test eax, eax
// 009733bb  7415                 je 0x9733d2
// 009733bd  8b00                 mov eax, dword ptr [eax]
// 009733bf  85c0                 test eax, eax
// 009733c1  740f                 je 0x9733d2
// 009733c3  8d4c2430             lea ecx, [esp + 0x30]
// 009733c7  6a02                 push 2
// 009733c9  51                   push ecx
// 009733ca  8bd1                 mov edx, ecx
// 009733cc  52                   push edx
// 009733cd  ffd0                 call eax
// 009733cf  83c40c               add esp, 0xc
// 009733d2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009733d6  5f                   pop edi
// 009733d7  8bc6                 mov eax, esi
// 009733d9  64890d00000000       mov dword ptr fs:[0], ecx
// 009733e0  5e                   pop esi
// 009733e1  83c414               add esp, 0x14
// 009733e4  c22800               ret 0x28
// copied from an identical function in another client (function ??0?$storage2@V?$value@V?$shared_ptr@Udata@worker_thread@RBX@@@boost@@@_bi@boost@@V?$value@V?$function0@W4work_result@worker_thread@RBX@@V?$allocator@Vfunction_base@boost@@@std@@@boost@@@23@@_bi@boost@@QAE@V?$value@V?$shared_ptr@Udata@worker_thread@RBX@@@boost@@@12@V?$value@V?$function0@W4work_result@worker_thread@RBX@@V?$allocator@Vfunction_base@boost@@@std@@@boost@@@12@@Z)

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
template<class A1> struct storage1 { A1 a1_; explicit storage1(A1 a1); };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {} };
}
}
namespace std { template<class T> class allocator; }
namespace RBX {
class worker_thread {
public:
    enum work_result { done, more };
    struct data;
};
}
template struct boost::_bi::storage2<boost::_bi::value<boost::shared_ptr<RBX::worker_thread::data> >,
    boost::_bi::value<boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> > > >;