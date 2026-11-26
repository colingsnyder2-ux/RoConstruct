// from server: 100% by Xemicl
// roc 2012-06 00863410  unit: VWiniInetRequest_source::?$stream_buffer  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00863410
//
// 00863410  8bc1                 mov eax, ecx
// 00863412  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00863416  8b11                 mov edx, dword ptr [ecx]
// 00863418  8910                 mov dword ptr [eax], edx
// 0086341a  85d2                 test edx, edx
// 0086341c  740c                 je 0x86342a
// 0086341e  83c210               add edx, 0x10
// 00863421  b901000000           mov ecx, 1
// 00863426  f00fc10a             lock xadd dword ptr [edx], ecx
// 0086342a  c20400               ret 4
// copied from an identical function in another client (function ??0?$intrusive_ptr@Vbasic_cv_list_entry@detail@boost@@@boost@@QAE@ABV01@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(intrusive_ptr const& rhs) : p_(rhs.p_) { if (p_ != 0) intrusive_ptr_add_ref(p_); }
private:
    T* p_;
};
namespace detail {
class basic_cv_list_entry {
public:
    void* semaphore;
    void* wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_add_ref(basic_cv_list_entry* p) { _InterlockedIncrement(&p->references); }
};
}
template class intrusive_ptr<detail::basic_cv_list_entry>;
}