// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-2008-06-dll roc_rtti_fc27c84cd7b01590.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/stream_buffer.hpp>
template class boost::iostreams::basic_gzip_compressor<std::allocator<char> >;
