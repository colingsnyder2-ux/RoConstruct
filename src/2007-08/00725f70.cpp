// from server: 100% by EspClaude
// from server: 53% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_47ff963daf20202c.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: Boost.Threads tss / tss_hooks as built in the 2007-08 client.
// The target reads the TLS key from [tss_data + 0x18] (struct: mutex 8 + vector 16 + key),
// and allocates an 8-byte boost::mutex for the thread-monitor mutex (push 8), i.e. the
// older single-struct tss_data layout rather than 1.34.1's separate globals.
#include <boost/thread/detail/config.hpp>
#include <boost/thread/tss.hpp>
#include <boost/thread/once.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/exceptions.hpp>
#include <vector>
#include <memory>
#include <windows.h>
#include <boost/thread/detail/tss_hooks.hpp>

namespace {

typedef std::vector<void*> tss_slots;

struct tss_data_t
{
    boost::mutex mutex;
    std::vector<boost::function1<void, void*>*> cleanup_handlers;
    DWORD native_key;
};

tss_data_t* tss_data = 0;

void __cdecl tss_thread_exit();

tss_slots* get_slots(bool alloc)
{
    tss_slots* slots = 0;

    slots = static_cast<tss_slots*>(
        TlsGetValue(tss_data->native_key));

    if (slots == 0 && alloc)
    {
        std::auto_ptr<tss_slots> temp(new tss_slots);

        if (at_thread_exit(&tss_thread_exit) == -1)
            return 0;
        if (!TlsSetValue(tss_data->native_key, temp.get()))
            return 0;
        slots = temp.release();
    }

    return slots;
}

boost::mutex* threadmon_mutex;
void init_threadmon_mutex(void)
{
    threadmon_mutex = new boost::mutex;
    if (!threadmon_mutex)
        throw boost::thread_resource_error();
}

} // namespace

namespace boost {
namespace detail {

void* tss::get() const
{
    tss_slots* slots = get_slots(false);

    if (!slots)
        return 0;

    if (m_slot >= slots->size())
        return 0;

    return (*slots)[m_slot];
}

} // namespace detail
} // namespace boost

void* roc_keep_init_threadmon_mutex = (void*)&init_threadmon_mutex;
