// from server: 92% by EspClaude
// from server: 49% by colin
// 0041c8e0  55                   push ebp
// 0041c8e1  8bec                 mov ebp, esp
// 0041c8e3  6aff                 push -1
// 0041c8e5  6890b57300           push 0x73b590
// 0041c8ea  64a100000000         mov eax, dword ptr fs:[0]
// 0041c8f0  50                   push eax
// 0041c8f1  51                   push ecx
// 0041c8f2  53                   push ebx
// 0041c8f3  56                   push esi
// 0041c8f4  57                   push edi
// 0041c8f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c8fa  33c5                 xor eax, ebp
// 0041c8fc  50                   push eax
// 0041c8fd  8d45f4               lea eax, [ebp - 0xc]
// 0041c900  64a300000000         mov dword ptr fs:[0], eax
// 0041c906  8965f0               mov dword ptr [ebp - 0x10], esp
// 0041c909  8bf1                 mov esi, ecx
// 0041c90b  6a14                 push 0x14
// 0041c90d  c70600000000         mov dword ptr [esi], 0
// 0041c913  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041c91a  e8d7352100           call 0x62fef6
// 0041c91f  83c404               add esp, 4
// 0041c922  85c0                 test eax, eax
// 0041c924  7419                 je 0x41c93f
// 0041c926  b901000000           mov ecx, 1
// 0041c92b  894804               mov dword ptr [eax + 4], ecx
// 0041c92e  894808               mov dword ptr [eax + 8], ecx
// 0041c931  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0041c934  c700c47a7800         mov dword ptr [eax], 0x787ac4
// 0041c93a  89480c               mov dword ptr [eax + 0xc], ecx
// 0041c93d  eb02                 jmp 0x41c941
// 0041c93f  33c0                 xor eax, eax
// 0041c941  8906                 mov dword ptr [esi], eax
// 0041c943  8bc6                 mov eax, esi
// 0041c945  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0041c948  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c94f  59                   pop ecx
// 0041c950  5f                   pop edi
// 0041c951  5e                   pop esi
// 0041c952  5b                   pop ebx
// 0041c953  8be5                 mov esp, ebp
// 0041c955  5d                   pop ebp
// 0041c956  c20800               ret 8
// from server: 49% by colin
// roc 2007-08 0041c8e0  unit: RBX::VPartInstance::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c8e0

namespace RBX { class PartInstance; }

namespace boost { namespace detail {

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void*) = 0;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void*) { return 0; }
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

} }

namespace RBX {
struct Deleter { void operator()(PartInstance* p) const; };
}

template boost::detail::shared_count::shared_count(RBX::PartInstance*, RBX::Deleter);
