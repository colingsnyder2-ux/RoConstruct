// from server: 100% by EspClaude
// from server: 78% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_claude_4fac4919c6e20708.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Camera.h"
struct CameraOwner{virtual void unused();virtual RBX::Camera*getCamera()const;};
struct Workspace{char prefix[0x228];CameraOwner owner;void setDefaultMouseCommand();};
struct Player{char prefix[0x118];RBX::Instance*character;void onCharacterChanged();};
extern Player*findLocalPlayer(Player*);extern Workspace*findWorkspace(Player*);
void Player::onCharacterChanged(){if(this==findLocalPlayer(this)){Workspace*w=findWorkspace(this);if(!character){w->owner.getCamera()->setCameraType(RBX::Camera::FIXED_CAMERA);w->owner.getCamera()->setDistanceFromTarget(0.0f);w->owner.getCamera()->zoom(-1.0f);}else{w->owner.getCamera()->setCameraSubject(character);w->owner.getCamera()->setCameraType((RBX::Camera::CameraType)4);w->owner.getCamera()->setDistanceFromTarget(13.0f);w->owner.getCamera()->zoom(-1.0f);w->setDefaultMouseCommand();}}}
