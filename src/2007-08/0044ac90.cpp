// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0044ac90  unit: CRobloxCommandLineInfo  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ac90
//
// 0044ac90  55                   push ebp
// 0044ac91  8bec                 mov ebp, esp
// 0044ac93  6aff                 push -1
// 0044ac95  68b0ff7300           push 0x73ffb0
// 0044ac9a  64a100000000         mov eax, dword ptr fs:[0]
// 0044aca0  50                   push eax
// 0044aca1  51                   push ecx
// 0044aca2  53                   push ebx
// 0044aca3  56                   push esi
// 0044aca4  57                   push edi
// 0044aca5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044acaa  33c5                 xor eax, ebp
// 0044acac  50                   push eax
// 0044acad  8d45f4               lea eax, [ebp - 0xc]
// 0044acb0  64a300000000         mov dword ptr fs:[0], eax
// 0044acb6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044acb9  8bf1                 mov esi, ecx
// 0044acbb  6a10                 push 0x10
// 0044acbd  c70600000000         mov dword ptr [esi], 0
// 0044acc3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044acca  e827521e00           call 0x62fef6
// 0044accf  83c404               add esp, 4
// 0044acd2  85c0                 test eax, eax
// 0044acd4  7419                 je 0x44acef
// 0044acd6  b901000000           mov ecx, 1
// 0044acdb  894804               mov dword ptr [eax + 4], ecx
// 0044acde  894808               mov dword ptr [eax + 8], ecx
// 0044ace1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0044ace4  c700bc057900         mov dword ptr [eax], 0x7905bc
// 0044acea  89480c               mov dword ptr [eax + 0xc], ecx
// 0044aced  eb02                 jmp 0x44acf1
// 0044acef  33c0                 xor eax, eax
// 0044acf1  8906                 mov dword ptr [esi], eax
// 0044acf3  8bc6                 mov eax, esi
// 0044acf5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0044acf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0044acff  59                   pop ecx
// 0044ad00  5f                   pop edi
// 0044ad01  5e                   pop esi
// 0044ad02  5b                   pop ebx
// 0044ad03  8be5                 mov esp, ebp
// 0044ad05  5d                   pop ebp
// 0044ad06  c20400               ret 4

// boost 1.34 shared_count(Y* p): try { new sp_counted_impl_p<Y>(p) } catch(...) { checked_delete(p); throw; }
// (catch funclet at 0x44ad09 calls checked_delete 0x44a9d0 and rethrows).
namespace std { class type_info; }

// Pointee type is unidentified: its dtor 0x44a5c0 is non-virtual (called directly by
// checked_delete 0x44a9d0); its size and layout are not needed by these bytes.
class CountedObj {
public:
    ~CountedObj();
};

namespace boost {

template<class T> inline void checked_delete(T* x)
{
    typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
    (void)sizeof(type_must_be_complete);
    delete x;
}

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

template<class X> class sp_counted_impl_p : public sp_counted_base {
public:
    explicit sp_counted_impl_p(X* px) : px_(px) {}
    virtual void dispose() { boost::checked_delete(px_); }
    virtual void* get_deleter(std::type_info const&) { return 0; }
private:
    X* px_;
};

class shared_count {
public:
    template<class Y> explicit shared_count(Y* p) : pi_(0)
    {
        try
        {
            pi_ = new sp_counted_impl_p<Y>(p);
        }
        catch (...)
        {
            boost::checked_delete(p);
            throw;
        }
    }
private:
    sp_counted_base* pi_;
};

template shared_count::shared_count(CountedObj* p);

}
}
