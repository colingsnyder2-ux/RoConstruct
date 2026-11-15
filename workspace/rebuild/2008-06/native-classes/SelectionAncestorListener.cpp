// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"
namespace RBX {
void Selection::onEvent(const Instance* source, AncestorChanged event) {
    if (source->getRootAncestor() != this->getRootAncestor()) removeFromSelection(source);
}
}
