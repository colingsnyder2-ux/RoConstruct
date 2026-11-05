// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_pointg3d_c9ad49395d07e5c8.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
struct Source{char reserved[0x94];G3D::CoordinateFrame frame;const void*get();};
struct Point{char reserved[12];Source* source;G3D::Vector3 local,position;void setPosition(const G3D::Vector3*);};
void Point::setPosition(const G3D::Vector3* value){position=*value;Source* s=source;s->get();local=s->frame.pointToObjectSpace(position);}
