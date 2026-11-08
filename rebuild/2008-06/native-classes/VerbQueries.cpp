#include "StandardVerbs.h"
#include "v8datamodel/Selection.h"

bool RBX::Verb::isEnabled() const { return true; }
bool RBX::Verb::isChecked() const { return false; }
bool RBX::EditSelectionVerb::isEnabled() const { return selection->size() > 0; }
