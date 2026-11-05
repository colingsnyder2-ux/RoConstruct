// from server: 100% by auto
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_espeon_boost134package9db0c617824a271b.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/detail/streambuf/indirect_streambuf.hpp>
template class boost::iostreams::detail::indirect_streambuf<boost::iostreams::basic_gzip_decompressor<>,std::char_traits<char>,std::allocator<char>,boost::iostreams::input>;
