// from server: 100% by EspClaude
// from server: 55% by colin
// roc 2007-08 004540c0  unit: RBX::VInstance::?$MarshaledListener  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004540c0
//
// 004540c0  83ec0c               sub esp, 0xc
// 004540c3  56                   push esi
// 004540c4  8bf1                 mov esi, ecx
// 004540c6  8b4618               mov eax, dword ptr [esi + 0x18]
// 004540c9  83c02c               add eax, 0x2c
// 004540cc  57                   push edi
// 004540cd  8d4c240c             lea ecx, [esp + 0xc]
// 004540d1  8944240c             mov dword ptr [esp + 0xc], eax
// 004540d5  c644241000           mov byte ptr [esp + 0x10], 0
// 004540da  e89197fcff           call 0x41d870
// 004540df  8b3e                 mov edi, dword ptr [esi]
// 004540e1  83ec08               sub esp, 8
// 004540e4  8d542424             lea edx, [esp + 0x24]
// 004540e8  8bcc                 mov ecx, esp
// 004540ea  89642410             mov dword ptr [esp + 0x10], esp
// 004540ee  52                   push edx
// 004540ef  83c70c               add edi, 0xc
// 004540f2  e8692b0500           call 0x4a6c60
// 004540f7  8b442420             mov eax, dword ptr [esp + 0x20]
// 004540fb  8b17                 mov edx, dword ptr [edi]
// 004540fd  50                   push eax
// 004540fe  8bce                 mov ecx, esi
// 00454100  ffd2                 call edx
// 00454102  807c241000           cmp byte ptr [esp + 0x10], 0
// 00454107  740b                 je 0x454114
// 00454109  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045410d  50                   push eax
// 0045410e  ff15f8d27700         call dword ptr [0x77d2f8]
// 00454114  8b742420             mov esi, dword ptr [esp + 0x20]
// 00454118  85f6                 test esi, esi
// 0045411a  742a                 je 0x454146
// 0045411c  8d4e04               lea ecx, [esi + 4]
// 0045411f  83caff               or edx, 0xffffffff
// 00454122  f00fc111             lock xadd dword ptr [ecx], edx
// 00454126  751e                 jne 0x454146
// 00454128  8b06                 mov eax, dword ptr [esi]
// 0045412a  8b5004               mov edx, dword ptr [eax + 4]
// 0045412d  8bce                 mov ecx, esi
// 0045412f  ffd2                 call edx
// 00454131  8d4608               lea eax, [esi + 8]
// 00454134  83c9ff               or ecx, 0xffffffff
// 00454137  f00fc108             lock xadd dword ptr [eax], ecx
// 0045413b  7509                 jne 0x454146
// 0045413d  8b16                 mov edx, dword ptr [esi]
// 0045413f  8b4208               mov eax, dword ptr [edx + 8]
// 00454142  8bce                 mov ecx, esi
// 00454144  ffd0                 call eax
// 00454146  5f                   pop edi
// 00454147  5e                   pop esi
// 00454148  83c40c               add esp, 0xc
// 0045414b  c20c00               ret 0xc
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r);
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    shared_ptr(const shared_ptr& r);
    T* px;
    detail::shared_count pn;
};
}
namespace RBX {
class Mutex {
public:
    class scoped_lock {
        Mutex& m;
        bool locked;
    public:
        scoped_lock(Mutex& mx) : m(mx), locked(false) { lock(); }
        ~scoped_lock() { if (locked) LeaveCriticalSection((_RTL_CRITICAL_SECTION*)&m); }
        void lock();
    };
};
class Instance;
struct Owner { char pad[0x2c]; Mutex mutex; };
template<class Arg> class MarshaledListener {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void onEvent(int a, boost::shared_ptr<Arg> p);
    void onEventMarshaled(int a, boost::shared_ptr<Arg> p) throw();
    char pad[0x14];
    Owner* owner;
};
template<class Arg> void MarshaledListener<Arg>::onEventMarshaled(int a, boost::shared_ptr<Arg> p) throw()
{
    Mutex::scoped_lock lock(owner->mutex);
    onEvent(a, p);
}
template class MarshaledListener<Instance>;
}
