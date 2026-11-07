// >>> native-status (generated) -- do not edit >>>
// Verb | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src fe4a1662 | roc native-status --write
#include "../native-headers/v8tree/Verb.h"

// 005833e0: intern the name, remember the container, register in its verb map.
RBX::Verb::Verb(VerbContainer* container, std::string name)
    : name(Name::declare(name.c_str(), -1)), container(container) {
    container->verbs[&this->name] = this;
}
