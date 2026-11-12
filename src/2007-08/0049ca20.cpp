// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0049ca20  unit: RBX::Network::Server::ClientProxy  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049ca20
//
// 0049ca20  55                   push ebp
// 0049ca21  8bec                 mov ebp, esp
// 0049ca23  6aff                 push -1
// 0049ca25  68c08f7400           push 0x748fc0
// 0049ca2a  64a100000000         mov eax, dword ptr fs:[0]
// 0049ca30  50                   push eax
// 0049ca31  51                   push ecx
// 0049ca32  53                   push ebx
// 0049ca33  56                   push esi
// 0049ca34  57                   push edi
// 0049ca35  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049ca3a  33c5                 xor eax, ebp
// 0049ca3c  50                   push eax
// 0049ca3d  8d45f4               lea eax, [ebp - 0xc]
// 0049ca40  64a300000000         mov dword ptr fs:[0], eax
// 0049ca46  8965f0               mov dword ptr [ebp - 0x10], esp
// 0049ca49  8bf1                 mov esi, ecx
// 0049ca4b  6a14                 push 0x14
// 0049ca4d  c70600000000         mov dword ptr [esi], 0
// 0049ca53  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0049ca5a  e897341900           call 0x62fef6
// 0049ca5f  83c404               add esp, 4
// 0049ca62  85c0                 test eax, eax
// 0049ca64  7419                 je 0x49ca7f
// 0049ca66  b901000000           mov ecx, 1
// 0049ca6b  894804               mov dword ptr [eax + 4], ecx
// 0049ca6e  894808               mov dword ptr [eax + 8], ecx
// 0049ca71  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0049ca74  c70094c67900         mov dword ptr [eax], 0x79c694
// 0049ca7a  89480c               mov dword ptr [eax + 0xc], ecx
// 0049ca7d  eb02                 jmp 0x49ca81
// 0049ca7f  33c0                 xor eax, eax
// 0049ca81  8906                 mov dword ptr [esi], eax
// 0049ca83  8bc6                 mov eax, esi
// 0049ca85  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049ca88  64890d00000000       mov dword ptr fs:[0], ecx
// 0049ca8f  59                   pop ecx
// 0049ca90  5f                   pop edi
// 0049ca91  5e                   pop esi
// 0049ca92  5b                   pop ebx
// 0049ca93  8be5                 mov esp, ebp

// boost 1.34 shared_count(P p, D d): try { pi_ = new sp_counted_impl_pd<P,D>(p, d); } catch(...) { d(p); throw; }
// new size 0x14 = vptr + use_count + weak_count + ptr + deleter.
class sp_counted_base {
    int use_count_;
    int weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int) = 0;
};

struct Object;

struct Deleter { void operator()(Object* p); };  // funclet at 0049ca99: lea ecx,[ebp+0xc]; call (thiscall)

class sp_counted_impl_pd : public sp_counted_base {
    Object* ptr;
    Deleter del;
public:
    sp_counted_impl_pd(Object* p, Deleter d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int) { return &del; }
};

class shared_count {
    sp_counted_base* pi_;
public:
    shared_count(Object* p, Deleter d);
};

shared_count::shared_count(Object* p, Deleter d) : pi_(0) {
    try {
        pi_ = new sp_counted_impl_pd(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}
