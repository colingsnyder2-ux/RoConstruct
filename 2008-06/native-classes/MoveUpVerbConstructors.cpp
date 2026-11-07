// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /DROC_INACTIVE_MOVEUP_PROVIDER
// MoveUpSelectionVerb base constructor and its two derived verb constructors.
// Names, float heights and vtables are read from the original ctors:
//   005c5400 MoveUpPlateVerb: "SelectionUpPlate" (00817de0), height 0x832a18 = 0.4f, vtable 0083902c
//   005c5490 MoveUpBrickVerb: "SelectionUpBrick" (00817df4), height 0x827278 = 1.2f, vtable 00839044
#include "../native-headers/StandardVerbs.h"

// BasicVerbConstructors.cpp remains the canonical provider. Opt in only for
// this isolated alternative proof; never select both providers in one link.
#if defined(ROC_INACTIVE_MOVEUP_PROVIDER)
namespace RBX {

MoveUpSelectionVerb::MoveUpSelectionVerb(DataModel* dm, const std::string& name, float height)
    : EditSelectionVerb(name, dm), moveUpHeight(height) {}

MoveUpPlateVerb::MoveUpPlateVerb(DataModel* dm)
    : MoveUpSelectionVerb(dm, "SelectionUpPlate", 0.4f) {}

MoveUpBrickVerb::MoveUpBrickVerb(DataModel* dm)
    : MoveUpSelectionVerb(dm, "SelectionUpBrick", 1.2f) {}

} // namespace RBX
#endif
