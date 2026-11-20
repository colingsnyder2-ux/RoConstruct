#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid2008.h"

namespace RBX {
namespace HUMAN {

// 00644670 (thiscall, ret 4): the 17 transition event ids. Case bodies are laid out in source order, not id order.
bool HumanoidState::canTransition(int event)
{
    switch (event)
    {
    case 0:  return humanoid->imDead;
    case 1:  return humanoid->getJump();
    case 4:  return humanoid->getSit();
    case 5:  return !humanoid->getSit();
    case 6:  return tipped();
    case 7:  return upright();
    case 8:  return floorFound;
    case 9:  return !floorFound;
    case 2:  return humanoid->getStrafe();
    case 3:  return !humanoid->getStrafe();
    case 11: return floorPart.get() != NULL;
    case 10: return floorPart.get() == NULL;
    case 12: return onFloorStep();
    case 13: return !onFloorStep();
    case 15: return value0c <= 0.0f;
    case 14: return flag11;
    case 16: return sub_00643eb0();
    default: return false;
    }
}

}
}

// 2008-06 native RBX::Humanoid (inactive), second translation unit of the original Humanoid unit: the bodies that
// need a complete PartInstance. The native v8datamodel/PartInstance.h reaches the donor v8kernel/Connector.h (through
// v8world/Primitive.h), which cannot share a translation unit with v8kernel/Connector2008.h, so this file selects the
// donor Connector for the Humanoid base (NATIVE_HUMANOID2008_DONOR_CONNECTOR, see Humanoid2008.h). Only bodies and the
// four reference-property descriptors live here (no constructor, so no vtable is emitted): the Humanoid layout is the
// same with either Connector (vptr + KernelIndex), and every vtable is built and checked from Humanoid2008.cpp. The two
// virtual bodies here (getContactManager, getLocation) do not depend on Connector slot order. The recorder builds this unit
// with native-headers/engine-world ahead of the donor dirs (the 2008 World: contactManager at +0x84).
// Verified by tests/record_native_humanoid2008.py.
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "util/NativeContentProvider.h"
#include "v8datamodel/ForceField.h"
#include "util/Object.h"
#include "util/Math.h"
#include <stdexcept>
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"   // native (read only): findWorkspace 005a3380, contextInWorkspace 005a33d0

namespace RBX
{
	extern Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint;   // Humanoid2008.cpp (0097a4b0), setTargetPoint

	Reflection::RefPropDescriptor<Humanoid, PartInstance> propTorso("Torso", "Data", &Humanoid::getTorso, &Humanoid::setTorso, Reflection::PropertyDescriptor::UI);                // 0097a538
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propLeftLeg("LeftLeg", "Data", &Humanoid::getLeftLeg, &Humanoid::setLeftLeg, Reflection::PropertyDescriptor::UI);        // 0097a3b0
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propRightLeg("RightLeg", "Data", &Humanoid::getRightLeg, &Humanoid::setRightLeg, Reflection::PropertyDescriptor::UI);    // 0097a5dc
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propWalkToPart("WalkToPart", "Control", &Humanoid::getWalkToPart, &Humanoid::setWalkToPart, Reflection::PropertyDescriptor::STREAMING); // 0097a328

