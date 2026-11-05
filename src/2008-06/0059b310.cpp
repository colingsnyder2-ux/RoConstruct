// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_fcbda0c1820c4cce.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/PartInstance.h"
#include <G3D/Array.h>
#include <boost/shared_ptr.hpp>
template void G3D::Array<boost::shared_ptr<RBX::PartInstance> >::resize(int, bool);
template void G3D::Array<boost::shared_ptr<RBX::PartInstance> >::append(const boost::shared_ptr<RBX::PartInstance>&);
