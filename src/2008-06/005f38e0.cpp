// from server: 100% by auto
// from server: 85% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_unit_9ef8423e6ab5aac9.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#define _DLL
#include <string>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/detail/closer.hpp>
template class boost::iostreams::detail::external_device_closer<boost::reference_wrapper<boost::iostreams::filtering_ostream> >;
