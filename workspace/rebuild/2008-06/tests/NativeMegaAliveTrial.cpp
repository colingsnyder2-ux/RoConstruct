#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
bool MegaDragger::anyDragPartAlive() { return DragUtilities::anyPartAlive(dragParts); }
}
