// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 00498560  unit: RBX::Network::Players::Plugin  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00498560
//
// 00498560  6aff                 push -1
// 00498562  686e887400           push 0x74886e
// 00498567  64a100000000         mov eax, dword ptr fs:[0]
// 0049856d  50                   push eax
// 0049856e  83ec0c               sub esp, 0xc
// 00498571  53                   push ebx
// 00498572  56                   push esi
// 00498573  a188518b00           mov eax, dword ptr [0x8b5188]
// 00498578  33c4                 xor eax, esp
// 0049857a  50                   push eax
// 0049857b  8d442418             lea eax, [esp + 0x18]
// 0049857f  64a300000000         mov dword ptr fs:[0], eax
// 00498585  8bf1                 mov esi, ecx
// 00498587  89742410             mov dword ptr [esp + 0x10], esi
// 0049858b  33db                 xor ebx, ebx
// 0049858d  891e                 mov dword ptr [esi], ebx
// 0049858f  895e04               mov dword ptr [esi + 4], ebx
// 00498592  8b442428             mov eax, dword ptr [esp + 0x28]
// 00498596  8b10                 mov edx, dword ptr [eax]
// 00498598  53                   push ebx
// 00498599  83ec08               sub esp, 8
// 0049859c  8bcc                 mov ecx, esp
// 0049859e  8911                 mov dword ptr [ecx], edx
// 004985a0  8b4004               mov eax, dword ptr [eax + 4]
// 004985a3  3bc3                 cmp eax, ebx
// 004985a5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004985a9  89642420             mov dword ptr [esp + 0x20], esp
// 004985ad  894104               mov dword ptr [ecx + 4], eax
// 004985b0  740c                 je 0x4985be
// 004985b2  83c004               add eax, 4
// 004985b5  b901000000           mov ecx, 1
// 004985ba  f00fc108             lock xadd dword ptr [eax], ecx
// 004985be  8d4e08               lea ecx, [esi + 8]
// 004985c1  e8eafeffff           call 0x4984b0
// 004985c6  6a20                 push 0x20
// 004985c8  c644242401           mov byte ptr [esp + 0x24], 1
// 004985cd  e824791900           call 0x62fef6
// 004985d2  83c404               add esp, 4
// 004985d5  3bc3                 cmp eax, ebx
// 004985d7  7414                 je 0x4985ed
// 004985d9  895804               mov dword ptr [eax + 4], ebx
// 004985dc  895808               mov dword ptr [eax + 8], ebx
// 004985df  89580c               mov dword ptr [eax + 0xc], ebx
// 004985e2  895814               mov dword ptr [eax + 0x14], ebx
// 004985e5  895818               mov dword ptr [eax + 0x18], ebx
// 004985e8  88581c               mov byte ptr [eax + 0x1c], bl
// 004985eb  eb02                 jmp 0x4985ef
// 004985ed  33c0                 xor eax, eax
// 004985ef  50                   push eax
// 004985f0  8bce                 mov ecx, esi
// 004985f2  c644242401           mov byte ptr [esp + 0x24], 1
// 004985f7  e8b4fbf7ff           call 0x4181b0
// 004985fc  8bce                 mov ecx, esi
// 004985fe  e82d022900           call 0x728830
// 00498603  8bc6                 mov eax, esi
// 00498605  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00498609  64890d00000000       mov dword ptr fs:[0], ecx
// 00498610  59                   pop ecx
// 00498611  5e                   pop esi
// 00498612  5b                   pop ebx
// 00498613  83c418               add esp, 0x18
// 00498616  c20400               ret 4
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
namespace RBX { namespace Network { namespace Players_ {
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
class Plugin {
    boost::shared_ptr<State> state;
    Link link;
    void init();
public:
    Plugin(const boost::shared_ptr<Peer>& peer);
};
Plugin::Plugin(const boost::shared_ptr<Peer>& peer)
    : link(peer, 0)
{
    state.reset(new State);
    init();
}
}}}
