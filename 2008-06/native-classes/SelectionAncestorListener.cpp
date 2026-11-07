// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// SelectionAncestorListener | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d1243b9f | roc native-status --write
#include "v8datamodel/Selection.h"
namespace RBX {
void Selection::onEvent(const Instance* source, AncestorChanged event) {
    if (source->getRootAncestor() != this->getRootAncestor()) removeFromSelection(source);
}
}
