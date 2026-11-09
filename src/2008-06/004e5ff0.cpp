// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_partchunkcframe_bd1a1158d696da97.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/CoordinateFrame.h"
struct Body { const G3D::CoordinateFrame& getFrame(); };
struct PartChunk {
 char reserved0[0x28];
 G3D::CoordinateFrame frame;
 char reserved58[0xbc-0x58];
 Body* body;
 const G3D::CoordinateFrame& cframe();
};
const G3D::CoordinateFrame& PartChunk::cframe() {frame=body->getFrame();return frame;}
