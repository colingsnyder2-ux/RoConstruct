// from server: 100% by EspClaude
// roc 2007-08 00493b70  unit: RBX::Network::VPlayers::?$Notifier  size: 527 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00493b70
//
// 00493b70  6aff                 push -1
// 00493b72  6819807400           push 0x748019
// 00493b77  64a100000000         mov eax, dword ptr fs:[0]
// 00493b7d  50                   push eax
// 00493b7e  83ec10               sub esp, 0x10
// 00493b81  53                   push ebx
// 00493b82  56                   push esi
// 00493b83  57                   push edi
// 00493b84  a188518b00           mov eax, dword ptr [0x8b5188]
// 00493b89  33c4                 xor eax, esp
// 00493b8b  50                   push eax
// 00493b8c  8d442420             lea eax, [esp + 0x20]
// 00493b90  64a300000000         mov dword ptr fs:[0], eax
// 00493b96  8bf1                 mov esi, ecx
// 00493b98  8974241c             mov dword ptr [esp + 0x1c], esi
// 00493b9c  c70654b97900         mov dword ptr [esi], 0x79b954
// 00493ba2  c7460448b97900       mov dword ptr [esi + 4], 0x79b948
// 00493ba9  c7461040b97900       mov dword ptr [esi + 0x10], 0x79b940
// 00493bb0  c7461430b97900       mov dword ptr [esi + 0x14], 0x79b930
// 00493bb7  c7462c20b97900       mov dword ptr [esi + 0x2c], 0x79b920
// 00493bbe  c7464410b97900       mov dword ptr [esi + 0x44], 0x79b910
// 00493bc5  c7465c00b97900       mov dword ptr [esi + 0x5c], 0x79b900
// 00493bcc  c74674f0b87900       mov dword ptr [esi + 0x74], 0x79b8f0
// 00493bd3  c7868c000000e0b87900 mov dword ptr [esi + 0x8c], 0x79b8e0
// 00493bdd  c786e8000000d0b87900 mov dword ptr [esi + 0xe8], 0x79b8d0
// 00493be7  c78600010000c0b87900 mov dword ptr [esi + 0x100], 0x79b8c0
// 00493bf1  c78618010000b4b87900 mov dword ptr [esi + 0x118], 0x79b8b4
// 00493bfb  8b8e40010000         mov ecx, dword ptr [esi + 0x140]
// 00493c01  33db                 xor ebx, ebx
// 00493c03  3bcb                 cmp ecx, ebx
// 00493c05  c744242808000000     mov dword ptr [esp + 0x28], 8
// 00493c0d  7411                 je 0x493c20
// 00493c0f  8b862c010000         mov eax, dword ptr [esi + 0x12c]
// 00493c15  8b11                 mov edx, dword ptr [ecx]
// 00493c17  50                   push eax
// 00493c18  8b82ec000000         mov eax, dword ptr [edx + 0xec]
// 00493c1e  ffd0                 call eax
// 00493c20  899e40010000         mov dword ptr [esi + 0x140], ebx
// 00493c26  899e44010000         mov dword ptr [esi + 0x144], ebx
// 00493c2c  8bbe3c010000         mov edi, dword ptr [esi + 0x13c]
// 00493c32  3bfb                 cmp edi, ebx
// 00493c34  c644242807           mov byte ptr [esp + 0x28], 7
// 00493c39  742a                 je 0x493c65
// 00493c3b  8d4f04               lea ecx, [edi + 4]
// 00493c3e  83caff               or edx, 0xffffffff
// 00493c41  f00fc111             lock xadd dword ptr [ecx], edx
// 00493c45  751e                 jne 0x493c65
// 00493c47  8b07                 mov eax, dword ptr [edi]
// 00493c49  8b5004               mov edx, dword ptr [eax + 4]
// 00493c4c  8bcf                 mov ecx, edi
// 00493c4e  ffd2                 call edx
// 00493c50  8d4708               lea eax, [edi + 8]
// 00493c53  83c9ff               or ecx, 0xffffffff
// 00493c56  f00fc108             lock xadd dword ptr [eax], ecx
// 00493c5a  7509                 jne 0x493c65
// 00493c5c  8b17                 mov edx, dword ptr [edi]
// 00493c5e  8b4208               mov eax, dword ptr [edx + 8]
// 00493c61  8bcf                 mov ecx, edi
// 00493c63  ffd0                 call eax
// 00493c65  8bbe34010000         mov edi, dword ptr [esi + 0x134]
// 00493c6b  3bfb                 cmp edi, ebx
// 00493c6d  c644242806           mov byte ptr [esp + 0x28], 6
// 00493c72  742a                 je 0x493c9e
// 00493c74  8d4f04               lea ecx, [edi + 4]
// 00493c77  83caff               or edx, 0xffffffff
// 00493c7a  f00fc111             lock xadd dword ptr [ecx], edx
// 00493c7e  751e                 jne 0x493c9e
// 00493c80  8b07                 mov eax, dword ptr [edi]
// 00493c82  8b5004               mov edx, dword ptr [eax + 4]
// 00493c85  8bcf                 mov ecx, edi
// 00493c87  ffd2                 call edx
// 00493c89  8d4708               lea eax, [edi + 8]
// 00493c8c  83c9ff               or ecx, 0xffffffff
// 00493c8f  f00fc108             lock xadd dword ptr [eax], ecx
// 00493c93  7509                 jne 0x493c9e
// 00493c95  8b17                 mov edx, dword ptr [edi]
// 00493c97  8b4208               mov eax, dword ptr [edx + 8]
// 00493c9a  8bcf                 mov ecx, edi
// 00493c9c  ffd0                 call eax
// 00493c9e  8b8e2c010000         mov ecx, dword ptr [esi + 0x12c]
// 00493ca4  3bcb                 cmp ecx, ebx
// 00493ca6  c644242805           mov byte ptr [esp + 0x28], 5
// 00493cab  7408                 je 0x493cb5
// 00493cad  8b11                 mov edx, dword ptr [ecx]
// 00493caf  8b02                 mov eax, dword ptr [edx]
// 00493cb1  6a01                 push 1
// 00493cb3  ffd0                 call eax
// 00493cb5  8dbe20010000         lea edi, [esi + 0x120]
// 00493cbb  8bcf                 mov ecx, edi
// 00493cbd  c644242804           mov byte ptr [esp + 0x28], 4
// 00493cc2  e889faffff           call 0x493750
// 00493cc7  8b4704               mov eax, dword ptr [edi + 4]
// 00493cca  50                   push eax
// 00493ccb  e892bf1900           call 0x62fc62
// 00493cd0  895f04               mov dword ptr [edi + 4], ebx
// 00493cd3  8bbe1c010000         mov edi, dword ptr [esi + 0x11c]
// 00493cd9  83c404               add esp, 4
// 00493cdc  3bfb                 cmp edi, ebx
// 00493cde  c644242803           mov byte ptr [esp + 0x28], 3
// 00493ce3  7410                 je 0x493cf5
// 00493ce5  8bcf                 mov ecx, edi
// 00493ce7  e8b4eaffff           call 0x4927a0
// 00493cec  57                   push edi
// 00493ced  e870bf1900           call 0x62fc62
// 00493cf2  83c404               add esp, 4
// 00493cf5  c786180100002cb77900 mov dword ptr [esi + 0x118], 0x79b72c
// 00493cff  c78600010000a4b87900 mov dword ptr [esi + 0x100], 0x79b8a4
// 00493d09  8b8608010000         mov eax, dword ptr [esi + 0x108]
// 00493d0f  3bc3                 cmp eax, ebx
// 00493d11  7409                 je 0x493d1c
// 00493d13  50                   push eax
// 00493d14  e849bf1900           call 0x62fc62
// 00493d19  83c404               add esp, 4
// 00493d1c  899e08010000         mov dword ptr [esi + 0x108], ebx
// 00493d22  899e0c010000         mov dword ptr [esi + 0x10c], ebx
// 00493d28  899e10010000         mov dword ptr [esi + 0x110], ebx
// 00493d2e  c786e800000094b87900 mov dword ptr [esi + 0xe8], 0x79b894
// 00493d38  8b86f0000000         mov eax, dword ptr [esi + 0xf0]
// 00493d3e  3bc3                 cmp eax, ebx
// 00493d40  7409                 je 0x493d4b
// 00493d42  50                   push eax
// 00493d43  e81abf1900           call 0x62fc62
// 00493d48  83c404               add esp, 4
// 00493d4b  8bce                 mov ecx, esi
// 00493d4d  899ef0000000         mov dword ptr [esi + 0xf0], ebx
// 00493d53  899ef4000000         mov dword ptr [esi + 0xf4], ebx
// 00493d59  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 00493d5f  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00493d67  e844c50a00           call 0x5402b0
// 00493d6c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00493d70  64890d00000000       mov dword ptr fs:[0], ecx
// 00493d77  59                   pop ecx
// 00493d78  5f                   pop edi
// 00493d79  5e                   pop esi
// 00493d7a  5b                   pop ebx
// 00493d7b  83c41c               add esp, 0x1c
// 00493d7e  c3                   ret 
// Rewritten as the destructor of a class: base Instance-like A at 0 (9 vptrs, dtor 0x5402b0),
// polymorphic bases at 0xe8 (vector at 0xec, freed _Myfirst 0xf0), 0x100 (vector at 0x104) and 0x118;
// members 0x11c scoped_ptr (dtor 0x4927a0 + delete), 0x120 std::list (clear 0x493750, head +4,
// element dtor 0x4919b0), 0x12c scoped_ptr with virtual dtor, shared_ptrs 0x130 and 0x138,
// raw 0x140 (peer: slot 0xec/4) and 0x144.  Body: peer->DetachPlugin(plugin); peer = 0; 0x144 = 0.
#include <vector>
#include <list>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
template<class T> struct shared_ptr { T* px; shared_count pn; };
template<class T> struct scoped_ptr {
    T* p;
    ~scoped_ptr() { delete p; }
    T* get() const { return p; }
};

