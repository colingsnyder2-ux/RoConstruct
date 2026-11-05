// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost { namespace detail {
class sp_counted_base { long use_count_; long weak_count_; public:
 virtual ~sp_counted_base(); virtual void dispose() = 0; virtual void destroy();
 void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); } };
} }
struct WeakCount { boost::detail::sp_counted_base* pi_; };
extern WeakCount g_weak_00894860;
void __cdecl dtor_00894860() { if (g_weak_00894860.pi_) g_weak_00894860.pi_->weak_release(); }
