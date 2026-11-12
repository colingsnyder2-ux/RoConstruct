// native-flags: /O2 /GS- /EHsc /MD /I{headers}/../../../tools/libs/zlib-1.2.3 /I{headers}/../../../tools/libs/boost_1_34_1/libs/thread/src
// 2008-06 native Boostbarrier (inactive): upstream tools/libs/boost_1_34_1/libs/thread/src/barrier.cpp, verbatim.
// Copyright (C) 2002-2003
// David Moore, William E. Kempf
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// >>> native-status (generated) -- do not edit >>>
// Boostbarrier | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src fac485cf | roc native-status --write
#include <boost/thread/detail/config.hpp>
#include <boost/thread/barrier.hpp>
#include <string> // see http://article.gmane.org/gmane.comp.lib.boost.devel/106981

namespace boost {

barrier::barrier(unsigned int count)
    : m_threshold(count), m_count(count), m_generation(0)
{
    if (count == 0)
        throw std::invalid_argument("count cannot be zero.");
}

barrier::~barrier()
{
}

bool barrier::wait()
{
    boost::mutex::scoped_lock lock(m_mutex);
    unsigned int gen = m_generation;

    if (--m_count == 0)
    {
        m_generation++;
        m_count = m_threshold;
        m_cond.notify_all();
        return true;
    }

    while (gen == m_generation)
        m_cond.wait(lock);
    return false;
}

} // namespace boost
