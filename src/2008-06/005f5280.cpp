// from server: 100% by colin
// from server: 96% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_espeon_boost134packagef99afc2b76029f15.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/detail/closer.hpp>
template struct boost::iostreams::detail::closer<boost::iostreams::symmetric_filter<boost::iostreams::detail::zlib_compressor_impl<>, std::allocator<char> > >;
