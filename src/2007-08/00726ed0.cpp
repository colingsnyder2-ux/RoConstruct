// from server: 82% by EspClaude
// roc 2007-08 00726ed0  unit: boost::thread_resource_error  size: 222 bytes
// Shape of boost 1.34 libs/thread/src/tss_hooks.cpp on_thread_exit(): call_once,
// scoped_lock on threadmon mutex, TLS handler list, unlock, run+pop handlers, delete list.
#include <list>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);

namespace boost {

typedef long once_flag;
void call_once(void (*func)(), once_flag& flag);

class mutex {
public:
    void do_lock();
    void do_unlock();
};

class scoped_lock {
public:
    explicit scoped_lock(mutex& mx) : m_mutex(mx) { lock(); }
    ~scoped_lock() { if (m_locked) m_mutex.do_unlock(); }
    void lock();
    void unlock();
private:
    mutex& m_mutex;
    bool m_locked;
};

inline void scoped_lock::lock()
{
    m_mutex.do_lock();
    m_locked = true;
}

}

typedef void (__cdecl *thread_exit_handler)(void);
typedef std::list<thread_exit_handler> thread_exit_handlers;

extern boost::once_flag once_init_threadmon_mutex;
extern boost::mutex* threadmon_mutex;
extern unsigned long tss_data_cleanup_handlers_tls;
extern long attached_thread_count;
void init_threadmon_mutex(void);

extern "C" void on_thread_exit(void)
{
    boost::call_once(init_threadmon_mutex, once_init_threadmon_mutex);
    boost::scoped_lock lock(*threadmon_mutex);

    if (tss_data_cleanup_handlers_tls == 0xFFFFFFFF)
        return;

    thread_exit_handlers* exit_handlers =
        static_cast<thread_exit_handlers*>(TlsGetValue(tss_data_cleanup_handlers_tls));
    if (!exit_handlers)
        return;

    if (!TlsSetValue(tss_data_cleanup_handlers_tls, 0))
        return;

    --attached_thread_count;

    lock.unlock();

    while (!exit_handlers->empty()) {
        if (thread_exit_handler exit_handler = *exit_handlers->begin())
            (*exit_handler)();
        exit_handlers->pop_front();
    }
    delete exit_handlers;
}
