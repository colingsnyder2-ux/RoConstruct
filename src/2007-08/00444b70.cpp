// from server: 92% by EspClaude
// roc 2007-08 00444b70  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 492 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444b70
// 00444b70  6aff                 push -1
// 00444b72  68aaf57300           push 0x73f5aa
// 00444b77  64a100000000         mov eax, dword ptr fs:[0]
// 00444b7d  50                   push eax
// 00444b7e  83ec1c               sub esp, 0x1c
// 00444b81  53                   push ebx
// 00444b82  56                   push esi
// 00444b83  a188518b00           mov eax, dword ptr [0x8b5188]
// 00444b88  33c4                 xor eax, esp
// 00444b8a  50                   push eax
// 00444b8b  8d442428             lea eax, [esp + 0x28]
// 00444b8f  64a300000000         mov dword ptr fs:[0], eax
// 00444b95  33db                 xor ebx, ebx
// 00444b97  895c2414             mov dword ptr [esp + 0x14], ebx
// 00444b9b  f6051cba8b0001       test byte ptr [0x8bba1c], 1
// 00444ba2  7520                 jne 0x444bc4
// 00444ba4  830d1cba8b0001       or dword ptr [0x8bba1c], 1
// 00444bab  68907a7700           push 0x777a90
// 00444bb0  891d14ba8b00         mov dword ptr [0x8bba14], ebx
// 00444bb6  891d18ba8b00         mov dword ptr [0x8bba18], ebx
// 00444bbc  e862c11e00           call 0x630d23
// 00444bc1  83c404               add esp, 4
// 00444bc4  b9ccba8b00           mov ecx, 0x8bbacc
// 00444bc9  c7442420ccba8b00     mov dword ptr [esp + 0x20], 0x8bbacc
// 00444bd1  e87a0b2e00           call 0x725750
// 00444bd6  c644242401           mov byte ptr [esp + 0x24], 1
// 00444bdb  391d14ba8b00         cmp dword ptr [0x8bba14], ebx
// 00444be1  895c2430             mov dword ptr [esp + 0x30], ebx
// 00444be5  0f8522010000         jne 0x444d0d
// 00444beb  8d442418             lea eax, [esp + 0x18]
// 00444bef  50                   push eax
// 00444bf0  e8ebf9fdff           call 0x4245e0
// 00444bf5  83c404               add esp, 4
// 00444bf8  8b08                 mov ecx, dword ptr [eax]
// 00444bfa  83c004               add eax, 4
// 00444bfd  890d14ba8b00         mov dword ptr [0x8bba14], ecx
// 00444c03  50                   push eax
// 00444c04  b918ba8b00           mov ecx, 0x8bba18
// 00444c09  c644243401           mov byte ptr [esp + 0x34], 1
// 00444c0e  e84ddefbff           call 0x402a60
// 00444c13  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00444c17  3bf3                 cmp esi, ebx
// 00444c19  885c2430             mov byte ptr [esp + 0x30], bl
// 00444c1d  742a                 je 0x444c49
// 00444c1f  8d5604               lea edx, [esi + 4]
// 00444c22  83c8ff               or eax, 0xffffffff
// 00444c25  f00fc102             lock xadd dword ptr [edx], eax
// 00444c29  751e                 jne 0x444c49
// 00444c2b  8b16                 mov edx, dword ptr [esi]
// 00444c2d  8b4204               mov eax, dword ptr [edx + 4]
// 00444c30  8bce                 mov ecx, esi
// 00444c32  ffd0                 call eax
// 00444c34  8d4e08               lea ecx, [esi + 8]
// 00444c37  83caff               or edx, 0xffffffff
// 00444c3a  f00fc111             lock xadd dword ptr [ecx], edx
// 00444c3e  7509                 jne 0x444c49
// 00444c40  8b06                 mov eax, dword ptr [esi]
// 00444c42  8b5008               mov edx, dword ptr [eax + 8]
// 00444c45  8bce                 mov ecx, esi
// 00444c47  ffd2                 call edx
// 00444c49  8d4c2410             lea ecx, [esp + 0x10]
// 00444c4d  ff15acdd7700         call dword ptr [0x77ddac]
// 00444c53  c644243002           mov byte ptr [esp + 0x30], 2
// 00444c58  e8a5b21e00           call 0x62ff02
// 00444c5d  8b4004               mov eax, dword ptr [eax + 4]
// 00444c60  8b5044               mov edx, dword ptr [eax + 0x44]
// 00444c63  8d4c2410             lea ecx, [esp + 0x10]
// 00444c67  51                   push ecx
// 00444c68  52                   push edx
// 00444c69  e8acb21e00           call 0x62ff1a
// 00444c6e  8d4c2410             lea ecx, [esp + 0x10]
// 00444c72  ff1598dd7700         call dword ptr [0x77dd98]
// 00444c78  50                   push eax
// 00444c79  8d4c2410             lea ecx, [esp + 0x10]
// 00444c7d  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00444c83  8d4c240c             lea ecx, [esp + 0xc]
// 00444c87  c644243003           mov byte ptr [esp + 0x30], 3
// 00444c8c  ff15c8dc7700         call dword ptr [0x77dcc8]
// 00444c92  50                   push eax
// 00444c93  8d4c2410             lea ecx, [esp + 0x10]
// 00444c97  ff1560d57700         call dword ptr [0x77d560]
// 00444c9d  50                   push eax
// 00444c9e  ff15d4eb7700         call dword ptr [0x77ebd4]
// 00444ca4  6aff                 push -1
// 00444ca6  8d4c2410             lea ecx, [esp + 0x10]
// 00444caa  ff155cd57700         call dword ptr [0x77d55c]
// 00444cb0  68b0f97800           push 0x78f9b0
// 00444cb5  8d442410             lea eax, [esp + 0x10]
// 00444cb9  50                   push eax
// 00444cba  8d4c241c             lea ecx, [esp + 0x1c]
// 00444cbe  51                   push ecx
// 00444cbf  e83c5dfcff           call 0x40aa00
// 00444cc4  83c40c               add esp, 0xc
// 00444cc7  8bc8                 mov ecx, eax
// 00444cc9  c644243004           mov byte ptr [esp + 0x30], 4
// 00444cce  ff1598dd7700         call dword ptr [0x77dd98]
// 00444cd4  83ec1c               sub esp, 0x1c
// 00444cd7  8bcc                 mov ecx, esp
// 00444cd9  89642434             mov dword ptr [esp + 0x34], esp
// 00444cdd  50                   push eax
// 00444cde  ff1598e67700         call dword ptr [0x77e698]
// 00444ce4  8b0d14ba8b00         mov ecx, dword ptr [0x8bba14]
// 00444cea  e811fcffff           call 0x444900
// 00444cef  8d4c2414             lea ecx, [esp + 0x14]
// 00444cf3  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00444cf9  8d4c240c             lea ecx, [esp + 0xc]
// 00444cfd  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00444d03  8d4c2410             lea ecx, [esp + 0x10]
// 00444d07  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00444d0d  b9ccba8b00           mov ecx, 0x8bbacc
// 00444d12  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00444d1a  e8510a2e00           call 0x725770
// 00444d1f  8b442438             mov eax, dword ptr [esp + 0x38]
// 00444d23  8b1514ba8b00         mov edx, dword ptr [0x8bba14]
// 00444d29  8910                 mov dword ptr [eax], edx
// 00444d2b  8b0d18ba8b00         mov ecx, dword ptr [0x8bba18]
// 00444d31  894804               mov dword ptr [eax + 4], ecx
// 00444d34  8b0d18ba8b00         mov ecx, dword ptr [0x8bba18]
// 00444d3a  3bcb                 cmp ecx, ebx
// 00444d3c  740c                 je 0x444d4a
// 00444d3e  83c104               add ecx, 4
// 00444d41  ba01000000           mov edx, 1
// 00444d46  f00fc111             lock xadd dword ptr [ecx], edx
// 00444d4a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00444d4e  64890d00000000       mov dword ptr fs:[0], ecx
// 00444d55  59                   pop ecx
// 00444d56  5e                   pop esi
// 00444d57  5b                   pop ebx
// 00444d58  83c428               add esp, 0x28
// 00444d5b  c3                   ret 
#include <string>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) int __stdcall PathRemoveFileSpecA(char*);

