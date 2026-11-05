// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-2008-06-dll roc_rtti_b7cc3f484797ef8c.cpp

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
template class boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>;
