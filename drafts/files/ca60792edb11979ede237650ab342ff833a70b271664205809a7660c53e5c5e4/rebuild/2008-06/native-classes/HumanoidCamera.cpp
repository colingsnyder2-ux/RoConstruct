// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native RBX::Humanoid (inactive), camera / Connector rows of the original Humanoid unit (005d74a0..005dccxx)
// that need the 2008 PartInstance with the Primitive embedded at +0x228 (native-headers/part-embedded): getBody
// 005d9310, tellCameraNear 005d9df0 (+ its helper collectAllDescendantCharacterPrims 005d9d10) and
// cameraSetWalkOrientation 005dc7f0. Same split as Humanoid2008Parts.cpp: the PartInstance chain reaches the donor
// v8kernel/Connector.h, so this unit selects the donor Connector for the Humanoid base (see Humanoid2008.h); no
// constructor here, so no vtable is emitted (every vtable is built from Humanoid2008.cpp).
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "util/NativeContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid2008.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Tool.h"
#include "v8kernel/Body.h"
#include "util/Math.h"
#include <boost/bind.hpp>
#include <vector>

namespace RBX
{
	extern Reflection::PropDescriptor<Humanoid, float> propWalkRotationalVelocity;   // Humanoid2008.cpp (0097a2d8)

	// 005d9310 (Connector slot, this adjusted by -0x130): torso primitive (+0x228) body (+0xa0 -> part+0x2c8),
	// then Body::getRoot (+0x10). PARKED (draft): the part-embedded Primitive.h reaches the donor v8kernel/Body.h
	// (root +0x4), so this compiles to `mov eax, [eax + 4]` where the original reads the 2008 Body root at +0x10
	// (native-headers/v8kernel/Body2008.h, which cannot share a unit with the donor Body.h). Otherwise identical.
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

	// NOT BUILT (header proposals, see the batch result), both in this part-embedded Humanoid unit:
	// - onEvent 005dc740 (Listener<RunService, Stepped>, this adjusted by -0x1a4, `ret 0xc`): if (world +0x21c) {
	//   if (ModelInstance* m = dynamic_cast<ModelInstance*>(getParent())) 00645450(&currentState +0x220, event.step,
	//   m->getTopPVController() 0059a9e0) (an undeclared cdecl HUMAN::HumanoidState stepper); if (getTorsoPrimitive())
	//   (inlined: getTorso 005d8b10, +0x228) getTorsoPrimitive()->setCanCollide(false) (Primitive 005e75b0);
	//   checkForJointDeath() 005dc6c0 (undeclared in Humanoid2008.h); if (walkTimer > 0 && --walkTimer == 0)
	//   walkMode = DIRECTION_MOVE }. Needs getTorsoPrimitive, checkForJointDeath and the 00645450 stepper declared.
	// - render3dAdorn 005d9c30 (IRenderable, this adjusted by -0x13c): walkMode == CLICK_TO_MOVE and this ==
	//   modelIsCharacter(Players::findLocalCharacter(this)) (inlined: dynamic_cast<ModelInstance*> +
	//   findModifierOfType<Humanoid> 005d8690) and Workspace::findWorkspace 005a3380: Vector3 p(0,0,0);
	//   if (hasWalkToPoint(p) 005d79b0 && getHead() 005d8a10 && head float +0x328 != 0) renderWaypoint 005d7750; then
	//   getCharacterFromHumanoid 005d7670 -> for_eachChild(00045c600 helper: PartInstance 0059dd50(1.0f), recursing
	//   into ModelInstances); finally currentState (+0x220) -> 00645060(adorn) (undeclared HumanoidState method).
	//   Needs the PartInstance +0x328 accessor, the 0045c600 helper and HumanoidState 00645060 declared.
#ifdef NATIVE_HUMANOID2008_PENDING_GETTERS
	// 005d90a0 ?getTorsoPrimitive@Humanoid@RBX@@QBEPAVPrimitive@2@XZ (18 bytes): getTorso 005d8b10, then the embedded
	// Primitive (part + 0x228) or NULL. Siblings 005d90c0 (left leg), 005d90e0 (right leg), 005d9100 (head) have the
	// same shape. onEvent 005dc740 inlines this body (getTorso, `add eax, 0x228`), so it is defined in the Humanoid unit.
	// Pending header proposal: humanoid/Humanoid2008.h does not declare getTorsoPrimitive (or the three siblings). A
	// trial (2026-11-14) compiled this body against the donor humanoid/Humanoid.h declaration with the part-embedded
	// PartInstance (HumanoidStateFloor.cpp flags): byte-identical to 005d90a0 (18/18, relocations masked).
	Primitive* Humanoid::getTorsoPrimitive() const
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive() : NULL;
	}
#endif

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
	// in Humanoid2008.cpp, so the same statement sequence is written here. PARKED (draft): same Body conflict as
	// getBody (root +0x10 / pv +0x94 in the 2008 Body against the donor +0x4 / +0x88), and with the setter written out
	// the noAdjust branch keeps the ICharacterSubject this in edi instead of adjusting ecx by -0x14c per branch. Body::updatePV 00599360 (getPV),
	// CoordinateFrame::lookVector 005187f0, Vector3::unitize 00518470, Math::angleToE0 005de0f0, Math::radWrap 005cbec0.
	void Humanoid::cameraSetWalkOrientation(float rad, bool noAdjust)
	{
		if (noAdjust)
		{
			const float value = 0.0f;
			if (walkRotationalVelocity != value)
			{
				walkRotationalVelocity = value;
				raisePropertyChanged(propWalkRotationalVelocity);
			}
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

					if (walkRotationalVelocity != value)
					{
						walkRotationalVelocity = value;
						raisePropertyChanged(propWalkRotationalVelocity);
					}
				}
			}
		}
	}
}
