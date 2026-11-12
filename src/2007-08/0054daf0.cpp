// from server: 100% by EspClaude
// from server: 80% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_049bf4ed8f070094.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: boost::iostreams::detail::optional<T>::reset() for an 8-byte T whose only
// non-trivial member is a boost::shared_ptr (bool initialized_ at +8, shared_count pi_ at +4).
#include "boost/shared_ptr.hpp"
#include "boost/iostreams/detail/optional.hpp"

template class boost::iostreams::detail::optional< boost::shared_ptr<int> >;
