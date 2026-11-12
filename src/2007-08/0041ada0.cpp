// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 0041ada0  unit: VDHTMLWindowService::?$FactoryProduct  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ada0
// 0041ada0  6aff                 push -1
// 0041ada2  6868d37300           push 0x73d368
// 0041ada7  64a100000000         mov eax, dword ptr fs:[0]
// 0041adad  50                   push eax
// 0041adae  56                   push esi
// 0041adaf  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041adb4  33c4                 xor eax, esp
// 0041adb6  50                   push eax
// 0041adb7  8d442408             lea eax, [esp + 8]
// 0041adbb  64a300000000         mov dword ptr fs:[0], eax
// 0041adc1  8bf1                 mov esi, ecx
// 0041adc3  8d442418             lea eax, [esp + 0x18]
// 0041adc7  50                   push eax
// 0041adc8  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0041add0  e8fbcb0600           call 0x4879d0
// 0041add5  83c404               add esp, 4
// 0041add8  84c0                 test al, al
// 0041adda  7554                 jne 0x41ae30
// 0041addc  6a18                 push 0x18
// 0041adde  c7460870a94100       mov dword ptr [esi + 8], 0x41a970
// 0041ade5  c706e06b4100         mov dword ptr [esi], 0x416be0
// 0041adeb  e806512100           call 0x62fef6
// 0041adf0  83c404               add esp, 4
// 0041adf3  85c0                 test eax, eax
// 0041adf5  7436                 je 0x41ae2d
// 0041adf7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041adfb  8908                 mov dword ptr [eax], ecx
// 0041adfd  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041ae01  895004               mov dword ptr [eax + 4], edx
// 0041ae04  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0041ae08  894808               mov dword ptr [eax + 8], ecx
// 0041ae0b  8b542424             mov edx, dword ptr [esp + 0x24]
// 0041ae0f  89500c               mov dword ptr [eax + 0xc], edx
// 0041ae12  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041ae16  85c9                 test ecx, ecx
// 0041ae18  740c                 je 0x41ae26
// 0041ae1a  83c104               add ecx, 4
// 0041ae1d  ba01000000           mov edx, 1
// 0041ae22  f00fc111             lock xadd dword ptr [ecx], edx
// 0041ae26  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0041ae2a  894810               mov dword ptr [eax + 0x10], ecx
// 0041ae2d  894604               mov dword ptr [esi + 4], eax
// 0041ae30  8b742424             mov esi, dword ptr [esp + 0x24]
// 0041ae34  85f6                 test esi, esi
// 0041ae36  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0041ae3e  742a                 je 0x41ae6a
// 0041ae40  8d5604               lea edx, [esi + 4]
// 0041ae43  83c8ff               or eax, 0xffffffff
// 0041ae46  f00fc102             lock xadd dword ptr [edx], eax
// 0041ae4a  751e                 jne 0x41ae6a
// 0041ae4c  8b16                 mov edx, dword ptr [esi]
// 0041ae4e  8b4204               mov eax, dword ptr [edx + 4]
// 0041ae51  8bce                 mov ecx, esi
// 0041ae53  ffd0                 call eax
// 0041ae55  8d4e08               lea ecx, [esi + 8]
// 0041ae58  83caff               or edx, 0xffffffff
// 0041ae5b  f00fc111             lock xadd dword ptr [ecx], edx
// 0041ae5f  7509                 jne 0x41ae6a
// 0041ae61  8b06                 mov eax, dword ptr [esi]
// 0041ae63  8b5008               mov edx, dword ptr [eax + 8]
// 0041ae66  8bce                 mov ecx, esi
// 0041ae68  ffd2                 call edx
// 0041ae6a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041ae6e  64890d00000000       mov dword ptr fs:[0], ecx
// 0041ae75  59                   pop ecx
// 0041ae76  5e                   pop esi
// 0041ae77  83c40c               add esp, 0xc
// 0041ae7a  c21c00               ret 0x1c

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

bool has_empty_target(const void*);

typedef void* (*manager_type)(void*, int);
typedef void (*invoker_type)(void*);
void* functor_manage(void*, int);
void functor_invoke(void*);

struct function1 {
    manager_type manager;
    void* functor;
    invoker_type invoker;
    void assign_to(Functor f, function_obj_tag);
};

void function1::assign_to(Functor f, function_obj_tag)
{
    if (!has_empty_target(&f)) {
        invoker = &functor_invoke;
        manager = &functor_manage;
        Functor* nf = static_cast<Functor*>(operator new(sizeof(Functor)));
        new (nf) Functor(f);
        functor = nf;
    }
}
