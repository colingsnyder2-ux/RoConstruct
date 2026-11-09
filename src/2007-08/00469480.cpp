// from server: 100% by EspClaude
// roc 2007-08 00469480  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 82 bytes
// std::string::const_iterator::operator+= (VS2005 checked iterator), basic_string imported from MSVCP80.
// roc-flags: /O2 /Ob0 /GS /EHsc /MD
#include <string>
typedef std::_String_const_iterator<char, std::char_traits<char>, std::allocator<char> > It;
template It& It::operator+=(It::difference_type);
