// from server: 100% by Xemicl
// roc 2012-06 00864560  unit: VWiniInetRequest_source::?$stream_buffer  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864560
//
// 00864560  55                   push ebp
// 00864561  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00864565  57                   push edi
// 00864566  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086456a  3bfd                 cmp edi, ebp
// 0086456c  744d                 je 0x8645bb
// 0086456e  53                   push ebx
// 0086456f  8b1de821b200         mov ebx, dword ptr [0xb221e8]
// 00864575  56                   push esi
// 00864576  8b37                 mov esi, dword ptr [edi]
// 00864578  85f6                 test esi, esi
// 0086457a  7436                 je 0x8645b2
// 0086457c  8d4610               lea eax, [esi + 0x10]
// 0086457f  83c9ff               or ecx, 0xffffffff
// 00864582  f00fc108             lock xadd dword ptr [eax], ecx
// 00864586  752a                 jne 0x8645b2
// 00864588  85f6                 test esi, esi
// 0086458a  7426                 je 0x8645b2
// 0086458c  8b4604               mov eax, dword ptr [esi + 4]
// 0086458f  85c0                 test eax, eax
// 00864591  7408                 je 0x86459b
// 00864593  83f8ff               cmp eax, -1
// 00864596  7403                 je 0x86459b
// 00864598  50                   push eax
// 00864599  ffd3                 call ebx
// 0086459b  8b06                 mov eax, dword ptr [esi]
// 0086459d  85c0                 test eax, eax
// 0086459f  7408                 je 0x8645a9
// 008645a1  83f8ff               cmp eax, -1
// 008645a4  7403                 je 0x8645a9
// 008645a6  50                   push eax
// 008645a7  ffd3                 call ebx
// 008645a9  56                   push esi
// 008645aa  e865db1100           call 0x982114
// 008645af  83c404               add esp, 4
// 008645b2  83c704               add edi, 4
// 008645b5  3bfd                 cmp edi, ebp
// 008645b7  75bd                 jne 0x864576
// 008645b9  5e                   pop esi
// 008645ba  5b                   pop ebx
// 008645bb  5f                   pop edi
// 008645bc  5d                   pop ebp
// 008645bd  c3                   ret 
// copied from an identical function in another client (function ??$_Destroy_range@V?$allocator@V?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@@std@@@std@@YAXPAV?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@0AAV?$allocator@V?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@@0@U_Nonscalar_ptr_iterator_tag@0@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
template<class T> class intrusive_ptr {
public:
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
    T* p_;
};
namespace detail {
namespace win32 {
class handle_manager {
    void* handle_to_manage;
    void cleanup() { if (handle_to_manage && handle_to_manage != (void*)-1) CloseHandle(handle_to_manage); }
public:
    ~handle_manager() { cleanup(); }
};
}
class basic_cv_list_entry;
void intrusive_ptr_release(basic_cv_list_entry* p);
class basic_cv_list_entry {
    win32::handle_manager semaphore;
    win32::handle_manager wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_release(basic_cv_list_entry* p);
};
inline void intrusive_ptr_release(basic_cv_list_entry* p)
{
    if (!_InterlockedDecrement(&p->references))
        delete p;
}
}
}
typedef boost::intrusive_ptr<boost::detail::basic_cv_list_entry> entry_ptr;
template void std::_Destroy_range(entry_ptr*, entry_ptr*, std::allocator<entry_ptr>&, std::_Nonscalar_ptr_iterator_tag);