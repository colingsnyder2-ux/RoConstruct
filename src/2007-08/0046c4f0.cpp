// from server: 100% by EspClaude
// roc 2007-08 0046c4f0  std::string::const_iterator member (VS2005 checked iterator), basic_string imported from MSVCP80.
// roc-flags: /O2 /Ob0 /GS /EHsc /MD
#include <string>
typedef std::_String_const_iterator<char, std::char_traits<char>, std::allocator<char> > It;
template It::reference It::operator*() const;
