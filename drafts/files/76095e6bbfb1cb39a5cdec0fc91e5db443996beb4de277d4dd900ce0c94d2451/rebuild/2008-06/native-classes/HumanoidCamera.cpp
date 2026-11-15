// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native RBX::Humanoid (inactive), camera / Connector rows of the original Humanoid unit (005d74a0..005dccxx)
// that need the 2008 PartInstance with the Primitive embedded at +0x228 (native-headers/part-embedded): getBody
// 005d9310, tellCameraNear 005d9df0 (+ its helper collectAllDescendantCharacterPrims 005d9d10) and
// cameraSetWalkOrientation 005dc7f0. Since batch 14 this unit defines NATIVE_PRIMITIVE_NATIVE_BODY: the part-embedded
// Primitive.h then reaches native-headers/v8kernel/Body2008.h (root +0x10, pv +0x94) instead of the donor Body (root
// +0x4, pv +0x88), so getBody 005d9310 / getRootBody 005d9180 read the 2008 root. Nothing here may reach the donor
// v8kernel/Body.h: Joint comes from the native v8world/Joints2008.h (Edge on IPipelined2008.h; otherPrimitive inline)
// instead of the donor v8world/Joint.h, and the Humanoid base takes a unit-local Connector (below), exactly as
// native-headers/v8kernel/Connector2008.h declares it, because Connector2008.h reaches the donor Body.h (pattern of
// RunningBaseForce.cpp / BodyGyro.cpp). No constructor here, so no vtable is emitted (every vtable is built from
// Humanoid2008.cpp).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "util/NativeContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/KernelIndex.h"

// Unit-local Connector, exactly as native-headers/v8kernel/Connector2008.h declares it (see the header comment above).
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
#include <boost/bind.hpp>
#include <vector>

namespace RBX
{
	// 005d9310 (Connector slot, this adjusted by -0x130): torso primitive (+0x228) body (+0xa0 -> part+0x2c8),
	// then Body::getRoot (+0x10, the 2008 Body of Body2008.h through NATIVE_PRIMITIVE_NATIVE_BODY).
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

	// 005d90a0 ?getTorsoPrimitive@Humanoid@RBX@@QBEPAVPrimitive@2@XZ (18 bytes): getTorso 005d8b10, then the embedded
	// Primitive (part + 0x228) or NULL. onEvent 005dc740 inlines this body (getTorso, `add eax, 0x228`), so it is
	// defined in the Humanoid unit. Earlier trial (2026-11-14, donor humanoid/Humanoid.h declaration, same flags):
	// byte-identical (18/18, relocations masked).
	Primitive* Humanoid::getTorsoPrimitive() const
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d90c0: same shape as getTorsoPrimitive over getLeftLeg 005d8c10.
	Primitive* Humanoid::getLeftLegPrimitive() const
	{
		PartInstance* part = getLeftLeg();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d90e0: same shape over getRightLeg 005d8d10.
	Primitive* Humanoid::getRightLegPrimitive() const
	{
		PartInstance* part = getRightLeg();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d9100: same shape over getHead 005d8a10 (inlined in checkForJointDeath 005dc6c0).
	Primitive* Humanoid::getHeadPrimitive() const
	{
		PartInstance* part = getHead();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d9120: same shape over getLeftArm 005d8e10.
	Primitive* Humanoid::getLeftArmPrimitive() const
	{
		PartInstance* part = getLeftArm();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d9140: same shape over getRightArm 005d8f10.
	Primitive* Humanoid::getRightArmPrimitive() const
	{
		PartInstance* part = getRightArm();
		return part ? part->getPrimitive() : NULL;
	}

	// 005d9160 (19 bytes): getTorso 005d8b10, then `mov eax, [eax + 0x2c8]` (the embedded Primitive's body +0xa0) or
	// NULL. Reads no Body field, so the donor Body this part-embedded unit sees does not affect it.
	Body* Humanoid::getTorsoBody()
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive()->getBody() : NULL;
	}

	// 005d9180 (30 bytes; RunningBase::onComputeForce 00666550): getTorsoBody 005d9160 inlined (getTorso 005d8b10,
	// part +0x2c8), then Body::getRoot (2008 Body root +0x10).
	Body* Humanoid::getRootBody()
	{
		Body* body = getTorsoBody();
		return body ? body->getRoot() : NULL;
	}

	// 005dc6c0 (119 bytes; called by onEvent 005dc740). Head and torso primitives inline (getHead 005d8a10 /
	// getTorso 005d8b10, + 0x228); Primitive::getFirstJoint 005e7b90 / getNextJoint 005e7ba0; Edge::otherPrimitive
	// inline (prim0 +0xc / prim1 +0x10); hadHeadJoint is bit 2 of +0x1e8; setHealth 005dbe70(0.0f).
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

	// 005dc740 (Listener<RunService, Stepped>, this adjusted by -0x1a4, `ret 0xc`): world +0x21c tested first;
	// dynamic_cast<ModelInstance*>(getParent()) -> PVInstance::getTopPVController 0059a9e0 -> HumanoidState stepper
	// 00645450(&currentState +0x220, event.step, controller); getTorsoPrimitive inlined twice; Primitive::setCanCollide
	// 005e75b0(false); checkForJointDeath 005dc6c0; walkTimer +0x1b4 / walkMode +0x1b8.
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

	// 005d9d10: boost::bind target of tellCameraNear / getIgnorePrims (visitDescendents 005d8540); pushes part+0x228.
	void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(descendent.get()))
			primitives.push_back(part->getPrimitive());
	}

	// 005d9df0 (ICharacterSubject slot, this adjusted by -0x14c; bytes identical with relocations masked): getCharacterFromHumanoid 005d7670 inlined, visitDescendents 005d8540,
	// PartInstance::fromPrimitive 00599f80, dynamic_cast<Tool*> of the parent, setAlphaModifier 0059dee0.
	void Humanoid::tellCameraNear(float distance)
	{
		std::vector<Primitive*> primitives;
		// getCharacterFromHumanoid(this) 005d7670 is inlined in the original (null test of the adjusted this, then
		// dynamic_cast<ModelInstance*> of the parent); its out-of-line body lives in Humanoid2008.cpp.
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

	// 005dc7f0 (ICharacterSubject slot, this adjusted by -0x14c). setWalkRotationalVelocity 005dc090 is inlined twice
	// in the original (compare with +0x1b0, raisePropertyChanged 0040db00 with 0097a2d8); its out-of-line body lives
	// in Humanoid2008.cpp, so the same statement sequence is written here. PARKED (draft): the Body offsets are right
	// since batch 14 (root +0x10, pv +0x94 through NATIVE_PRIMITIVE_NATIVE_BODY), but with the setter written out
	// the noAdjust branch keeps the ICharacterSubject this in edi instead of adjusting ecx by -0x14c per branch. Body::updatePV 00599360 (getPV),
	// CoordinateFrame::lookVector 005187f0, Vector3::unitize 00518470, Math::angleToE0 005de0f0, Math::radWrap 005cbec0.
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
