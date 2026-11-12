// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 004b2ee0  unit: RBX::Network::Server::ClientProxy  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b2ee0
//
// 004b2ee0  6aff                 push -1
// 004b2ee2  686e887400           push 0x74886e
// 004b2ee7  64a100000000         mov eax, dword ptr fs:[0]
// 004b2eed  50                   push eax
// 004b2eee  83ec0c               sub esp, 0xc
// 004b2ef1  53                   push ebx
// 004b2ef2  56                   push esi
// 004b2ef3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b2ef8  33c4                 xor eax, esp
// 004b2efa  50                   push eax
// 004b2efb  8d442418             lea eax, [esp + 0x18]
// 004b2eff  64a300000000         mov dword ptr fs:[0], eax
// 004b2f05  8bf1                 mov esi, ecx
// 004b2f07  89742410             mov dword ptr [esp + 0x10], esi
// 004b2f0b  33db                 xor ebx, ebx
// 004b2f0d  891e                 mov dword ptr [esi], ebx
// 004b2f0f  895e04               mov dword ptr [esi + 4], ebx
// 004b2f12  8b442428             mov eax, dword ptr [esp + 0x28]
// 004b2f16  8b10                 mov edx, dword ptr [eax]
// 004b2f18  53                   push ebx
// 004b2f19  83ec08               sub esp, 8
// 004b2f1c  8bcc                 mov ecx, esp
// 004b2f1e  8911                 mov dword ptr [ecx], edx
// 004b2f20  8b4004               mov eax, dword ptr [eax + 4]
// 004b2f23  3bc3                 cmp eax, ebx
// 004b2f25  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004b2f29  89642420             mov dword ptr [esp + 0x20], esp
// 004b2f2d  894104               mov dword ptr [ecx + 4], eax
// 004b2f30  740c                 je 0x4b2f3e
// 004b2f32  83c004               add eax, 4
// 004b2f35  b901000000           mov ecx, 1
// 004b2f3a  f00fc108             lock xadd dword ptr [eax], ecx
// 004b2f3e  8d4e08               lea ecx, [esi + 8]
// 004b2f41  e89af8ffff           call 0x4b27e0
// 004b2f46  6a20                 push 0x20
// 004b2f48  c644242401           mov byte ptr [esp + 0x24], 1
// 004b2f4d  e8a4cf1700           call 0x62fef6
// 004b2f52  83c404               add esp, 4
// 004b2f55  3bc3                 cmp eax, ebx
// 004b2f57  7414                 je 0x4b2f6d
// 004b2f59  895804               mov dword ptr [eax + 4], ebx
// 004b2f5c  895808               mov dword ptr [eax + 8], ebx
// 004b2f5f  89580c               mov dword ptr [eax + 0xc], ebx
// 004b2f62  895814               mov dword ptr [eax + 0x14], ebx
// 004b2f65  895818               mov dword ptr [eax + 0x18], ebx
// 004b2f68  88581c               mov byte ptr [eax + 0x1c], bl
// 004b2f6b  eb02                 jmp 0x4b2f6f
// 004b2f6d  33c0                 xor eax, eax
// 004b2f6f  50                   push eax
// 004b2f70  8bce                 mov ecx, esi
// 004b2f72  c644242401           mov byte ptr [esp + 0x24], 1
// 004b2f77  e83452f6ff           call 0x4181b0
// 004b2f7c  8bce                 mov ecx, esi
// 004b2f7e  e8ad582700           call 0x728830
// 004b2f83  8bc6                 mov eax, esi
// 004b2f85  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b2f89  64890d00000000       mov dword ptr fs:[0], ecx
// 004b2f90  59                   pop ecx
// 004b2f91  5e                   pop esi
// 004b2f92  5b                   pop ebx
// 004b2f93  83c418               add esp, 0x18
// 004b2f96  c20400               ret 4


extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct sp_counted_base {
    void* vptr;
    long use_count_;
};

template <class T> class shared_ptr {
    T* px;
    sp_counted_base* pi;
public:
    shared_ptr() : px(0), pi(0) {}
    shared_ptr(const shared_ptr& r) : px(r.px), pi(r.pi) {
        if (pi != 0) _InterlockedIncrement(&pi->use_count_);
    }
    ~shared_ptr();
    void reset(T* p);          // 0x4181b0, thiscall on this+0
};

struct Peer;

// new 0x20: ctor zeroes +4,+8,+0xc,+0x14,+0x18 (dword) and +0x1c (byte); +0 and +0x10 untouched.
// Modelled as two sub-objects (0x00-0x0f, 0x10-0x1f) with inline ctors and out-of-line dtors.
#include <vector>
typedef std::vector<int> Part0;   // VS2005 vector: allocator at +0, _Myfirst/_Mylast/_Myend at +4/+8/+0xc
struct Part1 {
    int pad0;
    int a4, a8;
    bool bc;
    Part1() : a4(0), a8(0), bc(false) {}
    ~Part1();
};
struct State {
    Part0 p0;
    Part1 p1;
};

struct Member8 {
    Member8(shared_ptr<Peer> peer, void* extra);   // 0x4b27e0, thiscall on this+8
    ~Member8();
};

class ClientProxy {
    shared_ptr<State> state;
    Member8 m8;
public:
    ClientProxy(const shared_ptr<Peer>& peer);
    void start();             // 0x728830
};

ClientProxy::ClientProxy(const shared_ptr<Peer>& peer)
    : state(), m8(peer, 0)
{
    state.reset(new State());
    start();
}
