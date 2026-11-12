// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00418220  unit: boost::signals::detail::slot_base::Udata_t::?$sp_counted_impl_p  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00418220
//
// 00418220  6aff                 push -1
// 00418222  6868d37300           push 0x73d368
// 00418227  64a100000000         mov eax, dword ptr fs:[0]
// 0041822d  50                   push eax
// 0041822e  56                   push esi
// 0041822f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00418234  33c4                 xor eax, esp
// 00418236  50                   push eax
// 00418237  8d442408             lea eax, [esp + 8]
// 0041823b  64a300000000         mov dword ptr fs:[0], eax
// 00418241  8bf1                 mov esi, ecx
// 00418243  8d442418             lea eax, [esp + 0x18]
// 00418247  50                   push eax
// 00418248  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00418250  e87bf70600           call 0x4879d0
// 00418255  83c404               add esp, 4
// 00418258  84c0                 test al, al
// 0041825a  755b                 jne 0x4182b7
// 0041825c  6a18                 push 0x18
// 0041825e  c74608406a4100       mov dword ptr [esi + 8], 0x416a40
// 00418265  c70630754100         mov dword ptr [esi], 0x417530
// 0041826b  e8867c2100           call 0x62fef6
// 00418270  83c404               add esp, 4
// 00418273  85c0                 test eax, eax
// 00418275  743d                 je 0x4182b4
// 00418277  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041827b  8908                 mov dword ptr [eax], ecx
// 0041827d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418281  895004               mov dword ptr [eax + 4], edx
// 00418284  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00418288  894808               mov dword ptr [eax + 8], ecx
// 0041828b  8b542424             mov edx, dword ptr [esp + 0x24]
// 0041828f  89500c               mov dword ptr [eax + 0xc], edx
// 00418292  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00418296  85c9                 test ecx, ecx
// 00418298  740c                 je 0x4182a6
// 0041829a  83c104               add ecx, 4
// 0041829d  ba01000000           mov edx, 1
// 004182a2  f00fc111             lock xadd dword ptr [ecx], edx
// 004182a6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004182aa  894810               mov dword ptr [eax + 0x10], ecx
// 004182ad  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004182b1  895014               mov dword ptr [eax + 0x14], edx
// 004182b4  894604               mov dword ptr [esi + 4], eax
// 004182b7  8b742424             mov esi, dword ptr [esp + 0x24]
// 004182bb  85f6                 test esi, esi
// 004182bd  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004182c5  742a                 je 0x4182f1
// 004182c7  8d4604               lea eax, [esi + 4]
// 004182ca  83c9ff               or ecx, 0xffffffff
// 004182cd  f00fc108             lock xadd dword ptr [eax], ecx
// 004182d1  751e                 jne 0x4182f1
// 004182d3  8b16                 mov edx, dword ptr [esi]
// 004182d5  8b4204               mov eax, dword ptr [edx + 4]
// 004182d8  8bce                 mov ecx, esi
// 004182da  ffd0                 call eax
// 004182dc  8d4e08               lea ecx, [esi + 8]
// 004182df  83caff               or edx, 0xffffffff
// 004182e2  f00fc111             lock xadd dword ptr [ecx], edx
// 004182e6  7509                 jne 0x4182f1
// 004182e8  8b06                 mov eax, dword ptr [esi]
// 004182ea  8b5008               mov edx, dword ptr [eax + 8]
// 004182ed  8bce                 mov ecx, esi
// 004182ef  ffd2                 call edx
// 004182f1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004182f5  64890d00000000       mov dword ptr fs:[0], ecx
// 004182fc  59                   pop ecx
// 004182fd  5e                   pop esi
// 004182fe  83c40c               add esp, 0xc
// 00418301  c21c00               ret 0x1c

// boost 1.33-style function0::assign_to(FunctionObj f, function_obj_tag):
// manager at +0, functor at +4, invoker at +8 (store order read from target).
#include <memory>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
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

class shared_count {
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

struct Target;

struct shared_ptr_t {
    Target* px;
    shared_count pn;
};

// 0x18-byte functor (new 0x18); shared_ptr at +8 (count at +0xc).
struct Functor {
    int a0;
    int a4;
    shared_ptr_t sp;
    int a10;
    int a14;
};

struct function_obj_tag {};
typedef void* any_pointer;
enum functor_manager_operation_type { clone_functor_tag, destroy_functor_tag };

bool has_empty_target(...);

struct functor_manager_F {
    static any_pointer manage(any_pointer, functor_manager_operation_type);
};
struct invoker_F {
    static void invoke(any_pointer);
};

struct function_base {
    any_pointer (*manager)(any_pointer, functor_manager_operation_type);
    any_pointer functor;
};

struct function0 : function_base {
    void (*invoker)(any_pointer);
    void assign_to(Functor f, function_obj_tag);
};

void function0::assign_to(Functor f, function_obj_tag)
{
    if (!has_empty_target(&f)) {
        invoker = &invoker_F::invoke;
        this->manager = &functor_manager_F::manage;
        std::allocator<Functor> allocator;
        Functor* copy = allocator.allocate(1);
        allocator.construct(copy, f);
        Functor* new_f = static_cast<Functor*>(copy);
        this->functor = static_cast<void*>(new_f);
    }
}
