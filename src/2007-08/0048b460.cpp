// from server: 92% by EspClaude
// from server: 51% by colin
// roc 2007-08 0048b460  unit: RBX::VGameSettings::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048b460
//
// 0048b460  55                   push ebp
// 0048b461  8bec                 mov ebp, esp
// 0048b463  6aff                 push -1
// 0048b465  6820727400           push 0x747220
// 0048b46a  64a100000000         mov eax, dword ptr fs:[0]
// 0048b470  50                   push eax
// 0048b471  51                   push ecx
// 0048b472  53                   push ebx
// 0048b473  56                   push esi
// 0048b474  57                   push edi
// 0048b475  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048b47a  33c5                 xor eax, ebp
// 0048b47c  50                   push eax
// 0048b47d  8d45f4               lea eax, [ebp - 0xc]
// 0048b480  64a300000000         mov dword ptr fs:[0], eax
// 0048b486  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048b489  8bf1                 mov esi, ecx
// 0048b48b  6a14                 push 0x14
// 0048b48d  c70600000000         mov dword ptr [esi], 0
// 0048b493  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048b49a  e8574a1a00           call 0x62fef6
// 0048b49f  83c404               add esp, 4
// 0048b4a2  85c0                 test eax, eax
// 0048b4a4  7419                 je 0x48b4bf
// 0048b4a6  b901000000           mov ecx, 1
// 0048b4ab  894804               mov dword ptr [eax + 4], ecx
// 0048b4ae  894808               mov dword ptr [eax + 8], ecx
// 0048b4b1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048b4b4  c70000b07900         mov dword ptr [eax], 0x79b000
// 0048b4ba  89480c               mov dword ptr [eax + 0xc], ecx
// 0048b4bd  eb02                 jmp 0x48b4c1
// 0048b4bf  33c0                 xor eax, eax
// 0048b4c1  8906                 mov dword ptr [esi], eax
// 0048b4c3  8bc6                 mov eax, esi
// 0048b4c5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048b4c8  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b4cf  59                   pop ecx
// 0048b4d0  5f                   pop edi
// 0048b4d1  5e                   pop esi
// 0048b4d2  5b                   pop ebx
// 0048b4d3  8be5                 mov esp, ebp
// 0048b4d5  5d                   pop ebp
// 0048b4d6  c20800               ret 8

namespace boost { namespace detail {
class sp_counted_base {
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* get_deleter(int) = 0;
private:
    long use_count_;
    long weak_count_;
};
template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr; D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int) { return &del; }
};
class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
};
}}
namespace RBX { class GameSettings; struct Deleter { void operator()(GameSettings* p) const; }; }

template<class P, class D> boost::detail::shared_count::shared_count(P p, D d) : pi_(0)
{
    try {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}
template boost::detail::shared_count::shared_count(RBX::GameSettings*, RBX::Deleter);
