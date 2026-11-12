// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 004507a0  unit: CRobloxDoc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004507a0
//
// 004507a0  55                   push ebp
// 004507a1  8bec                 mov ebp, esp
// 004507a3  6aff                 push -1
// 004507a5  68800d7400           push 0x740d80
// 004507aa  64a100000000         mov eax, dword ptr fs:[0]
// 004507b0  50                   push eax
// 004507b1  51                   push ecx
// 004507b2  53                   push ebx
// 004507b3  56                   push esi
// 004507b4  57                   push edi
// 004507b5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004507ba  33c5                 xor eax, ebp
// 004507bc  50                   push eax
// 004507bd  8d45f4               lea eax, [ebp - 0xc]
// 004507c0  64a300000000         mov dword ptr fs:[0], eax
// 004507c6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004507c9  8bf1                 mov esi, ecx
// 004507cb  6a14                 push 0x14
// 004507cd  c70600000000         mov dword ptr [esi], 0
// 004507d3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004507da  e817f71d00           call 0x62fef6
// 004507df  83c404               add esp, 4
// 004507e2  85c0                 test eax, eax
// 004507e4  7419                 je 0x4507ff
// 004507e6  b901000000           mov ecx, 1
// 004507eb  894804               mov dword ptr [eax + 4], ecx
// 004507ee  894808               mov dword ptr [eax + 8], ecx
// 004507f1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004507f4  c70070197900         mov dword ptr [eax], 0x791970
// 004507fa  89480c               mov dword ptr [eax + 0xc], ecx
// 004507fd  eb02                 jmp 0x450801
// 004507ff  33c0                 xor eax, eax
// 00450801  8906                 mov dword ptr [esi], eax
// 00450803  8bc6                 mov eax, esi
// 00450805  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00450808  64890d00000000       mov dword ptr fs:[0], ecx
// 0045080f  59                   pop ecx
// 00450810  5f                   pop edi
// 00450811  5e                   pop esi
// 00450812  5b                   pop ebx
// 00450813  8be5                 mov esp, ebp
// 00450815  5d                   pop ebp
// 00450816  c20800               ret 8

// boost 1.34 shared_count(P p, D d) with an empty deleter:
// new sp_counted_impl_pd<P,D> (operator new(0x14)), counts 1/1, ptr at +0xc,
// try/catch(...) { d(p); throw; } (ebp frame with saved esp).

namespace std { class type_info; }

namespace boost {
namespace detail {

class sp_counted_base {
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(std::type_info const& ti) = 0;
private:
    long use_count_;
    long weak_count_;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(std::type_info const&) { return 0; }
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0)
    {
        try {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
    }
};

}
}

struct Node;
struct NodeDeleter {
    void operator()(Node* p) const;
};

template boost::detail::shared_count::shared_count(Node*, NodeDeleter);
