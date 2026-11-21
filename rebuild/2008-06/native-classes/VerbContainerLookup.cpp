// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::VerbContainer destructor and lookups (2008-06 Verb unit 005832e0..005834ab, beside Verb::Verb 005833e0; the
// ctor and setVerbParent are in native-classes/VerbContainer.cpp). Identities from work/2008-06/identity-registry.json
// (decorated-signature + reference votes); bodies after the donor tools/rbxgs v8tree/Verb.cpp.
//   ~VerbContainer 005832e0: vtable 00830b7c, loop deleting verbs.begin()->second through Verb's virtual deleting
//                  destructor (slot 1, arg 1; ~Verb removes itself from the map), then the map destructor 00553d80.
//   getVerb(Name)  00583220: Name::getNullName 00554270 compared by address, map find 00451600, the parent recursion
//                  turned into a loop by the compiler.
//   getVerb(string) 00583380: Name::lookup(const std::string&) 00554180, then getVerb(Name) 00583220.
#include "../native-headers/v8tree/Verb.h"
#include "util/Name.h"

namespace RBX
{
	// 005832e0 ??1VerbContainer@RBX@@UAE@XZ (vector deleting destructor 00583490 calls it)
	VerbContainer::~VerbContainer()
	{
		while (verbs.begin() != verbs.end())
		{
			delete verbs.begin()->second;
		}
	}

	// 00583380 ?getVerb@VerbContainer@RBX@@QAEPAVVerb@2@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
	Verb* VerbContainer::getVerb(std::string name)
	{
		return getVerb(Name::lookup(name));
	}

	// 00583220 ?getVerb@VerbContainer@RBX@@QAEPAVVerb@2@ABVName@2@@Z
	Verb* VerbContainer::getVerb(const Name& name)
	{
		if (Name::getNullName() == name)
			return NULL;

		std::map<const Name*, Verb*>::iterator iter = verbs.find(&name);

		if (iter != verbs.end())
			return iter->second;

		if (!parent)
			return NULL;

		return parent->getVerb(name);
	}
}
