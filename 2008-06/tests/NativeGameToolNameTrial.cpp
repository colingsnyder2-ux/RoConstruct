#include "NativeGameToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<MouseCommand, &sGameTool>::getName() const {
    return NativeToolName<GameTool>::get();
}
}
