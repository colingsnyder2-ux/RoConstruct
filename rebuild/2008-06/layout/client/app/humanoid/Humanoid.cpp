#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "util/NativeContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/KernelIndex.h"

namespace RBX
{
	class Body;

	class Connector : public KernelIndex
	{
	public:
		Connector() {}
		__declspec(noinline) int& getKernelIndex() { return kernelIndex; }
		virtual ~Connector() {}                                         // slot 0 (??_G 006062c0)
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};
}
#define NATIVE_HUMANOID_UNIT_CONNECTOR
#include "humanoid/Humanoid2008.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Tool.h"
#include "v8world/Joints2008.h"
#include "util/Math.h"
#include "Network/Players.h"        // findLocalCharacter 0049aca0 (render3dAdorn 005d9c30)
#include "v8datamodel/Workspace.h"  // native (read only): findWorkspace 005a3380 (render3dAdorn 005d9c30)
#include <boost/bind.hpp>
#include <vector>

namespace RBX
{
	// 0045c600: defined in AppUnit454_2008WndServices.cpp (INFERRED name; registry placeholder func_0045c600).
	void setCharacterRenderImportance(Instance* instance);

	void Humanoid::render3dAdorn(Adorn* adorn)
	{
		if (walkMode == CLICK_TO_MOVE)
		{
			const Instance* localCharacter = Network::Players::findLocalCharacter(this);
			const ModelInstance* model = localCharacter ? dynamic_cast<const ModelInstance*>(localCharacter) : NULL;
			Humanoid* localHumanoid = model ? model->findModifierOfType<Humanoid>() : NULL;

			if (this == localHumanoid && Workspace::findWorkspace(this))
			{
				G3D::Vector3 worldPosition;
				if (hasWalkToPoint(worldPosition))
				{
					PartInstance* head = getHead();
					if (head && head->getAlphaModifier() != 0.0f)
						renderWaypoint(adorn, worldPosition);
				}

				if (ModelInstance* character = getCharacterFromHumanoid(this))
					character->for_eachChild(&setCharacterRenderImportance);
			}
		}

		if (currentState.get())
			currentState->render3dAdorn(adorn);
	}

	Body* Humanoid::getBody(int i)
	{
		if (i == 0)
		{
			PartInstance* part = getTorso();
			Body* body = part ? part->getPrimitive()->getBody() : NULL;
			if (body)
				return body->getRoot();
		}

		return NULL;
	}

	Primitive* Humanoid::getTorsoPrimitive() const
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getLeftLegPrimitive() const
	{
		PartInstance* part = getLeftLeg();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getRightLegPrimitive() const
	{
		PartInstance* part = getRightLeg();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getHeadPrimitive() const
	{
		PartInstance* part = getHead();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getLeftArmPrimitive() const
	{
		PartInstance* part = getLeftArm();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getRightArmPrimitive() const
	{
		PartInstance* part = getRightArm();
		return part ? part->getPrimitive() : NULL;
	}

	Body* Humanoid::getTorsoBody()
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive()->getBody() : NULL;
	}

	Body* Humanoid::getRootBody()
	{
		Body* body = getTorsoBody();
		return body ? body->getRoot() : NULL;
	}

	float Humanoid::getTorsoHeading() const
	{
		if (Primitive* primitive = getTorsoPrimitive())
		{
			return Math::getHeading(primitive->getCoordinateFrame().lookVector());
		}
		else
		{
			return 0.0f;
		}
	}

	void Humanoid::checkForJointDeath()
	{
		if (Primitive* headPrimitive = getHeadPrimitive())
		{
			if (Primitive* torsoPrimitive = getTorsoPrimitive())
			{
				for (Joint* current = headPrimitive->getFirstJoint(); current != NULL; current = headPrimitive->getNextJoint(current))
				{
					if (current->otherPrimitive(headPrimitive) == torsoPrimitive)
					{
						hadHeadJoint = true;
						return;
					}
				}
			}
		}

		if (hadHeadJoint)
		{
			setHealth(0.0f);
		}
	}

	void Humanoid::onEvent(const RunService* source, Stepped event)
	{
		if (world)
		{
			if (ModelInstance* character = dynamic_cast<ModelInstance*>(getParent()))
				HUMAN::HumanoidState::stepState(currentState, event.step, character->getTopPVController());

			if (getTorsoPrimitive())
				getTorsoPrimitive()->setCanCollide(false);

			checkForJointDeath();

			if (walkTimer > 0)
			{
				if (--walkTimer == 0)
					walkMode = DIRECTION_MOVE;
			}
		}
	}

	void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(descendent.get()))
			primitives.push_back(part->getPrimitive());
	}

	void Humanoid::tellCameraNear(float distance)
	{
		std::vector<Primitive*> primitives;
		Humanoid* humanoid = this;
		ModelInstance* character = NULL;
		if (humanoid)
			character = dynamic_cast<ModelInstance*>(humanoid->getParent());
		if (character)
			character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref(primitives)));

		float alphaModifier = 1.0f;
		if (distance < 3.0f)
		{
			alphaModifier = 0.0f;
		}
		else if (distance < 6.0f)
		{
			alphaModifier = 0.5f;
		}

		for (size_t i = 0; i < primitives.size(); i++)
		{
			PartInstance* part = PartInstance::fromPrimitive(primitives[i]);

			if (!dynamic_cast<Tool*>(part->getParent()))
				part->setAlphaModifier(alphaModifier);
		}
	}

	void Humanoid::cameraSetWalkOrientation(float rad, bool noAdjust)
	{
		if (noAdjust)
		{
			setWalkRotationalVelocity(0.0f);
		}
		else
		{
			PartInstance* torso = getTorso();
			Body* body = (torso) ? torso->getPrimitive()->getBody() : NULL;

			if (body)
			{
				if (Body* root = body->getRoot())
				{
					G3D::Vector3 look = root->getPV().position.lookVector();
					look.y = 0.0f;

					look.unitize();

					float lookAng = Math::radWrap(Math::angleToE0(G3D::Vector2(look.z, look.x)));
					float value = Math::radWrap(Math::radWrap(rad) - lookAng);

					if (fabs(value) < 0.1f)
						value = 0.0f;

					setWalkRotationalVelocity(value);
				}
			}
		}
	}
}
