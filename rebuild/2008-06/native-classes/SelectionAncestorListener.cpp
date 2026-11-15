// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"
#ifdef NATIVE_SELECTION_ROOT_ANCESTOR_PENDING
// Blocked (core header): the body calls Instance::getRootAncestor() 0042a5f0
// (?getRootAncestor@Instance@RBX@@QAEPAV12@XZ), which core v8tree/Instance.h does not declare (proposal to its owner).
// The declaration of the override is in v8datamodel/Selection.h, so Selection is concrete without this body.
namespace RBX {
// 005682e0
void Selection::onEvent(const Instance* source, AncestorChanged event) {
    if (source->getRootAncestor() != this->getRootAncestor()) removeFromSelection(source);
}
}
#endif
