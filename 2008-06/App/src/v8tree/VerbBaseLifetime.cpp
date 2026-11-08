// >>> native-status (generated) -- do not edit >>>
// VerbBaseLifetime | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src c0ca879c | roc native-status --write
#include "v8tree/Verb.h"

RBX::Verb::~Verb()
{
    if (container) container->verbs.erase(&name);
}
