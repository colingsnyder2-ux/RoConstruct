// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 42% by colin
// roc 2007-08 00561b60  unit: RBX::VModelInstance::?$FilteredSelection  size: 367 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00561b60
//
// 00561b60  64a100000000         mov eax, dword ptr fs:[0]
// 00561b66  6aff                 push -1
// 00561b68  68d8bc7500           push 0x75bcd8
// 00561b6d  50                   push eax
// 00561b6e  64892500000000       mov dword ptr fs:[0], esp
// 00561b75  83ec08               sub esp, 8
// 00561b78  55                   push ebp
// 00561b79  56                   push esi
// 00561b7a  8b742420             mov esi, dword ptr [esp + 0x20]
// 00561b7e  56                   push esi
// 00561b7f  8be9                 mov ebp, ecx
// 00561b81  e8dafdfdff           call 0x541960
// 00561b86  83bdec00000000       cmp dword ptr [ebp + 0xec], 0
// 00561b8d  0f8529010000         jne 0x561cbc
// 00561b93  8b4608               mov eax, dword ptr [esi + 8]
// 00561b96  50                   push eax
// 00561b97  e8a4cfebff           call 0x41eb40
// 00561b9c  50                   push eax
// 00561b9d  8d4c2410             lea ecx, [esp + 0x10]
// 00561ba1  51                   push ecx
// 00561ba2  e8c9baf3ff           call 0x49d670
// 00561ba7  83c40c               add esp, 0xc
// 00561baa  8b10                 mov edx, dword ptr [eax]
// 00561bac  83c004               add eax, 4
// 00561baf  50                   push eax
// 00561bb0  8d8df0000000         lea ecx, [ebp + 0xf0]
// 00561bb6  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00561bbe  8995ec000000         mov dword ptr [ebp + 0xec], edx
// 00561bc4  e8970eeaff           call 0x402a60
// 00561bc9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00561bcd  85c0                 test eax, eax
// 00561bcf  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00561bd7  742c                 je 0x561c05
// 00561bd9  8bf0                 mov esi, eax
// 00561bdb  83c004               add eax, 4
// 00561bde  83c9ff               or ecx, 0xffffffff
// 00561be1  f00fc108             lock xadd dword ptr [eax], ecx
// 00561be5  751e                 jne 0x561c05
// 00561be7  8b16                 mov edx, dword ptr [esi]
// 00561be9  8b4204               mov eax, dword ptr [edx + 4]
// 00561bec  8bce                 mov ecx, esi
// 00561bee  ffd0                 call eax
// 00561bf0  8d4e08               lea ecx, [esi + 8]
// 00561bf3  83caff               or edx, 0xffffffff
// 00561bf6  f00fc111             lock xadd dword ptr [ecx], edx
// 00561bfa  7509                 jne 0x561c05
// 00561bfc  8b06                 mov eax, dword ptr [esi]
// 00561bfe  8b5008               mov edx, dword ptr [eax + 8]
// 00561c01  8bce                 mov ecx, esi
// 00561c03  ffd2                 call edx
// 00561c05  8b85ec000000         mov eax, dword ptr [ebp + 0xec]
// 00561c0b  85c0                 test eax, eax
// 00561c0d  0f84a9000000         je 0x561cbc
// 00561c13  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00561c19  53                   push ebx
// 00561c1a  57                   push edi
// 00561c1b  8b7804               mov edi, dword ptr [eax + 4]
// 00561c1e  3b7808               cmp edi, dword ptr [eax + 8]
// 00561c21  89442428             mov dword ptr [esp + 0x28], eax
// 00561c25  7609                 jbe 0x561c30
// 00561c27  ff15d8e67700         call dword ptr [0x77e6d8]
// 00561c2d  8d4900               lea ecx, [ecx]
// 00561c30  8b85ec000000         mov eax, dword ptr [ebp + 0xec]
// 00561c36  8bb004010000         mov esi, dword ptr [eax + 0x104]
// 00561c3c  8b5e08               mov ebx, dword ptr [esi + 8]
// 00561c3f  395e04               cmp dword ptr [esi + 4], ebx
// 00561c42  7606                 jbe 0x561c4a
// 00561c44  ff15d8e67700         call dword ptr [0x77e6d8]
// 00561c4a  39742428             cmp dword ptr [esp + 0x28], esi
// 00561c4e  8b35d8e67700         mov esi, dword ptr [0x77e6d8]
// 00561c54  7402                 je 0x561c58
// 00561c56  ffd6                 call esi
// 00561c58  3bfb                 cmp edi, ebx
// 00561c5a  744c                 je 0x561ca8
// 00561c5c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00561c60  3b7908               cmp edi, dword ptr [ecx + 8]
// 00561c63  7202                 jb 0x561c67
// 00561c65  ffd6                 call esi
// 00561c67  8b07                 mov eax, dword ptr [edi]
// 00561c69  6a00                 push 0
// 00561c6b  68b8c68800           push 0x88c6b8
// 00561c70  684c1f8800           push 0x881f4c
// 00561c75  6a00                 push 0
// 00561c77  50                   push eax
// 00561c78  e8b9f00c00           call 0x630d36
// 00561c7d  83c414               add esp, 0x14
// 00561c80  85c0                 test eax, eax
// 00561c82  89442410             mov dword ptr [esp + 0x10], eax
// 00561c86  7410                 je 0x561c98
// 00561c88  8d542410             lea edx, [esp + 0x10]
// 00561c8c  52                   push edx
// 00561c8d  8d8df4000000         lea ecx, [ebp + 0xf4]
// 00561c93  e8d8230500           call 0x5b4070
// 00561c98  8b442428             mov eax, dword ptr [esp + 0x28]
// 00561c9c  3b7808               cmp edi, dword ptr [eax + 8]
// 00561c9f  7202                 jb 0x561ca3
// 00561ca1  ffd6                 call esi
// 00561ca3  83c708               add edi, 8
// 00561ca6  eb88                 jmp 0x561c30
// 00561ca8  8d8de8000000         lea ecx, [ebp + 0xe8]
// 00561cae  51                   push ecx
// 00561caf  8b8dec000000         mov ecx, dword ptr [ebp + 0xec]
// 00561cb5  e8e60efdff           call 0x532ba0
// 00561cba  5f                   pop edi
// 00561cbb  5b                   pop ebx
// 00561cbc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00561cc0  5e                   pop esi
// 00561cc1  5d                   pop ebp
// 00561cc2  64890d00000000       mov dword ptr fs:[0], ecx
// 00561cc9  83c414               add esp, 0x14
// 00561ccc  c20400               ret 4

