// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_characterheartbeatreorder3e3c8646d84aea95.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include <vector>
#include "v8datamodel/ICharacterSubject.h"
#include "G3D/Vector2.h"
namespace RBX {
class Instance {public: virtual ~Instance();};
class Workspace {public: static Workspace* findWorkspace(Instance*); void setCursorCenterLocked(bool);};
namespace Math {float angleToE0(const G3D::Vector2&);}
void ICharacterSubject::onHeartBeat(G3D::CoordinateFrame& goal,G3D::CoordinateFrame& focus) {
 G3D::Vector3 delta=goal.translation-focus.translation;
 cursorLocked=sqrt(delta.y*delta.y+delta.x*delta.x+delta.z*delta.z)<2.75f;
 Instance* instance=dynamic_cast<Instance*>(this);
 if(Workspace* workspace=Workspace::findWorkspace(instance)) workspace->setCursorCenterLocked(cursorLocked);
 float angle=0.0f;
 if(cursorLocked) {G3D::Vector3 v=focus.translation-goal.translation;v.y=0.0f;v=v.direction();angle=Math::angleToE0(G3D::Vector2(v.z,v.x));}
 cameraSetWalkOrientation(angle,!cursorLocked);
}
}
