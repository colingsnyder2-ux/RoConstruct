// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 0051db50  unit: RBX::Network::P8Player::?$GetSetImpl  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051db50
//
// 0051db50  6aff                 push -1
// 0051db52  6808b1aa00           push 0xaab108
// 0051db57  64a100000000         mov eax, dword ptr fs:[0]
// 0051db5d  50                   push eax
// 0051db5e  64892500000000       mov dword ptr fs:[0], esp
// 0051db65  51                   push ecx
// 0051db66  56                   push esi
// 0051db67  8bf1                 mov esi, ecx
// 0051db69  89742404             mov dword ptr [esp + 4], esi
// 0051db6d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0051db70  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051db78  85c9                 test ecx, ecx
// 0051db7a  7413                 je 0x51db8f
// 0051db7c  8d4108               lea eax, [ecx + 8]
// 0051db7f  83caff               or edx, 0xffffffff
// 0051db82  f00fc110             lock xadd dword ptr [eax], edx
// 0051db86  7507                 jne 0x51db8f
// 0051db88  8b01                 mov eax, dword ptr [ecx]
// 0051db8a  8b5008               mov edx, dword ptr [eax + 8]
// 0051db8d  ffd2                 call edx
// 0051db8f  8bce                 mov ecx, esi
// 0051db91  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0051db99  e842edffff           call 0x51c8e0
// 0051db9e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051dba2  5e                   pop esi
// 0051dba3  64890d00000000       mov dword ptr fs:[0], ecx
// 0051dbaa  83c410               add esp, 0x10
// 0051dbad  c3                   ret 

// copied from an identical function in another client (function ??1Item@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
}
namespace RBX {
class Instance;
class PartInstance;
struct ExeString { char d[0x10]; ~ExeString(); };
struct ItemBase {
    ExeString name;
    boost::weak_ptr<Instance> owner;
    ~ItemBase();
};
struct Item : ItemBase {
    boost::weak_ptr<PartInstance> part;
    ~Item();
};
Item::~Item() {}
}
