// from server: 92% by EspClaude
// from server: 55% by colin
// roc 2007-08 00459f70  unit: RBX::VControllerService::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459f70
//
// 00459f70  55                   push ebp
// 00459f71  8bec                 mov ebp, esp
// 00459f73  6aff                 push -1
// 00459f75  6820227400           push 0x742220
// 00459f7a  64a100000000         mov eax, dword ptr fs:[0]
// 00459f80  50                   push eax
// 00459f81  51                   push ecx
// 00459f82  53                   push ebx
// 00459f83  56                   push esi
// 00459f84  57                   push edi
// 00459f85  a188518b00           mov eax, dword ptr [0x8b5188]
// 00459f8a  33c5                 xor eax, ebp
// 00459f8c  50                   push eax
// 00459f8d  8d45f4               lea eax, [ebp - 0xc]
// 00459f90  64a300000000         mov dword ptr fs:[0], eax
// 00459f96  8965f0               mov dword ptr [ebp - 0x10], esp
// 00459f99  8bf1                 mov esi, ecx
// 00459f9b  6a14                 push 0x14
// 00459f9d  c70600000000         mov dword ptr [esi], 0
// 00459fa3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00459faa  e8475f1d00           call 0x62fef6
// 00459faf  83c404               add esp, 4
// 00459fb2  85c0                 test eax, eax
// 00459fb4  7419                 je 0x459fcf
// 00459fb6  b901000000           mov ecx, 1
// 00459fbb  894804               mov dword ptr [eax + 4], ecx
// 00459fbe  894808               mov dword ptr [eax + 8], ecx
// 00459fc1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00459fc4  c70098367900         mov dword ptr [eax], 0x793698
// 00459fca  89480c               mov dword ptr [eax + 0xc], ecx
// 00459fcd  eb02                 jmp 0x459fd1
// 00459fcf  33c0                 xor eax, eax
// 00459fd1  8906                 mov dword ptr [esi], eax
// 00459fd3  8bc6                 mov eax, esi
// 00459fd5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00459fd8  64890d00000000       mov dword ptr fs:[0], ecx
// 00459fdf  59                   pop ecx
// 00459fe0  5f                   pop edi
// 00459fe1  5e                   pop esi
// 00459fe2  5b                   pop ebx
// 00459fe3  8be5                 mov esp, ebp
// 00459fe5  5d                   pop ebp
// 00459fe6  c20800               ret 8
namespace boost { namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const char&) = 0;
};
template<class P, class D> class sp_counted_base_impl : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_base_impl(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const char&) { return 0; }
};
class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0)
    {
        try {
            pi_ = new sp_counted_base_impl<P, D>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
    }
};
}}
namespace RBX {
class Creator;
struct CreatorDeleter { void operator()(Creator* p) const; };
}
template boost::detail::shared_count::shared_count(RBX::Creator*, RBX::CreatorDeleter);
