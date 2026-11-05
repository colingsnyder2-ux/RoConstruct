// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <exception>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
class thread_exception : public std::exception {
protected:
    thread_exception();
    int m_sys_err;
};
class lock_error : public thread_exception {
public:
    lock_error();
};
namespace detail {
struct basic_timed_mutex {
    static const unsigned char lock_flag_bit = 31;
    static const unsigned char event_set_flag_bit = 30;
    static const long lock_flag_value = 1 << lock_flag_bit;
    static const long event_set_flag_value = 1 << event_set_flag_bit;
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = lock_flag_value;
        long const old_count = _InterlockedExchangeAdd(&active_count, lock_flag_value);
        if (!(old_count & event_set_flag_value) && (old_count > offset))
        {
            if (!_interlockedbittestandset(&active_count, event_set_flag_bit))
            {
                SetEvent(get_event());
            }
        }
    }
};
}
template<typename Mutex> class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    void unlock()
    {
        if (!is_locked) throw boost::lock_error();
        m->unlock();
        is_locked = false;
    }
};
template class unique_lock<detail::basic_timed_mutex>;
}
