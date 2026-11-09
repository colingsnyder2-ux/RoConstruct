// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-2008-06-dll roc_rtti_8be15fbf9b64785c.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/filtering_stream.hpp>
template class boost::iostreams::detail::filtering_stream_base<boost::iostreams::chain<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char> >,boost::iostreams::public_>;