	PartInstance* Humanoid::getHead() const
	{
		if (!head && getParent())
			head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));

		return head.get();
	}

	PartInstance* Humanoid::getTorso() const
	{
		if (!torso && getParent())
			torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));

		return torso.get();
	}

	PartInstance* Humanoid::getLeftLeg() const
	{
		if (!leftLeg && getParent())
			leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));

		return leftLeg.get();
	}

	PartInstance* Humanoid::getRightLeg() const
	{
		if (!rightLeg && getParent())
			rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));

		return rightLeg.get();
	}

	PartInstance* Humanoid::getLeftArm() const
	{
		if (!leftArm && getParent())
			leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));

		return leftArm.get();
	}

	PartInstance* Humanoid::getRightArm() const
	{
		if (!rightArm && getParent())
			rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));

		return rightArm.get();
	}

	void Humanoid::takeDamage(float amount)
	{
		if (getTorso() && !ForceField::isProtected(getTorso()))
			setHealth(health - amount);
	}

	void Humanoid::setWalkToPart(PartInstance* value)
	{
		if (walkToPart.get() != value)
		{
			walkToPart = shared_from(value);
			raisePropertyChanged(propWalkToPart);
		}

		walkMode = (walkMode == HAS_POINT) ? CLICK_TO_MOVE : HAS_PART;
		walkTimer = (walkMode == CLICK_TO_MOVE) ? 240 : 0;
	}

	void Humanoid::setLeftLeg(PartInstance* value)
	{
		if (leftLeg.get() != value)
		{
			leftLeg = shared_from(value);
			raisePropertyChanged(propLeftLeg);
		}
	}

	void Humanoid::setRightLeg(PartInstance* value)
	{
		if (rightLeg.get() != value)
		{
			rightLeg = shared_from(value);
			raisePropertyChanged(propRightLeg);
		}
	}

	void Humanoid::setTorso(PartInstance* value)
	{
		if (torso.get() != value)
		{
			torso = shared_from(value);
			raisePropertyChanged(propTorso);
		}
	}

	ContactManager* Humanoid::getContactManager()
	{
		return world ? &world->getContactManager() : NULL;
	}

	void Humanoid::moveTo2(G3D::Vector3 worldPosition, boost::shared_ptr<Instance> part)
	{
		PartInstance* p = dynamic_cast<PartInstance*>(part.get());
		if (!p)
			throw std::runtime_error("Argument error: A Part is required");

		moveTo(worldPosition, p);
	}

	const G3D::CoordinateFrame Humanoid::getLocation() const
	{
		return getHead() ? getHead()->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	void Humanoid::moveTo(const G3D::Vector3& worldPosition, PartInstance* part)
	{
		if (part)
		{
			G3D::Vector3 local = part->getCoordinateFrame().pointToObjectSpace(worldPosition);

			walkToPoint = local + G3D::Vector3::unitX();
			walkToPart.reset();
			setWalkToPart(part);
			setWalkToPoint(local);
		}
	}

	void Humanoid::setTargetPoint(const G3D::Vector3& value)
	{
		float tolerance = 1.0f;
		if (getTorso())
		{
			float distance = Math::taxiCabMagnitude(getTorso()->getCoordinateFrame().translation - value);
			tolerance = std::max(2.0f, distance) * 0.01f;
		}

		if (Math::taxiCabMagnitude(value - targetPoint) > tolerance)
		{
			targetPoint = value;
			raisePropertyChanged(propTargetPoint);
		}
	}

	// 005d79b0: Workspace::findWorkspace 005a3380 / contextInWorkspace 005a33d0 (native v8datamodel/Workspace.h).
	bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
	{
		if (walkToPart && Workspace::findWorkspace(this) && Workspace::contextInWorkspace(walkToPart.get()))
		{
			worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);
			return true;
		}
		else
		{
			return false;
		}
	}

	PartInstance* Humanoid::getHeadFromCharacter(const ModelInstance* character)
	{
		return character ? dynamic_cast<PartInstance*>(character->findFirstChildByName("Head")) : NULL;
	}

	JointInstance* Humanoid::findRightShoulder() const
	{
		PartInstance* torso = getTorso();
		return torso ? rbx_static_cast<JointInstance*>(torso->findFirstChildByName("Right Shoulder")) : NULL;
	}

	// 005d8420. Free helper of the original unit (buildJoints 005d9340 calls it five times); name and linkage after the
	// donor. Batch 27: returns shared_ptr<JointInstance> because v8datamodel/JointInstance.h now derives Motor and Snap
	// from JointInstance (2008 RTTI), so the donor's shared_ptr<AutoJoint> return no longer compiles (the whole unit
	// failed with C2440). The body has no pointer adjustment either way (bases at offset 0); the registry's
	// decorated name ?newJoint@RBX@@YA?AV?$shared_ptr@VAutoJoint@RBX@@@boost@@_N@Z comes from the donor signature.
	boost::shared_ptr<JointInstance> newJoint(bool animated)
	{
		if (animated)
		{
			boost::shared_ptr<Motor> m = Creatable<Instance>::create<Motor>();
			m->setMaxVelocity(0.1f);
			return m;
		}
		else
		{
			boost::shared_ptr<Snap> s = Creatable<Instance>::create<Snap>();
			return s;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::AutoJoint>;

// 2008-06 native RBX::Humanoid (inactive), camera / Connector rows of the original Humanoid unit (005d74a0..005dccxx)
// that need the 2008 PartInstance with the Primitive embedded at +0x228 (native-headers/part-embedded): getBody
// 005d9310, tellCameraNear 005d9df0 (+ its helper collectAllDescendantCharacterPrims 005d9d10) and
// cameraSetWalkOrientation 005dc7f0, and render3dAdorn 005d9c30 (reads the head's alphaModifier +0x328).
// Since batch 14 this unit defines NATIVE_PRIMITIVE_NATIVE_BODY: the part-embedded
// Primitive.h then reaches native-headers/v8kernel/Body2008.h (root +0x10, pv +0x94) instead of the donor Body (root
// +0x4, pv +0x88), so getBody 005d9310 / getRootBody 005d9180 read the 2008 root. Nothing here may reach the donor
// v8kernel/Body.h: Joint comes from the native v8world/Joints2008.h (Edge on IPipelined2008.h; otherPrimitive inline)
// instead of the donor v8world/Joint.h, and the Humanoid base takes a unit-local Connector (below), exactly as
// native-headers/v8kernel/Connector2008.h declares it, because Connector2008.h reaches the donor Body.h (pattern of
// RunningBaseForce.cpp / BodyGyro.cpp). No constructor here, so no vtable is emitted (every vtable is built from
// Humanoid2008.cpp).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8kernel/KernelIndex.h"

// Unit-local Connector, exactly as native-headers/v8kernel/Connector2008.h declares it (see the header comment above).
namespace RBX
{
	class Body;

}
#define NATIVE_HUMANOID_UNIT_CONNECTOR
#include "v8datamodel/Tool.h"
#include "v8world/Joints2008.h"
#include "Network/Players.h"        // findLocalCharacter 0049aca0 (render3dAdorn 005d9c30)
#include "v8datamodel/Workspace.h"  // native (read only): findWorkspace 005a3380 (render3dAdorn 005d9c30)
#include "v8datamodel/Selection.h"  // FilteredSelection<PartInstance> (getIgnorePrims 005db9e0)
#include <boost/thread/once.hpp>
#include <boost/bind.hpp>
#include <vector>

namespace RBX
{
	// 0045c600: defined in AppUnit454_2008WndServices.cpp (INFERRED name; registry placeholder func_0045c600).
	void setCharacterRenderImportance(Instance* instance);

	// 005d9c30 ?render3dAdorn@Humanoid@RBX@@EAEXPAVAdorn@2@@Z (222 B, IRenderable slot; `this` is the IRenderable
	// subobject +0x13c: walkMode [this+0x7c] = +0x1b8, currentState [this+0xe4] = +0x220). Here rather than in
	// Humanoid2008.cpp because it reads the head's alphaModifier at +0x328, which only the part-embedded PartInstance has.
	// Donor body plus two additions read from the target: the waypoint is drawn only while that alphaModifier is non-zero,
	// and the local character's parts are walked with for_eachChild 0045c470 (setCharacterRenderImportance 0045c600,
	// defined in AppUnit454_2008WndServices.cpp). findLocalCharacter 0049aca0 + modelIsCharacter inlined
	// (findModifierOfType 005d8690), findWorkspace 005a3380, hasWalkToPoint 005d79b0, getHead 005d8a10, renderWaypoint
	// 005d7750, getCharacterFromHumanoid 005d7670, HumanoidState::render3dAdorn 00645060.
	void Humanoid::render3dAdorn(Adorn* adorn)
	{
		if (walkMode == CLICK_TO_MOVE)
		{
			// modelIsCharacter 005d9a20 is inlined in the target; it is defined in Humanoid2008.cpp, so its body is
			// spelled out here: dynamic_cast<const ModelInstance*> then findModifierOfType<Humanoid> 005d8690.
			// Rejected: calling modelIsCharacter (out of line here, 186 B); nested ifs into a NULL-initialized local
			// (222 B, the NULL lands in ebx and the adorn argument in ebp). These conditional expressions match.
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

	// 005d91a0 (105 bytes; MovingNoPhysicsBase::onStep 0066f2c0, RunningBase::onStep 00666410): getTorso 005d8b10 and the
	// embedded Primitive (+0x228) tested inline, Primitive::getCoordinateFrame 005e82c0, lookVector (column 2 00513240
	// times -1.0f [00828b60]), Math::getHeading 005de650; else fldz. Body after the donor tools/rbxgs Humanoid.cpp.
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

	// ServiceProvider templates the core v8tree/Service.h only declares; same definitions as FilteredSelectionFactory.cpp
	// (find without a class-name fallback) and LocalBackpack2008.cpp (create(const Instance*)). This unit emits the
	// FilteredSelection<PartInstance> instances that getIgnorePrims 005db9e0 calls: create(const Instance*) 005db230
	// (parent walk with dynamic_cast<ServiceProvider> 0092e15c, tail jump to create() const), create() const 005daa50,
	// find() const 005da370, doGetClassIndex 005d78f0 (guard 0097a25c, index 0097a258), callDoGetClassIndex 005d7c70.
	template<class Class> size_t ServiceProvider::doGetClassIndex()
	{
		static size_t index = newIndex();
		return index;
	}
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}
	template<class Class> Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		if (index + 1 > serviceArray.size())
			serviceArray.resize(index + 1);
		else
		{
			Class* service = static_cast<Class*>(serviceArray[index].get());
			if (service)
				return service;
		}
		// No class-name fallback in this specialization (005da370 returns NULL); the unreachable tail keeps the
		// original exception-handling codegen (as in FilteredSelectionFactory.cpp).
		if (true)
			return NULL;
		boost::shared_ptr<Instance> item;
		if (!item)
			return NULL;
		serviceArray[index] = item;
		return static_cast<Class*>(item.get());
	}
	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (!service)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}
	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		while (context)
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context))
				return provider->create<Class>();
			context = context->getParent();
		}
		return NULL;
	}

	// 005db9e0 ?getIgnorePrims@Humanoid@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@...@Z (238 B, ICharacterSubject slot, this
	// adjusted by -0x14c, `ret 4`). Donor tools/rbxgs humanoid/Humanoid.cpp: getCharacterFromHumanoid inlined (null test,
	// dynamic_cast<ModelInstance> 00932a40 of the parent), visitDescendents 005d8540 with collectAllDescendantCharacterPrims
	// 005d9d10 bound to the ignore vector cast to vector<Primitive*>& (as the donor). 2008 addition (no donor): the service
	// created by 005db230 is FilteredSelection<PartInstance> (create<T>() 005d9280 allocates 0x154 bytes, constructor
	// 005d8740 stores vtable 0083d544 = ??_7?$FilteredSelection@VPartInstance@RBX@@@RBX@@6B@ and names it
	// "FilteredSelection" 008308a4); every selected part's embedded Primitive (+0x228) is pushed (push_back 004213a0).
	void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
	{
		Humanoid* humanoid = this;
		ModelInstance* character = NULL;
		if (humanoid)
			character = dynamic_cast<ModelInstance*>(humanoid->getParent());
		if (character)
			character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref((std::vector<Primitive*>&)ignore)));

		if (FilteredSelection<PartInstance>* selection = ServiceProvider::create<FilteredSelection<PartInstance> >(this))
		{
			const std::vector<PartInstance*>& parts = selection->items();
			for (std::vector<PartInstance*>::const_iterator it = parts.begin(); it != parts.end(); ++it)
				ignore.push_back((*it)->getPrimitive());
		}
	}

	// 005dc7f0 (ICharacterSubject slot, this adjusted by -0x14c). setWalkRotationalVelocity 005dc090 is inlined twice
	// (compare with +0x1b0, raisePropertyChanged 0040db00 with 0097a2d8): batch 15 made it an inline body in
	// humanoid/Humanoid2008.h, which gives the target's per-branch `add ecx, -0x14c` (written out here before, the
	// noAdjust branch kept the ICharacterSubject this in edi). Body offsets through NATIVE_PRIMITIVE_NATIVE_BODY (root
	// +0x10, pv +0x94). Body::updatePV 00599360 (getPV), CoordinateFrame::lookVector 005187f0, Vector3::unitize 00518470,
	// Math::angleToE0 005de0f0, Math::radWrap 005cbec0.
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
