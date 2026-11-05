// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// VS2008 std::map<pointer, MarkerItem>::erase(const_iterator) with checked iterators.
// Target-proven only: 4-byte pointer key at node+0xc, 44-byte mapped value at node+0x10
// (_Color/_Isnil at 0x3c/0x3d) whose destructor (004ab8c0) is called out of line.
#include <map>

namespace RBX { namespace Network {
struct MarkerItem
{
	~MarkerItem();
	int storage[11];
};
}}

typedef std::map<void*, RBX::Network::MarkerItem> MarkerMap;
template MarkerMap::iterator MarkerMap::_Mybase::erase(MarkerMap::const_iterator);
