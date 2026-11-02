#include "StandardVerbs.h"
namespace RBX {
inline MoveUpSelectionVerb::MoveUpSelectionVerb(DataModel* dm,const std::string& name,float height) : EditSelectionVerb(name,dm),moveUpHeight(height) {}
MoveUpPlateVerb::MoveUpPlateVerb(DataModel* dm) : MoveUpSelectionVerb(dm,"SelectionUpPlate",0.4f) {}
MoveUpBrickVerb::MoveUpBrickVerb(DataModel* dm) : MoveUpSelectionVerb(dm,"SelectionUpBrick",1.2f) {}
}
