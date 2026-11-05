// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 00438910  unit: ScriptItem  size: 603 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438910
//
// 00438910  6aff                 push -1
// 00438912  68f8fc8400           push 0x84fcf8
// 00438917  64a100000000         mov eax, dword ptr fs:[0]
// 0043891d  50                   push eax
// 0043891e  64892500000000       mov dword ptr fs:[0], esp
// 00438925  83ec34               sub esp, 0x34
// 00438928  53                   push ebx
// 00438929  8bd9                 mov ebx, ecx
// 0043892b  8b8328010000         mov eax, dword ptr [ebx + 0x128]
// 00438931  8b8858020000         mov ecx, dword ptr [eax + 0x258]
// 00438937  8b9040020000         mov edx, dword ptr [eax + 0x240]
// 0043893d  55                   push ebp
// 0043893e  0540020000           add eax, 0x240
// 00438943  56                   push esi
// 00438944  8bb31c010000         mov esi, dword ptr [ebx + 0x11c]
// 0043894a  57                   push edi
// 0043894b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0043894f  894c2428             mov dword ptr [esp + 0x28], ecx
// 00438953  89542424             mov dword ptr [esp + 0x24], edx
// 00438957  3bb320010000         cmp esi, dword ptr [ebx + 0x120]
// 0043895d  7606                 jbe 0x438965
// 0043895f  ff15ace98900         call dword ptr [0x89e9ac]
// 00438965  8bbb10010000         mov edi, dword ptr [ebx + 0x110]
// 0043896b  8bee                 mov ebp, esi
// 0043896d  8bb320010000         mov esi, dword ptr [ebx + 0x120]
// 00438973  897c241c             mov dword ptr [esp + 0x1c], edi
// 00438977  896c2420             mov dword ptr [esp + 0x20], ebp
// 0043897b  89742418             mov dword ptr [esp + 0x18], esi
// 0043897f  39b31c010000         cmp dword ptr [ebx + 0x11c], esi
// 00438985  7606                 jbe 0x43898d
// 00438987  ff15ace98900         call dword ptr [0x89e9ac]
// 0043898d  8b8310010000         mov eax, dword ptr [ebx + 0x110]
// 00438993  89442434             mov dword ptr [esp + 0x34], eax
// 00438997  85ff                 test edi, edi
// 00438999  7406                 je 0x4389a1
// 0043899b  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0043899f  7406                 je 0x4389a7
// 004389a1  ff15ace98900         call dword ptr [0x89e9ac]
// 004389a7  3bee                 cmp ebp, esi
// 004389a9  0f84a7010000         je 0x438b56
// 004389af  85ff                 test edi, edi
// 004389b1  0f8542010000         jne 0x438af9
// 004389b7  ff15ace98900         call dword ptr [0x89e9ac]
// 004389bd  33c0                 xor eax, eax
// 004389bf  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 004389c2  7206                 jb 0x4389ca
// 004389c4  ff15ace98900         call dword ptr [0x89e9ac]
// 004389ca  8b4d00               mov ecx, dword ptr [ebp]
// 004389cd  894c2410             mov dword ptr [esp + 0x10], ecx
// 004389d1  8b8b28010000         mov ecx, dword ptr [ebx + 0x128]
// 004389d7  8d542410             lea edx, [esp + 0x10]
// 004389db  52                   push edx
// 004389dc  8d442430             lea eax, [esp + 0x30]
// 004389e0  81c140020000         add ecx, 0x240
// 004389e6  50                   push eax
// 004389e7  e874bcffff           call 0x434660
// 004389ec  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004389f0  85ff                 test edi, edi
// 004389f2  7406                 je 0x4389fa
// 004389f4  3b7c2424             cmp edi, dword ptr [esp + 0x24]
// 004389f8  7406                 je 0x438a00
// 004389fa  ff15ace98900         call dword ptr [0x89e9ac]
// 00438a00  8b742430             mov esi, dword ptr [esp + 0x30]
// 00438a04  3b742428             cmp esi, dword ptr [esp + 0x28]
// 00438a08  0f8415010000         je 0x438b23
// 00438a0e  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00438a14  85ff                 test edi, edi
// 00438a16  0f85e4000000         jne 0x438b00
// 00438a1c  ffd5                 call ebp
// 00438a1e  33c0                 xor eax, eax
// 00438a20  3b7018               cmp esi, dword ptr [eax + 0x18]
// 00438a23  7502                 jne 0x438a27
// 00438a25  ffd5                 call ebp
// 00438a27  8b5e1c               mov ebx, dword ptr [esi + 0x1c]
// 00438a2a  3b5e20               cmp ebx, dword ptr [esi + 0x20]
// 00438a2d  7602                 jbe 0x438a31
// 00438a2f  ffd5                 call ebp
// 00438a31  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00438a34  85ff                 test edi, edi
// 00438a36  0f85cb000000         jne 0x438b07
// 00438a3c  ff15ace98900         call dword ptr [0x89e9ac]
// 00438a42  3b7718               cmp esi, dword ptr [edi + 0x18]
// 00438a45  7506                 jne 0x438a4d
// 00438a47  ff15ace98900         call dword ptr [0x89e9ac]
// 00438a4d  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00438a50  397e1c               cmp dword ptr [esi + 0x1c], edi
// 00438a53  7606                 jbe 0x438a5b
// 00438a55  ff15ace98900         call dword ptr [0x89e9ac]
// 00438a5b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00438a5e  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00438a62  85ed                 test ebp, ebp
// 00438a64  7406                 je 0x438a6c
// 00438a66  3b6c243c             cmp ebp, dword ptr [esp + 0x3c]
// 00438a6a  7406                 je 0x438a72
// 00438a6c  ff15ace98900         call dword ptr [0x89e9ac]
// 00438a72  3bdf                 cmp ebx, edi
// 00438a74  0f84a1000000         je 0x438b1b
// 00438a7a  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 00438a80  85ed                 test ebp, ebp
// 00438a82  0f8586000000         jne 0x438b0e
// 00438a88  ffd6                 call esi
// 00438a8a  33c0                 xor eax, eax
// 00438a8c  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 00438a8f  7202                 jb 0x438a93
// 00438a91  ffd6                 call esi
// 00438a93  8b03                 mov eax, dword ptr [ebx]
// 00438a95  6a00                 push 0
// 00438a97  68c0ff9d00           push 0x9dffc0
// 00438a9c  6840be9d00           push 0x9dbe40
// 00438aa1  6a00                 push 0
// 00438aa3  50                   push eax
// 00438aa4  e8d1112e00           call 0x719c7a
// 00438aa9  83c414               add esp, 0x14
// 00438aac  85c0                 test eax, eax
// 00438aae  7432                 je 0x438ae2
// 00438ab0  83ec08               sub esp, 8
// 00438ab3  8bd4                 mov edx, esp
// 00438ab5  89642418             mov dword ptr [esp + 0x18], esp
// 00438ab9  50                   push eax
// 00438aba  52                   push edx
// 00438abb  e8f0fe1c00           call 0x6089b0
// 00438ac0  83c408               add esp, 8
// 00438ac3  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00438acb  e826022e00           call 0x718cf6
// 00438ad0  8b4004               mov eax, dword ptr [eax + 4]
// 00438ad3  8bc8                 mov ecx, eax
// 00438ad5  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 00438add  e8eeee0000           call 0x4479d0
// 00438ae2  85ed                 test ebp, ebp
// 00438ae4  7530                 jne 0x438b16
// 00438ae6  ffd6                 call esi
// 00438ae8  33c0                 xor eax, eax
// 00438aea  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 00438aed  7202                 jb 0x438af1
// 00438aef  ffd6                 call esi
// 00438af1  83c308               add ebx, 8
// 00438af4  e969ffffff           jmp 0x438a62
// 00438af9  8b07                 mov eax, dword ptr [edi]
// 00438afb  e9bffeffff           jmp 0x4389bf
// 00438b00  8b07                 mov eax, dword ptr [edi]
// 00438b02  e919ffffff           jmp 0x438a20
// 00438b07  8b3f                 mov edi, dword ptr [edi]
// 00438b09  e934ffffff           jmp 0x438a42
// 00438b0e  8b4500               mov eax, dword ptr [ebp]
// 00438b11  e976ffffff           jmp 0x438a8c
// 00438b16  8b4500               mov eax, dword ptr [ebp]
// 00438b19  ebcf                 jmp 0x438aea
// 00438b1b  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00438b1f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00438b23  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00438b27  85c0                 test eax, eax
// 00438b29  7527                 jne 0x438b52
// 00438b2b  ff15ace98900         call dword ptr [0x89e9ac]
// 00438b31  33c0                 xor eax, eax
// 00438b33  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00438b36  7206                 jb 0x438b3e
// 00438b38  ff15ace98900         call dword ptr [0x89e9ac]
// 00438b3e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00438b42  8b742418             mov esi, dword ptr [esp + 0x18]
// 00438b46  83c504               add ebp, 4
// 00438b49  896c2420             mov dword ptr [esp + 0x20], ebp
// 00438b4d  e945feffff           jmp 0x438997
// 00438b52  8b00                 mov eax, dword ptr [eax]
// 00438b54  ebdd                 jmp 0x438b33
// 00438b56  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00438b5a  5f                   pop edi
// 00438b5b  5e                   pop esi
// 00438b5c  5d                   pop ebp
// 00438b5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00438b64  5b                   pop ebx
// 00438b65  83c440               add esp, 0x40
// 00438b68  c20400               ret 4

