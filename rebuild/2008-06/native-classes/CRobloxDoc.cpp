#include <afxwin.h>
#include "v8xml/XmlElement.h"
#include "v8tree/Verb.h"
#include "../native-headers/CRobloxDoc.h"

// Existing recovered 00451ac0, expressed through the shared native fields.
CRobloxDoc::CRobloxDoc() : standardVerbs(0), workspace(0) {}

inline const RBX::Name& RBX::Verb::getName() const { return name; }

// 00451a10: external verb ownership stays with its container.
void CRobloxDoc::bindExisting(UINT id, RBX::Verb* verb) {
    if (verb) {
        const RBX::Name* name = &verb->getName();
        commandNames[id] = name;
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[id] = name;
    }
}

// 00451a60: document also tracks the newly owned verb.
void CRobloxDoc::bindOwned(UINT id, RBX::Verb* verb) {
    if (verb) {
        ownedVerbs.push_back(verb);
        commandNames[id] = &verb->getName();
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[id] = name;
    }
}
