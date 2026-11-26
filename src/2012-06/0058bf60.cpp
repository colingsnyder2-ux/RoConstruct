// from server: 100% by Xemicl
// roc 2012-06 0058bf60  unit: RBX::Network::Replicator  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0058bf60
//
// 0058bf60  56                   push esi
// 0058bf61  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0058bf65  85f6                 test esi, esi
// 0058bf67  742a                 je 0x58bf93
// 0058bf69  8d4604               lea eax, [esi + 4]
// 0058bf6c  83c9ff               or ecx, 0xffffffff
// 0058bf6f  f00fc108             lock xadd dword ptr [eax], ecx
// 0058bf73  751e                 jne 0x58bf93
// 0058bf75  8b16                 mov edx, dword ptr [esi]
// 0058bf77  8b4204               mov eax, dword ptr [edx + 4]
// 0058bf7a  8bce                 mov ecx, esi
// 0058bf7c  ffd0                 call eax
// 0058bf7e  8d4e08               lea ecx, [esi + 8]
// 0058bf81  83caff               or edx, 0xffffffff
// 0058bf84  f00fc111             lock xadd dword ptr [ecx], edx
// 0058bf88  7509                 jne 0x58bf93
// 0058bf8a  8b06                 mov eax, dword ptr [esi]
// 0058bf8c  8b5008               mov edx, dword ptr [eax + 8]
// 0058bf8f  8bce                 mov ecx, esi
// 0058bf91  ffd2                 call edx
// 0058bf93  32c0                 xor al, al
// 0058bf95  5e                   pop esi
// 0058bf96  c20800               ret 8
// copied from an identical function in another client (function ?filter@Replicator@@UAE_NV?$shared_ptr@VItem@@@@@Z)

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) { destroy(); } }
};
template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
class Item;
class Replicator {
public:
    virtual bool filter(shared_ptr<Item> item);
};
bool Replicator::filter(shared_ptr<Item> item) { return false; }