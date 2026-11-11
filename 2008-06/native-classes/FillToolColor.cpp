// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/ToolsPart.h"

namespace RBX {
FillToolColor::FillToolColor() {}
FillToolColor FillTool::color;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *> >;
