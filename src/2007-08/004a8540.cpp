// from server: 79% by EspClaude
// from server: 53% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs roc_claude_6b86010099c7969a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/signals/connection.hpp>

// std::vector<boost::signals::connection> element copy (16-byte elements,
// out-of-line connection copy constructor, rollback on exception).
template boost::signals::connection* std::_Uninit_copy(
	boost::signals::connection* _First, boost::signals::connection* _Last,
	boost::signals::connection* _Dest, std::allocator<boost::signals::connection>& _Al,
	std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
