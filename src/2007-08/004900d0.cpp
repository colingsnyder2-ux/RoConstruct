// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 004900d0  unit: RBX::Network::Player  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004900d0
//
// 004900d0  6aff                 push -1
// 004900d2  686e887400           push 0x74886e
// 004900d7  64a100000000         mov eax, dword ptr fs:[0]
// 004900dd  50                   push eax
// 004900de  83ec0c               sub esp, 0xc
// 004900e1  53                   push ebx
// 004900e2  56                   push esi
// 004900e3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004900e8  33c4                 xor eax, esp
// 004900ea  50                   push eax
// 004900eb  8d442418             lea eax, [esp + 0x18]
// 004900ef  64a300000000         mov dword ptr fs:[0], eax
// 004900f5  8bf1                 mov esi, ecx
// 004900f7  89742410             mov dword ptr [esp + 0x10], esi
// 004900fb  33db                 xor ebx, ebx
// 004900fd  891e                 mov dword ptr [esi], ebx
// 004900ff  895e04               mov dword ptr [esi + 4], ebx
// 00490102  8b442428             mov eax, dword ptr [esp + 0x28]
// 00490106  8b10                 mov edx, dword ptr [eax]
// 00490108  53                   push ebx
// 00490109  83ec08               sub esp, 8
// 0049010c  8bcc                 mov ecx, esp
// 0049010e  8911                 mov dword ptr [ecx], edx
// 00490110  8b4004               mov eax, dword ptr [eax + 4]
// 00490113  3bc3                 cmp eax, ebx
// 00490115  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00490119  89642420             mov dword ptr [esp + 0x20], esp
// 0049011d  894104               mov dword ptr [ecx + 4], eax
// 00490120  740c                 je 0x49012e
// 00490122  83c004               add eax, 4
// 00490125  b901000000           mov ecx, 1
// 0049012a  f00fc108             lock xadd dword ptr [eax], ecx
// 0049012e  8d4e08               lea ecx, [esi + 8]
// 00490131  e8bafcffff           call 0x48fdf0
// 00490136  6a20                 push 0x20
// 00490138  c644242401           mov byte ptr [esp + 0x24], 1
// 0049013d  e8b4fd1900           call 0x62fef6
// 00490142  83c404               add esp, 4
// 00490145  3bc3                 cmp eax, ebx
// 00490147  7414                 je 0x49015d
// 00490149  895804               mov dword ptr [eax + 4], ebx
// 0049014c  895808               mov dword ptr [eax + 8], ebx
// 0049014f  89580c               mov dword ptr [eax + 0xc], ebx
// 00490152  895814               mov dword ptr [eax + 0x14], ebx
// 00490155  895818               mov dword ptr [eax + 0x18], ebx
// 00490158  88581c               mov byte ptr [eax + 0x1c], bl
// 0049015b  eb02                 jmp 0x49015f
// 0049015d  33c0                 xor eax, eax
// 0049015f  50                   push eax
// 00490160  8bce                 mov ecx, esi
// 00490162  c644242401           mov byte ptr [esp + 0x24], 1
// 00490167  e84480f8ff           call 0x4181b0
// 0049016c  8bce                 mov ecx, esi
// 0049016e  e8bd862900           call 0x728830
// 00490173  8bc6                 mov eax, esi
// 00490175  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00490179  64890d00000000       mov dword ptr fs:[0], ecx
// 00490180  59                   pop ecx
// 00490181  5e                   pop esi
// 00490182  5b                   pop ebx
// 00490183  83c418               add esp, 0x18
// 00490186  c20400               ret 4
// roc: ctor: shared_ptr member at +0 (default), member at +8 built from (shared_ptr by value, 0),
//      then member0.reset(new 0x20 object) (out-of-line), then an out-of-line init call on this.
#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release();
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0) {}
    template<class Y> void reset(Y* p);
};
}
namespace RBX { namespace Network {
class Peer;
struct Tail {
    int alloc;
    int* first;
    int* last;
    bool flag;
    Tail() : first(0), last(0), flag(false) {}
    ~Tail();
};
struct State {
    std::vector<int> seq;
    Tail tail;
};
struct Link {
    int a, b;
    Link(boost::shared_ptr<Peer> peer, void* owner);
    ~Link();
};
class Player {
    boost::shared_ptr<State> state;
    Link link;
    void init();
public:
    Player(const boost::shared_ptr<Peer>& peer);
};
Player::Player(const boost::shared_ptr<Peer>& peer)
    : link(peer, 0)
{
    state.reset(new State);
    init();
}
}}
