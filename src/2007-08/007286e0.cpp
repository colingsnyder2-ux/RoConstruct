// from server: 92% by EspClaude
// from server: 48% by colin
// roc 2007-08 007286e0  unit: boost::signals::detail::Vsignal_base_impl::?$sp_counted_impl_p  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007286e0
//
// 007286e0  55                   push ebp
// 007286e1  8bec                 mov ebp, esp
// 007286e3  6aff                 push -1
// 007286e5  6850ba7600           push 0x76ba50
// 007286ea  64a100000000         mov eax, dword ptr fs:[0]
// 007286f0  50                   push eax
// 007286f1  51                   push ecx
// 007286f2  53                   push ebx
// 007286f3  56                   push esi
// 007286f4  57                   push edi
// 007286f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 007286fa  33c5                 xor eax, ebp
// 007286fc  50                   push eax
// 007286fd  8d45f4               lea eax, [ebp - 0xc]
// 00728700  64a300000000         mov dword ptr fs:[0], eax
// 00728706  8965f0               mov dword ptr [ebp - 0x10], esp
// 00728709  8bf1                 mov esi, ecx
// 0072870b  6a10                 push 0x10
// 0072870d  c70600000000         mov dword ptr [esi], 0
// 00728713  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0072871a  e8d777f0ff           call 0x62fef6
// 0072871f  83c404               add esp, 4
// 00728722  85c0                 test eax, eax
// 00728724  7419                 je 0x72873f
// 00728726  b901000000           mov ecx, 1
// 0072872b  894804               mov dword ptr [eax + 4], ecx
// 0072872e  894808               mov dword ptr [eax + 8], ecx
// 00728731  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00728734  c700a4517e00         mov dword ptr [eax], 0x7e51a4
// 0072873a  89480c               mov dword ptr [eax + 0xc], ecx
// 0072873d  eb02                 jmp 0x728741
// 0072873f  33c0                 xor eax, eax
// 00728741  8906                 mov dword ptr [esi], eax
// 00728743  8bc6                 mov eax, esi
// 00728745  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00728748  64890d00000000       mov dword ptr fs:[0], ecx
// 0072874f  59                   pop ecx
// 00728750  5f                   pop edi
// 00728751  5e                   pop esi
// 00728752  5b                   pop ebx
// 00728753  8be5                 mov esp, ebp
// 00728755  5d                   pop ebp
// 00728756  c20400               ret 4

// boost 1.34 shared_count(Y* p) shape: pi_(0); try { pi_ = new sp_counted_impl_p<Y>(p); } catch(...) { delete p; throw; }
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const type_info&) = 0;
};

struct Vsignal_base_impl { ~Vsignal_base_impl(); };

template<class X> class sp_counted_impl_p : public sp_counted_base {
    X* px_;
public:
    explicit sp_counted_impl_p(X* px) : px_(px) {}
    virtual void dispose() { delete px_; }
    virtual void* get_deleter(const type_info&) { return 0; }
};

template<class T> void checked_delete(T* x);

class shared_count {
    sp_counted_base* pi_;
public:
    template<class Y> explicit shared_count(Y* p) : pi_(0)
    {
        try {
            pi_ = new sp_counted_impl_p<Y>(p);
        } catch (...) {
            checked_delete(p);
            throw;
        }
    }
};

template shared_count::shared_count(Vsignal_base_impl*);
