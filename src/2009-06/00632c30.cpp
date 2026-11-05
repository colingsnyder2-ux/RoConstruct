// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name { public: std::string name; };
class Guid {
public:
	struct Data {
		const Name* scope;
		int index;
		bool operator<(const Data& other) const;
	};
};
bool Guid::Data::operator<(const Data& other) const
{
	const Name* otherScope = other.scope;
	const Name* thisScope = scope;
	int order = 0;

	if (thisScope != otherScope) {
		order = thisScope->name.compare(otherScope->name);

		if (order != -1 && order != 0) {
			return false;
		}
	}

	if (order == 0) {
		return index < other.index;
	}

	return true;
}
}
