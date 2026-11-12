// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00416870  unit: VCLuaFunction::?$CComObject  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416870
//
// 00416870  837c240800           cmp dword ptr [esp + 8], 0
// 00416875  56                   push esi
// 00416876  7540                 jne 0x4168b8
// 00416878  6a18                 push 0x18
// 0041687a  e877962100           call 0x62fef6
// 0041687f  83c404               add esp, 4
// 00416882  85c0                 test eax, eax
// 00416884  7474                 je 0x4168fa
// 00416886  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041688a  8b11                 mov edx, dword ptr [ecx]
// 0041688c  8910                 mov dword ptr [eax], edx
// 0041688e  8b5104               mov edx, dword ptr [ecx + 4]
// 00416891  895004               mov dword ptr [eax + 4], edx
// 00416894  8b5108               mov edx, dword ptr [ecx + 8]
// 00416897  895008               mov dword ptr [eax + 8], edx
// 0041689a  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0041689d  85d2                 test edx, edx
// 0041689f  89500c               mov dword ptr [eax + 0xc], edx
// 004168a2  740c                 je 0x4168b0
// 004168a4  83c204               add edx, 4
// 004168a7  be01000000           mov esi, 1
// 004168ac  f00fc132             lock xadd dword ptr [edx], esi
// 004168b0  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004168b3  894810               mov dword ptr [eax + 0x10], ecx
// 004168b6  5e                   pop esi
// 004168b7  c3                   ret 
// 004168b8  57                   push edi
// 004168b9  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004168bd  8b770c               mov esi, dword ptr [edi + 0xc]
// 004168c0  85f6                 test esi, esi
// 004168c2  742a                 je 0x4168ee
// 004168c4  8d5604               lea edx, [esi + 4]
// 004168c7  83c8ff               or eax, 0xffffffff
// 004168ca  f00fc102             lock xadd dword ptr [edx], eax
// 004168ce  751e                 jne 0x4168ee
// 004168d0  8b16                 mov edx, dword ptr [esi]
// 004168d2  8b4204               mov eax, dword ptr [edx + 4]
// 004168d5  8bce                 mov ecx, esi
// 004168d7  ffd0                 call eax
// 004168d9  8d4e08               lea ecx, [esi + 8]
// 004168dc  83caff               or edx, 0xffffffff
// 004168df  f00fc111             lock xadd dword ptr [ecx], edx
// 004168e3  7509                 jne 0x4168ee
// 004168e5  8b06                 mov eax, dword ptr [esi]
// 004168e7  8b5008               mov edx, dword ptr [eax + 8]
// 004168ea  8bce                 mov ecx, esi
// 004168ec  ffd2                 call edx
// 004168ee  57                   push edi
// 004168ef  e86e932100           call 0x62fc62
// 004168f4  83c404               add esp, 4
// 004168f7  33c0                 xor eax, eax
// 004168f9  5f                   pop edi
// 004168fa  5e                   pop esi
// 004168fb  c3                   ret 
#include <memory>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

namespace detail {
class sp_counted_base
{
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();

    volatile long use_count_;
    volatile long weak_count_;

    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};

class shared_count
{
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

struct arg1 {};

struct Functor
{
    int a;
    int b;
    void* px;
    shared_count pn;
    int value;
    arg1 placeholder;
};
}

union any_pointer
{
    void* obj_ptr;
    const void* const_obj_ptr;
    void (*func_ptr)();
    char data[1];
};

inline any_pointer make_any_pointer(void* o)
{
    any_pointer ptr;
    ptr.obj_ptr = o;
    return ptr;
}

any_pointer __cdecl manageFunctor(any_pointer function_obj_ptr, int op)
{
    typedef std::allocator<detail::Functor> allocator_type;
    typedef allocator_type::pointer pointer_type;
    allocator_type allocator;

    if (op == 0) {
        detail::Functor* f = static_cast<detail::Functor*>(function_obj_ptr.obj_ptr);
        pointer_type copy = allocator.allocate(1);
        allocator.construct(copy, *f);
        detail::Functor* new_f = static_cast<detail::Functor*>(copy);
        return make_any_pointer(static_cast<void*>(new_f));
    } else {
        detail::Functor* f = static_cast<detail::Functor*>(function_obj_ptr.obj_ptr);
        pointer_type victim = static_cast<pointer_type>(f);
        allocator.destroy(victim);
        allocator.deallocate(victim, 1);
        return make_any_pointer(static_cast<void*>(0));
    }
}
