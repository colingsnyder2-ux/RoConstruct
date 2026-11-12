// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 0041b120  unit: VDHTMLWindowService::?$FactoryProduct::Creator  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b120
// 0041b120  6aff                 push -1
// 0041b122  6838b07300           push 0x73b038
// 0041b127  64a100000000         mov eax, dword ptr fs:[0]
// 0041b12d  50                   push eax
// 0041b12e  51                   push ecx
// 0041b12f  56                   push esi
// 0041b130  57                   push edi
// 0041b131  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041b136  33c4                 xor eax, esp
// 0041b138  50                   push eax
// 0041b139  8d442410             lea eax, [esp + 0x10]
// 0041b13d  64a300000000         mov dword ptr fs:[0], eax
// 0041b143  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041b147  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0041b14b  c644240c00           mov byte ptr [esp + 0xc], 0
// 0041b150  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b154  50                   push eax
// 0041b155  83ec18               sub esp, 0x18
// 0041b158  85f6                 test esi, esi
// 0041b15a  8bc4                 mov eax, esp
// 0041b15c  8910                 mov dword ptr [eax], edx
// 0041b15e  8b542440             mov edx, dword ptr [esp + 0x40]
// 0041b162  895004               mov dword ptr [eax + 4], edx
// 0041b165  8b542444             mov edx, dword ptr [esp + 0x44]
// 0041b169  895008               mov dword ptr [eax + 8], edx
// 0041b16c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0041b174  89642428             mov dword ptr [esp + 0x28], esp
// 0041b178  89700c               mov dword ptr [eax + 0xc], esi
// 0041b17b  740c                 je 0x41b189
// 0041b17d  8d5604               lea edx, [esi + 4]
// 0041b180  bf01000000           mov edi, 1
// 0041b185  f00fc13a             lock xadd dword ptr [edx], edi
// 0041b189  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0041b18d  895010               mov dword ptr [eax + 0x10], edx
// 0041b190  e80bfcffff           call 0x41ada0
// 0041b195  85f6                 test esi, esi
// 0041b197  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0041b19f  742a                 je 0x41b1cb
// 0041b1a1  8d4604               lea eax, [esi + 4]
// 0041b1a4  83c9ff               or ecx, 0xffffffff
// 0041b1a7  f00fc108             lock xadd dword ptr [eax], ecx
// 0041b1ab  751e                 jne 0x41b1cb
// 0041b1ad  8b16                 mov edx, dword ptr [esi]
// 0041b1af  8b4204               mov eax, dword ptr [edx + 4]
// 0041b1b2  8bce                 mov ecx, esi
// 0041b1b4  ffd0                 call eax
// 0041b1b6  8d4e08               lea ecx, [esi + 8]
// 0041b1b9  83caff               or edx, 0xffffffff
// 0041b1bc  f00fc111             lock xadd dword ptr [ecx], edx
// 0041b1c0  7509                 jne 0x41b1cb
// 0041b1c2  8b06                 mov eax, dword ptr [esi]
// 0041b1c4  8b5008               mov edx, dword ptr [eax + 8]
// 0041b1c7  8bce                 mov ecx, esi
// 0041b1c9  ffd2                 call edx
// 0041b1cb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041b1cf  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b1d6  59                   pop ecx
// 0041b1d7  5f                   pop edi
// 0041b1d8  5e                   pop esi
// 0041b1d9  83c410               add esp, 0x10
// 0041b1dc  c21800               ret 0x18
#include <intrin.h>
#include <new>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

struct Target;
struct shared_ptr_T {
    Target* px;
    shared_count pn;
};

struct empty_arg {};

struct Functor {
    int f0;
    int f1;
    shared_ptr_T sp;
    int f4;
    empty_arg a;
};

struct function_obj_tag {};

typedef void* (*manager_type)(void*, int);
typedef void (*invoker_type)(void*);

struct function1 {
    manager_type manager;
    void* functor;
    invoker_type invoker;
    void assign_to(Functor f, function_obj_tag);
    void assign_to(Functor f);
};

void function1::assign_to(Functor f)
{
    assign_to(f, function_obj_tag());
}
