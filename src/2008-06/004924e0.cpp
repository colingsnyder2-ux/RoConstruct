// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_playercameraa3ca3ecaabfe7e3f.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Camera.h"
struct CameraOwner{virtual void unused();virtual RBX::Camera*getCamera()const;};
struct Workspace{char prefix[0x288];CameraOwner owner;void setDefaultMouseCommand();};
struct Player{char prefix[0x170];void*character;void onCharacterChanged();};
extern Player*findLocalPlayer(Player*);extern Workspace*findWorkspace(Player*);extern RBX::Instance*modelIsCharacter(void*);
void Player::onCharacterChanged(){if(this==findLocalPlayer(this)){Workspace*w=findWorkspace(this);if(!character){w->owner.getCamera()->setCameraType(RBX::Camera::FIXED_CAMERA);w->owner.getCamera()->setDistanceFromTarget(0.0f);w->owner.getCamera()->zoom(-1.0f);}else{w->owner.getCamera()->setCameraSubject(modelIsCharacter(character));w->owner.getCamera()->setCameraType(RBX::Camera::CUSTOM_CAMERA);w->owner.getCamera()->setDistanceFromTarget(13.0f);w->owner.getCamera()->zoom(-1.0f);w->setDefaultMouseCommand();}}}
