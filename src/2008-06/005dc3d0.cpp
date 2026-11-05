// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_humanoidmoveto_fbdefee5cd09993b.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/CoordinateFrame.h"
using namespace G3D;
struct Part {const CoordinateFrame& getCoordinateFrame() const;};
struct Handle {void* object;void*control;void clear();};
struct S {char padding[0x1bc];Handle handle;Vector3 position;
 void setPart(Part*);void setVector(const Vector3&);void f(const Vector3&,Part*);
};
void S::f(const Vector3& worldPosition,Part*part){
 if(part){Vector3 local=part->getCoordinateFrame().pointToObjectSpace(worldPosition);
 position=local+Vector3::unitX();handle.clear();setPart(part);setVector(local);}
}