// from server: 100% by coldek
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <map>
#include <intrin.h>

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
}
template <class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr() { if (pn) pn->release(); }
    T* get() const { return px; }
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class Script : public Instance {
};
template <class T> boost::shared_ptr<T> shared_from(T* p);
}

class AFX_MODULE_STATE {
public:
    void* pad;
    class CWinApp* m_pCurrentWinApp;
};
AFX_MODULE_STATE* __stdcall AfxGetModuleState();

class CWinApp {
};
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }
class CRobloxApp : public CWinApp {
public:
    void apply(boost::shared_ptr<RBX::Script> script);
};

struct KeyBase { int x; };
struct KeyDerived : KeyBase {};
typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;
typedef std::map<KeyBase*, Instances> InstanceMap;

struct OwnerPrefix { char pad[0x240]; };
struct MapHolder {
    InstanceMap instances;
    InstanceMap::iterator findB(KeyBase* key) { return instances.find(key); }
};
struct Owner : OwnerPrefix, MapHolder {};

class ScriptItem {
public:
    char pad[0x110];
    std::vector<KeyDerived*> keys;
    Owner* owner;
    void open(int);
};

void ScriptItem::open(int)
{
    InstanceMap::iterator mapEnd = owner->instances.end();
    for (std::vector<KeyDerived*>::const_iterator it = keys.begin(), end = keys.end(); it != end; ++it) {
        InstanceMap::iterator found = owner->findB(*it);
        if (found != mapEnd) {
            for (Instances::iterator j = found->second.begin(), jEnd = found->second.end(); j != jEnd; ++j) {
                if (RBX::Script* script = dynamic_cast<RBX::Script*>(j->get()))
                    static_cast<CRobloxApp*>(AfxGetApp())->apply(RBX::shared_from(script));
            }
        }
    }
}
