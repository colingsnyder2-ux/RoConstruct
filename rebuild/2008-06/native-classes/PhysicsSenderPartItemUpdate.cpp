// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::PhysicsSender::PartItem::update (inactive), declared in Network/PhysicsSenders2008.h.
// It belongs to the PhysicsSender unit (PhysicsSenderRecovery_004cce00.cpp holds resetPhysicsItem 004c9cf0 and the
// .data float 0093cc40 between this body's tuning floats); it has its own file because that unit was not assigned to
// this batch. Flags copied from that unit.
#define NATIVE_PRIMITIVE_NATIVE_BODY // part-embedded Primitive.h without the donor Clump.h / Edge.h
#define NATIVE_CLUMP_DECL            // the 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h (getMaxRadius)
#include "Network/PhysicsSenders2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8world/AssemblyLayout.h"
#include "util/Math.h"
#include <G3D/g3dmath.h>
#include <float.h>

namespace
{
	// Mutable .data floats of the sender unit, next to physicsResetValue 0093cc40 (PhysicsSenderRecovery_004cce00.cpp).
	float physicsMinError = 3.0f;          // 0093cc38 INFERRED name: low bound of the error clamp in 004c9e30
	float physicsMaxError = 1000.0f;       // 0093cc3c INFERRED name: high bound of the error clamp in 004c9e30
	float physicsMaxAccumulated = 50.0f;   // 0093cc44 INFERRED name: high bound of the accumulated clamp in 004c9e30
}

namespace RBX
{
	namespace Network
	{
		// 004c9e30 (registry placeholder func_004c9e30; thiscall, ret 0xc). Evidence: returns false when lastSendStep
		// (+0x44) >= the step argument; Primitive::getAssembly 005e7570 of the part's embedded Primitive (+0x228) and
		// the assembly's inline maxRadius ComputeProp (+0x50); G3D::clamp (inline g3dmath.inl shape) with the .data
		// floats 0093cc44 / 0093cc38 / 0093cc3c; getCoordinateFrame 00598cb0; taxi-cab distances (fabs sums); a first
		// send (lastSendStep == -1) copies the frame; Instance::isDescendentOf 00422ae0 of the character gives DBL_MAX
		// (00826848); otherwise Matrix3::operator!= 005132d0 adds 1 for a rotation change.
		bool PhysicsSender::PartItem::update(const G3D::CoordinateFrame& reference, ModelInstance* character, int newSequence)
		{
			if (lastSendStep >= newSequence)
				return false;

			Assembly* assembly = part->getPrimitive()->getAssembly();
			if (assembly)
				accumulated = G3D::clamp(assembly->getMaxRadius() * 2.0f, accumulated, physicsMaxAccumulated);
			float radius = assembly ? assembly->getMaxRadius() : 0.0f;

			error = Math::taxiCabMagnitude(part->getCoordinateFrame().translation - reference.translation) - radius;
			error = G3D::clamp(error, physicsMinError, physicsMaxError);

			// NEAR MISS (b37 nw01, 468 of 472 B; first divergence at insn 93): the target keeps the part pointer in esi
			// across isDescendentOf 00422ae0 into the first getCoordinateFrame of the last branch, and stores
			// lastSendStep before the priority in the last two branches (this shared tail stores it after).
			// Tried: (1) separate returns per branch (edi caches newSequence from insn 2: worse); (2) this shared tail
			// (kept); first-send priority `accumulated * accumulated / error` (kept: loads accumulated once like the
			// target, `accumulated / error * accumulated` used memory operands); (3) per-branch lastSendStep stores in
			// the target order with one return (edi cache again: rejected). Parked after three hypotheses.
			if (lastSendStep == -1)
			{
				priority = accumulated * accumulated / error;
				lastFrame = part->getCoordinateFrame();
			}
			else if (part->isDescendentOf(character))
			{
				priority = DBL_MAX;
			}
			else
			{
				float delta = Math::taxiCabMagnitude(part->getCoordinateFrame().translation - lastFrame.translation);
				float rotation = (part->getCoordinateFrame().rotation != lastFrame.rotation) ? 1.0f : 0.0f;
				priority = (rotation + delta) / error * accumulated * accumulated;
			}
			lastSendStep = newSequence;
			return true;
		}
	}
}
