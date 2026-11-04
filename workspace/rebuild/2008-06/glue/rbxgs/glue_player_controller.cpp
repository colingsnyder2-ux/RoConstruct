// PlayerController heartbeat behavior from 2008-06 005cb530.
// Uses the existing rbxgs input/camera APIs as adapters; not byte-verified.
#include "v8datamodel/UserController.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/ICharacterSubject.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"

namespace RBX
{
    void PlayerController::onEvent(const RunService*, Heartbeat event)
    {
        const UserInputBase* input=getHardwareDevice();
        boost::shared_ptr<const PVInstance> controlled=controlledInstance.lock();
        ModelInstance* character=Network::Players::findLocalCharacter(controlled.get());
        Humanoid* humanoid=controlled.get()==character?Humanoid::modelIsCharacter(character):NULL;
        Workspace* workspace=Workspace::findWorkspace(character);
        if(!input || !humanoid || !workspace)return;
        Camera* camera=workspace->getCamera();
        if(!camera)return;
        bool up=input->keyDown(SDLK_UP),down=input->keyDown(SDLK_DOWN);
        bool left=input->keyDown(SDLK_LEFT),right=input->keyDown(SDLK_RIGHT);
        bool w=input->keyDown(SDLK_w),s=input->keyDown(SDLK_s);
        bool a=input->keyDown(SDLK_a),d=input->keyDown(SDLK_d);
        if(up || down || left || right){
            if(left || right){camera->panRadians((left?1.0f:-1.0f)*event.step*1.8f);++stepsRotating;}
            else stepsRotating=0;
            float amount=up?1.0f:(down?-1.0f:0.0f);
            G3D::Vector3 forward=camera->getCameraCoordinateFrame().lookVector();forward.y=0;
            if(forward.squaredLength()>1e-12f)forward.unitize();
            humanoid->setWalkDirection(forward*amount);
        }else if(w || s || a || d){
            float forwardAmount=w?1.0f:(s?-1.0f:0.0f);
            float leftAmount=a?1.0f:(d?-1.0f:0.0f);
            G3D::Vector3 forward=camera->getCameraCoordinateFrame().lookVector();forward.y=0;
            if(forward.squaredLength()>1e-12f)forward.unitize();
            G3D::Vector3 walk=forward*forwardAmount+G3D::Vector3(forward.z,0,-forward.x)*leftAmount;
            if(walk.squaredLength()>1.0f)walk.unitize();
            humanoid->setWalkDirection(walk);
            ICharacterSubject* subject=dynamic_cast<ICharacterSubject*>(camera->getCameraSubject());
            humanoid->setStrafe(subject && subject->getCursorCenterLocked());
        }else humanoid->setWalkDirection(G3D::Vector3::zero());
        if(input->keyDown(SDLK_SPACE)){humanoid->setSit(false);humanoid->setJump(true);}
        // 005ca390 polls SDL 1.2 left/right Alt; its return is ignored here.
        if(!input->keyDown(SDLK_RALT))input->keyDown(SDLK_LALT);
    }
}
