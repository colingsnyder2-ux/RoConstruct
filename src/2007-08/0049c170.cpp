// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 0049c170  unit: RBX::Network::VClient::?$BoundFuncDesc  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049c170
//
// 0049c170  6aff                 push -1
// 0049c172  686e887400           push 0x74886e
// 0049c177  64a100000000         mov eax, dword ptr fs:[0]
// 0049c17d  50                   push eax
// 0049c17e  83ec0c               sub esp, 0xc
// 0049c181  53                   push ebx
// 0049c182  56                   push esi
// 0049c183  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049c188  33c4                 xor eax, esp
// 0049c18a  50                   push eax
// 0049c18b  8d442418             lea eax, [esp + 0x18]
// 0049c18f  64a300000000         mov dword ptr fs:[0], eax
// 0049c195  8bf1                 mov esi, ecx
// 0049c197  89742410             mov dword ptr [esp + 0x10], esi
// 0049c19b  33db                 xor ebx, ebx
// 0049c19d  891e                 mov dword ptr [esi], ebx
// 0049c19f  895e04               mov dword ptr [esi + 4], ebx
// 0049c1a2  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049c1a6  8b10                 mov edx, dword ptr [eax]
// 0049c1a8  53                   push ebx
// 0049c1a9  83ec08               sub esp, 8
// 0049c1ac  8bcc                 mov ecx, esp
// 0049c1ae  8911                 mov dword ptr [ecx], edx
// 0049c1b0  8b4004               mov eax, dword ptr [eax + 4]
// 0049c1b3  3bc3                 cmp eax, ebx
// 0049c1b5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0049c1b9  89642420             mov dword ptr [esp + 0x20], esp
// 0049c1bd  894104               mov dword ptr [ecx + 4], eax
// 0049c1c0  740c                 je 0x49c1ce
// 0049c1c2  83c004               add eax, 4
// 0049c1c5  b901000000           mov ecx, 1
// 0049c1ca  f00fc108             lock xadd dword ptr [eax], ecx
// 0049c1ce  8d4e08               lea ecx, [esi + 8]
// 0049c1d1  e8eafeffff           call 0x49c0c0
// 0049c1d6  6a20                 push 0x20
// 0049c1d8  c644242401           mov byte ptr [esp + 0x24], 1
// 0049c1dd  e8143d1900           call 0x62fef6
// 0049c1e2  83c404               add esp, 4
// 0049c1e5  3bc3                 cmp eax, ebx
// 0049c1e7  7414                 je 0x49c1fd
// 0049c1e9  895804               mov dword ptr [eax + 4], ebx
// 0049c1ec  895808               mov dword ptr [eax + 8], ebx
// 0049c1ef  89580c               mov dword ptr [eax + 0xc], ebx
// 0049c1f2  895814               mov dword ptr [eax + 0x14], ebx
// 0049c1f5  895818               mov dword ptr [eax + 0x18], ebx
// 0049c1f8  88581c               mov byte ptr [eax + 0x1c], bl
// 0049c1fb  eb02                 jmp 0x49c1ff
// 0049c1fd  33c0                 xor eax, eax
// 0049c1ff  50                   push eax
// 0049c200  8bce                 mov ecx, esi
// 0049c202  c644242401           mov byte ptr [esp + 0x24], 1
// 0049c207  e8a4bff7ff           call 0x4181b0
// 0049c20c  8bce                 mov ecx, esi
// 0049c20e  e81dc62800           call 0x728830
// 0049c213  8bc6                 mov eax, esi
// 0049c215  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0049c219  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c220  59                   pop ecx
// 0049c221  5e                   pop esi
// 0049c222  5b                   pop ebx
// 0049c223  83c418               add esp, 0x18
// 0049c226  c20400               ret 4


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
    Member8(shared_ptr<Peer> peer, void* extra);   // 0x49c0c0, thiscall on this+8
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
