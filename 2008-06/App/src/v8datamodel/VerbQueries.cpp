// >>> native-status (generated) -- do not edit >>>
// VerbQueries | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d05983f8 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Selection.h"

bool RBX::Verb::isEnabled() const { return true; }
bool RBX::Verb::isChecked() const { return false; }
bool RBX::EditSelectionVerb::isEnabled() const { return selection->size() > 0; }
