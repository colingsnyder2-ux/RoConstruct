// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
namespace RBX {
class Primitive;
class Contact {
public:
	virtual ~Contact();
	char pad[0xc];
	Primitive* primitive[2];
	Primitive* otherPrimitive(const Primitive* p) const { return p == primitive[0] ? primitive[1] : primitive[0]; }
	bool computeIsColliding(float overlapIgnored);
};
class Primitive {
public:
	Contact* getFirstContact();
	Contact* getNextContact(Contact* prev);
};
class ContactManager {
public:
	bool intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored);
};
bool ContactManager::intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored)
{
	for (Contact* cur = check->getFirstContact(); cur != NULL; cur = check->getNextContact(cur))
	{
		if (checkSet.find(cur->otherPrimitive(check)) == checkSet.end() && cur->computeIsColliding(overlapIgnored))
			return true;
	}
	return false;
}
}
