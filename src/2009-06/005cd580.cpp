// from server: 100% by EspClaude
// roc 2009-06 005cd580  RBX::Name::NamMap::~NamMap (2009 Name = {std::string} only)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <string>
namespace RBX {
class Name {
public:
	std::string name;
	class NamMap;
};
class Name::NamMap : public std::map<std::string, Name*>
{
public:
	~NamMap();
};
Name::NamMap::~NamMap()
{
	for (iterator iter = begin(); iter != end(); ++iter) {
		delete iter->second;
	}
}
}