struct CString;
extern void (__thiscall *CString_construct)(CString*);
extern void (__thiscall *CString_constructFrom)(CString*, const char*);
extern void (__thiscall *CString_destroy)(CString*);
extern const char* (__thiscall *CString_getString)(const CString*);
extern int (__thiscall *CString_getLength)(const CString*);
extern char* (__thiscall *CString_getBuffer)(CString*, int);
extern void (__thiscall *CString_releaseBuffer)(CString*, int);

struct CString {
    char* m_pszData;
    CString() { CString_construct(this); }
    CString(const char* s) { CString_constructFrom(this, s); }
    __declspec(dllimport) ~CString() throw();
    operator const char*() const { return CString_getString(this); }
    int GetLength() const { return CString_getLength(this); }
    char* GetBuffer(int n) { return CString_getBuffer(this, n); }
    void ReleaseBuffer(int n = -1) { CString_releaseBuffer(this, n); }
};
CString __cdecl operator+(const CString&, const char*);

// offsets read from the target: m_pCurrentWinApp at +4, m_hInstance at +0x44
struct CWinApp { char pad[0x44]; void* m_hInstance; };
struct AFX_MODULE_STATE { void* vptr; CWinApp* m_pCurrentWinApp; };
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
void __stdcall AfxGetModuleFileName(void* hInst, CString& name);

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    volatile long use_count_;
    volatile long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    operator bool() const { return px != 0; }
    T* operator->() const { return px; }
};
struct mutex {
    void do_lock();
    void do_unlock();
    struct scoped_lock {
        mutex& m;
        bool locked;
        scoped_lock(mutex& mm) : m(mm), locked(false) { m.do_lock(); locked = true; }
        ~scoped_lock() { if (locked) m.do_unlock(); }
    };
};
}

namespace RBX {
namespace Reflection {
namespace Metadata {

class Reflection {
public:
    static boost::shared_ptr<Reflection> __cdecl create();
    void load(std::string fileName);
    static boost::shared_ptr<Reflection> __cdecl singleton();
    static boost::mutex sync;
};


boost::shared_ptr<Reflection> __cdecl Reflection::singleton()
{
    static boost::shared_ptr<Reflection> instance;
    {
    boost::mutex::scoped_lock lock(sync);
    if (!instance) {
        instance = create();
        CString path;
        void* hInstance = AfxGetModuleState()->m_pCurrentWinApp->m_hInstance;
        AfxGetModuleFileName(hInstance, path);
        CString dir((const char*)path);
        PathRemoveFileSpecA(dir.GetBuffer(dir.GetLength()));
        dir.ReleaseBuffer();
        instance->load(std::string((const char*)(dir + "\\ReflectionMetadata.xml")));
    }
    }
    return instance;
}

}
}
}
