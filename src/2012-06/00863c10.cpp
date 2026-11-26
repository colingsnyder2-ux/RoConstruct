// from server: 100% by Xemicl
// roc 2012-06 00863c10  unit: VWiniInetRequest_source::?$stream_buffer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00863c10
//
// 00863c10  57                   push edi
// 00863c11  8b7c2408             mov edi, dword ptr [esp + 8]
// 00863c15  3b7c240c             cmp edi, dword ptr [esp + 0xc]
// 00863c19  7466                 je 0x863c81
// 00863c1b  53                   push ebx
// 00863c1c  8b1de821b200         mov ebx, dword ptr [0xb221e8]
// 00863c22  55                   push ebp
// 00863c23  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00863c27  56                   push esi
// 00863c28  8b4500               mov eax, dword ptr [ebp]
// 00863c2b  85c0                 test eax, eax
// 00863c2d  740c                 je 0x863c3b
// 00863c2f  8d4810               lea ecx, [eax + 0x10]
// 00863c32  ba01000000           mov edx, 1
// 00863c37  f00fc111             lock xadd dword ptr [ecx], edx
// 00863c3b  8b37                 mov esi, dword ptr [edi]
// 00863c3d  8907                 mov dword ptr [edi], eax
// 00863c3f  85f6                 test esi, esi
// 00863c41  7432                 je 0x863c75
// 00863c43  8d4610               lea eax, [esi + 0x10]
// 00863c46  83c9ff               or ecx, 0xffffffff
// 00863c49  f00fc108             lock xadd dword ptr [eax], ecx
// 00863c4d  7526                 jne 0x863c75
// 00863c4f  8b4604               mov eax, dword ptr [esi + 4]
// 00863c52  85c0                 test eax, eax
// 00863c54  7408                 je 0x863c5e
// 00863c56  83f8ff               cmp eax, -1
// 00863c59  7403                 je 0x863c5e
// 00863c5b  50                   push eax
// 00863c5c  ffd3                 call ebx
// 00863c5e  8b06                 mov eax, dword ptr [esi]
// 00863c60  85c0                 test eax, eax
// 00863c62  7408                 je 0x863c6c
// 00863c64  83f8ff               cmp eax, -1
// 00863c67  7403                 je 0x863c6c
// 00863c69  50                   push eax
// 00863c6a  ffd3                 call ebx
// 00863c6c  56                   push esi
// 00863c6d  e8a2e41100           call 0x982114
// 00863c72  83c404               add esp, 4
// 00863c75  83c704               add edi, 4
// 00863c78  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 00863c7c  75aa                 jne 0x863c28
// 00863c7e  5e                   pop esi
// 00863c7f  5d                   pop ebp
// 00863c80  5b                   pop ebx
// 00863c81  5f                   pop edi
// 00863c82  c3                   ret 
// copied from an identical function in another client (function ??$_Fill@PAV?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@V12@@std@@YAXPAV?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@0ABV12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <xutility>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(intrusive_ptr const& rhs) : p_(rhs.p_) { if (p_ != 0) intrusive_ptr_add_ref(p_); }
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
    intrusive_ptr& operator=(intrusive_ptr const& rhs) { intrusive_ptr(rhs).swap(*this); return *this; }
    void swap(intrusive_ptr& rhs) { T* tmp = p_; p_ = rhs.p_; rhs.p_ = tmp; }
private:
    T* p_;
};
namespace detail { namespace win32 {
typedef void* handle;
class handle_manager {
    handle handle_to_manage;
    void cleanup() {
        if (handle_to_manage && handle_to_manage != (handle)-1) CloseHandle(handle_to_manage);
    }
public:
    ~handle_manager() { cleanup(); }
};
}
class basic_cv_list_entry {
public:
    win32::handle_manager semaphore;
    win32::handle_manager wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_add_ref(basic_cv_list_entry* p) { _InterlockedIncrement(&p->references); }
    friend void intrusive_ptr_release(basic_cv_list_entry* p) { if (!_InterlockedDecrement(&p->references)) delete p; }
};
}
}
typedef boost::intrusive_ptr<boost::detail::basic_cv_list_entry> EP;
template void std::_Fill<EP*, EP>(EP*, EP*, const EP&);