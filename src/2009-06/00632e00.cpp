// from server: 100% by EspClaude
// roc 2009-06 00632e00  RBX::Guid::Data::readableString (2009 Name = {std::string})
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <algorithm>
#include <stdio.h>
namespace RBX {
class Name { public: std::string name; };
class Guid {
public:
	struct Data {
		const Name* scope;
		int index;
		std::string readableString(int scopeLength) const;
	};
};
std::string Guid::Data::readableString(int scopeLength) const
{
	char buffer[64];

	if (scopeLength > 0) {
		std::string s = scope->name;

		s = s.substr(std::min<size_t>(3, s.size()), std::min(scopeLength, 32));

		sprintf(buffer, "%s_%d", s.c_str(), index);
	}
	else {
		sprintf(buffer, "%d", index);
	}

	return std::string(buffer);
}
}
