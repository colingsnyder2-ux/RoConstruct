// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00409760  unit: VCRenderSettingsItem::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00409760
//
// 00409760  6aff                 push -1
// 00409762  68ebd7a900           push 0xa9d7eb
// 00409767  64a100000000         mov eax, dword ptr fs:[0]
// 0040976d  50                   push eax
// 0040976e  64892500000000       mov dword ptr fs:[0], esp
// 00409775  83ec08               sub esp, 8
// 00409778  c7042400000000       mov dword ptr [esp], 0
// 0040977f  688c000000           push 0x8c
// 00409784  c644240400           mov byte ptr [esp + 4], 0
// 00409789  e88c895700           call 0x98211a
// 0040978e  83c404               add esp, 4
// 00409791  89442404             mov dword ptr [esp + 4], eax
// 00409795  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040979d  85c0                 test eax, eax
// 0040979f  7409                 je 0x4097aa
// 004097a1  8bc8                 mov ecx, eax
// 004097a3  e898102900           call 0x69a840
// 004097a8  eb02                 jmp 0x4097ac
// 004097aa  33c0                 xor eax, eax
// 004097ac  8b0c24               mov ecx, dword ptr [esp]
// 004097af  56                   push esi
// 004097b0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004097b4  51                   push ecx
// 004097b5  50                   push eax
// 004097b6  8bce                 mov ecx, esi
// 004097b8  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004097c0  e82bffffff           call 0x4096f0
// 004097c5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004097c9  8bc6                 mov eax, esi
// 004097cb  5e                   pop esi
// 004097cc  64890d00000000       mov dword ptr fs:[0], ecx
// 004097d3  83c414               add esp, 0x14
// 004097d6  c3                   ret 

// copied from an identical function in another client (function ??$create@VTarget@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTarget@RBX@@@boost@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdlib.h>
namespace boost {
template<class T> class shared_ptr {
    T* px;
    void* pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace RBX {
template<class T> class Creatable {
public:
    class Deleter { public: void operator()(T* instance); };
    template<class U> static boost::shared_ptr<U> create() { return boost::shared_ptr<U>(new U(), Deleter()); }
protected:
    static void* operator new(size_t size) { return ::operator new(size); }
};
class Instance : public Creatable<Instance> { public: virtual ~Instance(); };
class Target : public Instance { char data[0x2b0 - 4]; public: Target(); };
template boost::shared_ptr<Target> Creatable<Instance>::create<Target>();
}
