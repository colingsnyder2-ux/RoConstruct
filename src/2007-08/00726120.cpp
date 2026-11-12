// from server: 94% by EspClaude
// from server: 64% by Intel
// from server: 63% by colin
// roc-lang: cpp
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_7a1d91d788137100.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
// Copyright (C) 2001-2003 William E. Kempf
// Copyright (C) 2006 Roland Schwarz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/thread/detail/config.hpp>

#include <boost/thread/tss.hpp>
#ifndef BOOST_THREAD_NO_TSS_CLEANUP

#include <boost/thread/once.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/exceptions.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

#if defined(BOOST_HAS_WINTHREADS)
#   include <windows.h>
#   include <boost/thread/detail/tss_hooks.hpp>
#endif

namespace {

typedef std::vector<void*> tss_slots;

struct tss_data_t
{
    boost::mutex mutex;
    std::vector<boost::function1<void, void*>*> cleanup_handlers;
#if defined(BOOST_HAS_WINTHREADS)
    DWORD native_key;
#elif defined(BOOST_HAS_PTHREADS)
    pthread_key_t native_key;
#elif defined(BOOST_HAS_MPTASKS)
    TaskStorageIndex native_key;
#endif
};

tss_data_t* tss_data = 0;
boost::once_flag tss_data_once = BOOST_ONCE_INIT;

extern "C" void cleanup_slots(void* p)
{
    tss_slots* slots = static_cast<tss_slots*>(p);
    for (tss_slots::size_type i = 0; i < slots->size(); ++i)
    {
        boost::mutex::scoped_lock lock(tss_data->mutex);
        (*tss_data->cleanup_handlers[i])((*slots)[i]);
        (*slots)[i] = 0;
    }
}

void init_tss_data()
{
    std::auto_ptr<tss_data_t> temp(new tss_data_t);

#if defined(BOOST_HAS_WINTHREADS)
    //Force the cleanup implementation library to be linked in
    tss_cleanup_implemented();

    //Allocate tls slot
    temp->native_key = TlsAlloc();
    if (temp->native_key == 0xFFFFFFFF)
        return;
#elif defined(BOOST_HAS_PTHREADS)
    int res = pthread_key_create(&temp->native_key, &cleanup_slots);
    if (res != 0)
        return;
#elif defined(BOOST_HAS_MPTASKS)
    OSStatus status = MPAllocateTaskStorageIndex(&temp->native_key);
    if (status != noErr)
        return;
#endif

    tss_data = temp.release();
}

#if defined(BOOST_HAS_WINTHREADS)
tss_slots* get_slots(bool alloc);

void __cdecl tss_thread_exit()
{
    tss_slots* slots = get_slots(false);
    if (slots)
        cleanup_slots(slots);
}
#endif

tss_slots* get_slots(bool alloc)
{
    tss_slots* slots = 0;

#if defined(BOOST_HAS_WINTHREADS)
    slots = static_cast<tss_slots*>(
        TlsGetValue(tss_data->native_key));
#elif defined(BOOST_HAS_PTHREADS)
    slots = static_cast<tss_slots*>(
        pthread_getspecific(tss_data_native_key));
#elif defined(BOOST_HAS_MPTASKS)
    slots = static_cast<tss_slots*>(
        MPGetTaskStorageValue(tss_data_native_key));
#endif

    if (slots == 0 && alloc)
    {
        std::auto_ptr<tss_slots> temp(new tss_slots);

#if defined(BOOST_HAS_WINTHREADS)
        if (at_thread_exit(&tss_thread_exit) == -1)
            return 0;
        if (!TlsSetValue(tss_data->native_key, temp.get()))
            return 0;
#elif defined(BOOST_HAS_PTHREADS)
        if (pthread_setspecific(tss_data_native_key, temp.get()) != 0)
            return 0;
#elif defined(BOOST_HAS_MPTASKS)
        if (MPSetTaskStorageValue(tss_data_native_key, temp.get()) != noErr)
            return 0;
#endif
        slots = temp.release();
    }

    return slots;
}

} // namespace

namespace boost {

namespace detail {
void tss::init(boost::function1<void, void*>* pcleanup)
{
    boost::call_once(&init_tss_data, tss_data_once);
    if (tss_data == 0)
        throw thread_resource_error();
    boost::mutex::scoped_lock lock(tss_data->mutex);
    try
    {
        tss_data->cleanup_handlers.push_back(pcleanup);
        m_slot = tss_data->cleanup_handlers.size() - 1;
    }
    catch (...)
    {
        throw thread_resource_error();
    }
}

void* tss::get() const
{
    tss_slots* slots = get_slots(false);

    if (!slots)
        return 0;

    if (m_slot >= slots->size())
        return 0;

    return (*slots)[m_slot];
}

void tss::set(void* value)
{
    tss_slots* slots = get_slots(true);

    if (!slots)
        throw boost::thread_resource_error();

    if (m_slot >= slots->size())
    {
        try
        {
            slots->resize(m_slot + 1);
        }
        catch (...)
        {
            throw boost::thread_resource_error();
        }
    }

    (*slots)[m_slot] = value;
}

void tss::cleanup(void* value)
{
    boost::mutex::scoped_lock lock(tss_data->mutex);
    (*tss_data->cleanup_handlers[m_slot])(value);
}

} // namespace detail
} // namespace boost

#endif //BOOST_THREAD_NO_TSS_CLEANUP
