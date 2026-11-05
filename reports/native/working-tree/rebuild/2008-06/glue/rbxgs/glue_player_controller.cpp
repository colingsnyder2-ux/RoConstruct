// Rebuild glue: PlayerController::onEvent, which rbxgs declares but never defines (it replaces an empty
// stub). Each heartbeat the local character walks along the camera's ground-plane forward/right from
// WASD or the arrow keys and jumps on space. Behavioural reconstruction, not byte-verified.
#include "v8datamodel/UserController.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "humanoid/Humanoid.h"

namespace RBX
{
	namespace
	{
		float held(const UserInputBase* input, SDLKey a, SDLKey b)
		{
			return input->keyDown(a) || input->keyDown(b) ? 1.0f : 0.0f;
		}

		G3D::Vector3 flat(G3D::Vector3 v)
		{
			v.y = 0.0f;
			return v.squaredLength() > 0.0f ? v.direction() : G3D::Vector3::zero();
		}
	}

	void PlayerController::onEvent(const RunService*, Heartbeat)
	{
		boost::shared_ptr<const PVInstance> character = controlledInstance.lock();
		const UserInputBase* input = getHardwareDevice();
		if (!character || !input)
			return;
		Humanoid* humanoid = Humanoid::modelIsCharacter(character.get());
		if (!humanoid)
			return;

		float forward = held(input, SDLK_w, SDLK_UP) - held(input, SDLK_s, SDLK_DOWN);
		float right = held(input, SDLK_d, SDLK_RIGHT) - held(input, SDLK_a, SDLK_LEFT);
		G3D::Vector3 direction = G3D::Vector3::zero();
		if (forward != 0.0f || right != 0.0f)
		{
			G3D::CoordinateFrame view;
			Workspace* workspace = Workspace::findWorkspace(character.get());
			if (workspace && workspace->getCamera())
				view = workspace->getCamera()->getCameraCoordinateFrame();
			direction = flat(flat(view.lookVector()) * forward + flat(view.rightVector()) * right);
		}
		humanoid->setWalkDirection(direction);

		if (input->keyDown(SDLK_SPACE))
			humanoid->setJump(true);
	}
}