struct V0 { virtual void f0(); };
struct V1 { virtual void f1(); int p[2]; };   // 4 -> 0x10
struct V2 { virtual void f2(); };             // 0x10 -> 0x14
struct V3 { virtual void f3(); int p[5]; };   // 0x14 -> 0x2c
struct V4 { virtual void f4(); int p[5]; };   // 0x2c -> 0x44
struct V5 { virtual void f5(); int p[5]; };   // 0x44 -> 0x5c
struct V6 { virtual void f6(); int p[5]; };   // 0x5c -> 0x74
struct V7 { virtual void f7(); int p[5]; };   // 0x74 -> 0x8c
struct V8 { virtual void f8(); int p[22]; };  // 0x8c -> 0xe8
struct A : V0, V1, V2, V3, V4, V5, V6, V7, V8 { A(); ~A(); };

struct B1 { virtual ~B1() {} std::vector<int> v; int pad; };   // 0xe8 -> 0x100
struct B2 { virtual ~B2() {} std::vector<int> v; int pad; };   // 0x100 -> 0x118
struct B3 { virtual ~B3() {} };                                // 0x118

struct Item { ~Item(); };
struct Owned { ~Owned(); };
struct PluginInterface { virtual ~PluginInterface(); };
struct Peer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void DetachPlugin(PluginInterface* p);
};
struct Obj;

struct Players : A, B1, B2, B3 {
    scoped_ptr<Owned> owned;              // 0x11c
    std::list<Item> items;                // 0x120
    scoped_ptr<PluginInterface> plugin;   // 0x12c
    shared_ptr<Obj> s1;                   // 0x130
    shared_ptr<Obj> s2;                   // 0x138
    Peer* peer;                           // 0x140
    void* other;                          // 0x144
    ~Players();
};

Players::~Players()
{
    if (peer)
        peer->DetachPlugin(plugin.get());
    peer = 0;
    other = 0;
}
