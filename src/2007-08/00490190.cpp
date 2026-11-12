// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00490190  unit: RBX::Network::Player  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00490190
//
// 00490190  6aff                 push -1
// 00490192  686e887400           push 0x74886e
// 00490197  64a100000000         mov eax, dword ptr fs:[0]
// 0049019d  50                   push eax
// 0049019e  83ec0c               sub esp, 0xc
// 004901a1  53                   push ebx
// 004901a2  56                   push esi
// 004901a3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004901a8  33c4                 xor eax, esp
// 004901aa  50                   push eax
// 004901ab  8d442418             lea eax, [esp + 0x18]
// 004901af  64a300000000         mov dword ptr fs:[0], eax
// 004901b5  8bf1                 mov esi, ecx
// 004901b7  89742410             mov dword ptr [esp + 0x10], esi
// 004901bb  33db                 xor ebx, ebx
// 004901bd  891e                 mov dword ptr [esi], ebx
// 004901bf  895e04               mov dword ptr [esi + 4], ebx
// 004901c2  8b442428             mov eax, dword ptr [esp + 0x28]
// 004901c6  8b10                 mov edx, dword ptr [eax]
// 004901c8  53                   push ebx
// 004901c9  83ec08               sub esp, 8
// 004901cc  8bcc                 mov ecx, esp
// 004901ce  8911                 mov dword ptr [ecx], edx
// 004901d0  8b4004               mov eax, dword ptr [eax + 4]
// 004901d3  3bc3                 cmp eax, ebx
// 004901d5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004901d9  89642420             mov dword ptr [esp + 0x20], esp
// 004901dd  894104               mov dword ptr [ecx + 4], eax
// 004901e0  740c                 je 0x4901ee
// 004901e2  83c004               add eax, 4
// 004901e5  b901000000           mov ecx, 1
// 004901ea  f00fc108             lock xadd dword ptr [eax], ecx
// 004901ee  8d4e08               lea ecx, [esi + 8]
// 004901f1  e8aafcffff           call 0x48fea0
// 004901f6  6a20                 push 0x20
// 004901f8  c644242401           mov byte ptr [esp + 0x24], 1
// 004901fd  e8f4fc1900           call 0x62fef6
// 00490202  83c404               add esp, 4
// 00490205  3bc3                 cmp eax, ebx
// 00490207  7414                 je 0x49021d
// 00490209  895804               mov dword ptr [eax + 4], ebx
// 0049020c  895808               mov dword ptr [eax + 8], ebx
// 0049020f  89580c               mov dword ptr [eax + 0xc], ebx
// 00490212  895814               mov dword ptr [eax + 0x14], ebx
// 00490215  895818               mov dword ptr [eax + 0x18], ebx
// 00490218  88581c               mov byte ptr [eax + 0x1c], bl
// 0049021b  eb02                 jmp 0x49021f
// 0049021d  33c0                 xor eax, eax
// 0049021f  50                   push eax
// 00490220  8bce                 mov ecx, esi
// 00490222  c644242401           mov byte ptr [esp + 0x24], 1
// 00490227  e8847ff8ff           call 0x4181b0
// 0049022c  8bce                 mov ecx, esi
// 0049022e  e8fd852900           call 0x728830
// 00490233  8bc6                 mov eax, esi
// 00490235  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00490239  64890d00000000       mov dword ptr fs:[0], ecx
// 00490240  59                   pop ecx
// 00490241  5e                   pop esi
// 00490242  5b                   pop ebx
// 00490243  83c418               add esp, 0x18
// 00490246  c20400               ret 4
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
struct Link2 {
    int a, b;
    Link2(boost::shared_ptr<Peer> peer, void* owner);
    ~Link2();
};
class Player2 {
    boost::shared_ptr<State> state;
    Link2 link;
    void init();
public:
    Player2(const boost::shared_ptr<Peer>& peer);
};
Player2::Player2(const boost::shared_ptr<Peer>& peer)
    : link(peer, 0)
{
    state.reset(new State);
    init();
}
}}
