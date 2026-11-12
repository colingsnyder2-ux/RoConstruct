// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 44% by colin
// roc 2007-08 0055ff50  unit: RBX::VModelInstance::?$FilteredSelection  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055ff50
//
// 0055ff50  6aff                 push -1
// 0055ff52  68d43d7500           push 0x753dd4
// 0055ff57  64a100000000         mov eax, dword ptr fs:[0]
// 0055ff5d  50                   push eax
// 0055ff5e  64892500000000       mov dword ptr fs:[0], esp
// 0055ff65  51                   push ecx
// 0055ff66  53                   push ebx
// 0055ff67  56                   push esi
// 0055ff68  8bf1                 mov esi, ecx
// 0055ff6a  8d86e8000000         lea eax, [esi + 0xe8]
// 0055ff70  57                   push edi
// 0055ff71  8974240c             mov dword ptr [esp + 0xc], esi
// 0055ff75  c706a4927a00         mov dword ptr [esi], 0x7a92a4
// 0055ff7b  c7460498927a00       mov dword ptr [esi + 4], 0x7a9298
// 0055ff82  c7461090927a00       mov dword ptr [esi + 0x10], 0x7a9290
// 0055ff89  c7461480927a00       mov dword ptr [esi + 0x14], 0x7a9280
// 0055ff90  c7462c70927a00       mov dword ptr [esi + 0x2c], 0x7a9270
// 0055ff97  c7464460927a00       mov dword ptr [esi + 0x44], 0x7a9260
// 0055ff9e  c7465c50927a00       mov dword ptr [esi + 0x5c], 0x7a9250
// 0055ffa5  c7467440927a00       mov dword ptr [esi + 0x74], 0x7a9240
// 0055ffac  c7868c00000030927a00 mov dword ptr [esi + 0x8c], 0x7a9230
// 0055ffb6  c70028927a00         mov dword ptr [eax], 0x7a9228
// 0055ffbc  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0055ffc2  33db                 xor ebx, ebx
// 0055ffc4  3bcb                 cmp ecx, ebx
// 0055ffc6  c744241802000000     mov dword ptr [esp + 0x18], 2
// 0055ffce  7406                 je 0x55ffd6
// 0055ffd0  50                   push eax
// 0055ffd1  e87a25fdff           call 0x532550
// 0055ffd6  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 0055ffdc  3bc3                 cmp eax, ebx
// 0055ffde  7409                 je 0x55ffe9
// 0055ffe0  50                   push eax
// 0055ffe1  e87cfc0c00           call 0x62fc62
// 0055ffe6  83c404               add esp, 4
// 0055ffe9  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 0055ffef  899efc000000         mov dword ptr [esi + 0xfc], ebx
// 0055fff5  899e00010000         mov dword ptr [esi + 0x100], ebx
// 0055fffb  8bbef0000000         mov edi, dword ptr [esi + 0xf0]
// 00560001  3bfb                 cmp edi, ebx
// 00560003  885c2418             mov byte ptr [esp + 0x18], bl
// 00560007  742a                 je 0x560033
// 00560009  8d4704               lea eax, [edi + 4]
// 0056000c  83c9ff               or ecx, 0xffffffff
// 0056000f  f00fc108             lock xadd dword ptr [eax], ecx
// 00560013  751e                 jne 0x560033
// 00560015  8b17                 mov edx, dword ptr [edi]
// 00560017  8b4204               mov eax, dword ptr [edx + 4]
// 0056001a  8bcf                 mov ecx, edi
// 0056001c  ffd0                 call eax
// 0056001e  8d4f08               lea ecx, [edi + 8]
// 00560021  83caff               or edx, 0xffffffff
// 00560024  f00fc111             lock xadd dword ptr [ecx], edx
// 00560028  7509                 jne 0x560033
// 0056002a  8b07                 mov eax, dword ptr [edi]
// 0056002c  8b5008               mov edx, dword ptr [eax + 8]
// 0056002f  8bcf                 mov ecx, edi
// 00560031  ffd2                 call edx
// 00560033  8bce                 mov ecx, esi
// 00560035  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0056003d  e86e02feff           call 0x5402b0
// 00560042  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00560046  5f                   pop edi
// 00560047  5e                   pop esi
// 00560048  5b                   pop ebx
// 00560049  64890d00000000       mov dword ptr fs:[0], ecx
// 00560050  83c410               add esp, 0x10
// 00560053  c3                   ret 

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

template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
    operator bool() const { return px != 0; }
    T* operator->() const { return px; }
};

struct Listener {           // subobject at +0xe8 (vptr only)
    virtual void onEvent();
};

struct Owner {
    void removeListener(Listener* l);   // 0x532550, thiscall
};

// polymorphic bases whose vptrs the target stores at 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c
struct B0 { virtual ~B0(); };
struct B1 { virtual ~B1(); int pad[2]; };
struct B2 { virtual ~B2(); };
struct B3 { virtual ~B3(); int pad[5]; };
struct B4 { virtual ~B4(); int pad[5]; };
struct B5 { virtual ~B5(); int pad[5]; };
struct B6 { virtual ~B6(); int pad[5]; };
struct B7 { virtual ~B7(); int pad[5]; };
struct B8 { virtual ~B8(); int pad[0x16]; };

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8 {
    ~Base();   // 0x5402b0
};

struct FilteredSelection : Base, Listener {
    shared_ptr<Owner> owner;   // +0xec
    std::vector<int> items;    // +0xf4
    ~FilteredSelection();
};

FilteredSelection::~FilteredSelection()
{
    if (owner)
        owner->removeListener(this);
}
