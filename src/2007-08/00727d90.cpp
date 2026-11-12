// from server: 92% by EspClaude
// from server: 48% by colin
// roc 2007-08 00727d90  unit: boost::thread_resource_error  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00727d90
//
// 00727d90  55                   push ebp
// 00727d91  8bec                 mov ebp, esp
// 00727d93  6aff                 push -1
// 00727d95  6850b97600           push 0x76b950
// 00727d9a  64a100000000         mov eax, dword ptr fs:[0]
// 00727da0  50                   push eax
// 00727da1  51                   push ecx
// 00727da2  53                   push ebx
// 00727da3  56                   push esi
// 00727da4  57                   push edi
// 00727da5  a188518b00           mov eax, dword ptr [0x8b5188]
// 00727daa  33c5                 xor eax, ebp
// 00727dac  50                   push eax
// 00727dad  8d45f4               lea eax, [ebp - 0xc]
// 00727db0  64a300000000         mov dword ptr fs:[0], eax
// 00727db6  8965f0               mov dword ptr [ebp - 0x10], esp
// 00727db9  8bf1                 mov esi, ecx
// 00727dbb  6a10                 push 0x10
// 00727dbd  c70600000000         mov dword ptr [esi], 0
// 00727dc3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00727dca  e82781f0ff           call 0x62fef6
// 00727dcf  83c404               add esp, 4
// 00727dd2  85c0                 test eax, eax
// 00727dd4  7419                 je 0x727def
// 00727dd6  b901000000           mov ecx, 1
// 00727ddb  894804               mov dword ptr [eax + 4], ecx
// 00727dde  894808               mov dword ptr [eax + 8], ecx
// 00727de1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00727de4  c70090517e00         mov dword ptr [eax], 0x7e5190
// 00727dea  89480c               mov dword ptr [eax + 0xc], ecx
// 00727ded  eb02                 jmp 0x727df1
// 00727def  33c0                 xor eax, eax
// 00727df1  8906                 mov dword ptr [esi], eax
// 00727df3  8bc6                 mov eax, esi
// 00727df5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00727df8  64890d00000000       mov dword ptr fs:[0], ecx
// 00727dff  59                   pop ecx
// 00727e00  5f                   pop edi
// 00727e01  5e                   pop esi
// 00727e02  5b                   pop ebx
// 00727e03  8be5                 mov esp, ebp
// 00727e05  5d                   pop ebp
// 00727e06  c20400               ret 4

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

struct month_map { ~month_map(); };

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

template shared_count::shared_count(month_map*);
