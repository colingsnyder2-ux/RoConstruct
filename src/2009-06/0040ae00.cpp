// from server: 83% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX { namespace Reflection { namespace Metadata {
class Item {
public:
	virtual ~Item();
	char pad[0x90 - 4];
};
class __declspec(novtable) Class : public Item {
public:
	virtual ~Class();
	std::string name2009;
};
Class::~Class() {}
}}}
