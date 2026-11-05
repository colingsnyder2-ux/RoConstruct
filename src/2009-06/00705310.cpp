// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(volatile long*, long);
extern "C" __declspec(dllimport) int __stdcall SwitchToThread();
struct lightweight_mutex {
    volatile long lock;
    volatile unsigned long owner;
};
class scoped_lock {
    bool recursive;
    lightweight_mutex* m;
public:
    explicit scoped_lock(lightweight_mutex& mx);
};
scoped_lock::scoped_lock(lightweight_mutex& mx) : m(&mx)
{
    unsigned long tid = GetCurrentThreadId();
    recursive = (tid == mx.owner);
    if (!recursive) {
        while (InterlockedExchange(&mx.lock, 1) != 0) {
            while (mx.lock != 0)
                SwitchToThread();
        }
        mx.owner = tid;
    }
}
