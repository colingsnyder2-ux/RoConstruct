// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* d; long a; long b; void* c; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Mutex { public: CRITICAL_SECTION cs; };
class ScopedLock {
    Mutex& m;
public:
    ScopedLock(Mutex& m) : m(m) { EnterCriticalSection(&m.cs); }
    ~ScopedLock() { LeaveCriticalSection(&m.cs); }
};
class TaskScheduler;
class Task {
public:
    virtual ~Task();
    virtual void f1();
    virtual void onAdded(TaskScheduler* s);
};
class TaskList { public: void add(const boost::shared_ptr<Task>& t); };
class TaskScheduler {
public:
    char pad[0x2c];
    Mutex mutex;
    TaskList tasks;
    void add(boost::shared_ptr<Task> task);
};
void TaskScheduler::add(boost::shared_ptr<Task> task)
{
    {
        ScopedLock lock(mutex);
        tasks.add(task);
    }
    task->onAdded(this);
}
}
