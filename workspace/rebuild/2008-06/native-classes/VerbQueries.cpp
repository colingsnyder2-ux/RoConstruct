// >>> native-status (generated) -- do not edit >>>
// VerbQueries | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src d05983f8 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Selection.h"

bool RBX::Verb::isEnabled() const { return true; }
bool RBX::Verb::isChecked() const { return false; }
bool RBX::EditSelectionVerb::isEnabled() const { return selection->size() > 0; }