#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

// boost::detail::sp_counted_base shape: vptr, use_count_ (+4), weak_count_ (+8)
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;   // vtable +4
    virtual void destroy();       // vtable +8
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_) pi_->release(); }
    shared_count& operator=(const shared_count& r);   // 0x402a60
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator bool() const { return px != 0; }
};

namespace RBX {
class Instance {                 // RTTI .?AVInstance@RBX@@ (0x881f4c)
public:
    virtual ~Instance();
};

class ModelInstance : public Instance {   // RTTI .?AVModelInstance@RBX@@ (0x88c6b8)
};
}
using RBX::Instance;
using RBX::ModelInstance;

struct Listener {           // subobject at +0xe8
    virtual void onEvent();
};

struct Owner {
    int pad[0x104 / 4];
    std::vector< shared_ptr<Instance> >* children;   // +0x104
    void addListener(Listener* l);                   // 0x532ba0
};

struct ServiceProvider;
ServiceProvider* findServiceProvider(Instance* inst);              // 0x41eb40
shared_ptr<Owner> findOwner(ServiceProvider* provider);            // 0x49d670

struct AncestorChanged {
    int pad[2];
    Instance* newParent;   // +8
};

struct Base {               // polymorphic: vptr at +0 (see dtor 0055ff50)
    virtual ~Base();
    int pad[(0xe8 - 4) / 4];
    void onAncestorChanged(const AncestorChanged& event);   // 0x541960
};

struct FilteredSelection : Base, Listener {
    shared_ptr<Owner> owner;            // +0xec
    std::vector<ModelInstance*> items;   // +0xf4
    void onAncestorChanged(const AncestorChanged& event);
};

void FilteredSelection::onAncestorChanged(const AncestorChanged& event)
{
    Base::onAncestorChanged(event);
    if (!owner) {
        owner = findOwner(findServiceProvider(event.newParent));
        if (owner) {
            const std::vector< shared_ptr<Instance> >& c = *owner->children;
            for (std::vector< shared_ptr<Instance> >::const_iterator it = c.begin();
                 it != owner->children->end(); ++it) {
                if (ModelInstance* p = dynamic_cast<ModelInstance*>(it->get()))
                    items.push_back(p);
            }
            owner->addListener(this);
        }
    }
}
