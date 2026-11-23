// Inactive native 2008-06 recovery: rows of the RBX::Dragger unit 0060fea0..00610bee (after the Extents unit
// 0060f3e0..0060fe95; the Lua 5.1.1 library starts at luaL_where 00610bf0). Declarations are the donor
// tool/Dragger.h (read-only; no native header shadows it). Bodies written here:
//   toGrid 0060fea0, intersectingWorldOrOthers 00610130, movePrimitivesDelta 00610270, searchUpFine 00610310,
//   searchDownFine 006103a0, searchUpGross 00610440, searchDownGross 006104e0, safeMoveYDrop 00610830,
//   safeMoveNoDrop 00610930.
// movePrimitives 0060fef0 (calls DragUtilities::moveAndClean 0060e840, DragUtilitiesMoveAndClean.cpp) and computeExtents(Array) 00610070 (bound by the
// recorder at the original call sites). Step constants from .rdata: 0.1f 0081e704, -0.1f 00843764, 1.2f 00827278,
// -1.2f 00830b6c; the world floor -0.01f 00843760 and the overlap 0.01f 0082748c (intersectingWorldOrOthers).
// The 2008 search functions are not in the donor: their shapes are read from the bytes (one step, then repeat while
// the moved vector is finite and the intersection test keeps the same answer; a Gross search hands over to the
// Fine search in the opposite direction).
// Codegen analog: the recorder proves each body against the bytes; names follow the donor declarations.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "util/Math.h"
#include "v8world/Primitive.h"
#include "v8datamodel/PartInstance.h"
#include "tool/DragUtilities.h"

namespace RBX
{
	G3D::Vector3 Dragger::toGrid(const G3D::Vector3& v)
	{
		return Math::toGrid(v, dragSnap());
	}

	// 0060fef0 (?movePrimitives@Dragger@RBX@@CAXABV?$Array@PAVPrimitive@RBX@@@G3D@@ABVVector3@4@@Z): skip a zero
	// delta (Vector3::zero 0096f044 inline, three fcomp), then per primitive PartInstance::fromPrimitive 00599f80 and
	// DragUtilities::moveAndClean 0060e840. The inactive lifetime trial recorded the same body exact as applyMove.
	void Dragger::movePrimitives(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& delta)
	{
		if (delta != G3D::Vector3::zero())
		{
			for (int i = 0; i < primitives.size(); ++i)
			{
				Primitive* primitive = primitives[i];
				PartInstance* part = PartInstance::fromPrimitive(primitive);
				DragUtilities::moveAndClean(part, delta);
			}
		}
	}

	// 00610070 (?computeExtents@Dragger@RBX@@SA?AVExtents@2@ABV?$Array@PAVPrimitive@RBX@@@G3D@@@Z, inside this unit's
	// range between toGrid 0060fea0 and intersectingWorldOrOthers 00610130). Extents::negativeInfiniteExtents 00583920
	// copied into the result, then per primitive: Primitive geometry (+0x9c) gridSize (+4) times 0.5f (00819bac), the
	// Extents(-half, half) local, Primitive::getCoordinateFrame 005e82c0, Extents::toWorldSpace 0060fc20 and
	// Extents::unionWith 0057dee0. Same shape as the std::vector overload in DragPrimitiveBounds.cpp.
	Extents Dragger::computeExtents(const G3D::Array<Primitive*>& primitives)
	{
		Extents result = Extents::negativeInfiniteExtents();
		for (int i = 0; i < primitives.size(); ++i)
		{
			Primitive* primitive = primitives[i];
			G3D::Vector3 half = primitive->getGeometry()->getGridSize() * 0.5f;
			Extents world = Extents(-half, half).toWorldSpace(primitive->getCoordinateFrame());
			result.unionWith(world);
		}
		return result;
	}

	__declspec(noinline) bool Dragger::intersectingWorldOrOthers(const G3D::Array<Primitive*>& primitives, ContactManager& contactManager)
	{
		Extents group = computeExtents(primitives);
		return group.min().y < -0.01f || contactManager.intersectingOthers(primitives, 0.01f);
	}

	void Dragger::movePrimitivesDelta(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& delta, G3D::Vector3& movedSoFar)
	{
		movePrimitives(primitives, delta);
		movedSoFar = toGrid(movedSoFar + delta);
	}

	void Dragger::searchUpFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 0.1f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar) && intersectingWorldOrOthers(primitives, contactManager))
		{
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 0.1f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchDownFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -0.1f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (intersectingWorldOrOthers(primitives, contactManager))
			{
				searchUpFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -0.1f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchUpGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 1.2f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (!intersectingWorldOrOthers(primitives, contactManager))
			{
				searchDownFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 1.2f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchDownGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -1.2f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (intersectingWorldOrOthers(primitives, contactManager))
			{
				searchUpFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -1.2f, 0.0f), movedSoFar);
		}
	}

	G3D::Vector3 Dragger::safeMoveYDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager)
	{
		if (primitives.size() == 0)
		{
			return G3D::Vector3::zero();
		}

		G3D::Vector3 moved = tryMove - G3D::Vector3(0.0f, 1.2f, 0.0f);
		moved = Math::toGrid(moved, 0.1f);

		movePrimitives(primitives, moved);

		if (intersectingWorldOrOthers(primitives, contactManager))
			searchUpGross(primitives, moved, contactManager);
		else
			searchDownGross(primitives, moved, contactManager);

		return moved;
	}

	G3D::Vector3 Dragger::safeMoveNoDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager)
	{
		G3D::Vector3 movedSoFar(0.0f, 0.0f, 0.0f);

		if (primitives.size() == 0)
		{
			return G3D::Vector3::zero();
		}

		if (tryMove != G3D::Vector3::zero())
		{
			movePrimitives(primitives, tryMove);
			movedSoFar += tryMove;
		}

		if (intersectingWorldOrOthers(primitives, contactManager))
			searchUpGross(primitives, movedSoFar, contactManager);

		return movedSoFar;
	}

	// 00610a60 (registry func_00610a60; caller MegaDragger::safeRotate 0060e359): openrbx Dragger::safeRotate.
	// computeExtents 00610070, center (0.5f 00819bac), toGrid inline (Math::toGrid 005dee10, 0.1f), identity 00513e20,
	// toObjectSpace 0060e8f0, CoordinateFrame * 00476700 twice, fromPrimitive 00599f80, setCoordinateFrame 0059d8a0.
	void Dragger::safeRotate(const G3D::Array<Primitive*>& primitives, const G3D::Matrix3& rotate, ContactManager& contactManager)
	{
		if (primitives.size() != 0)
		{
			G3D::Vector3 center = toGrid(computeExtents(primitives).center());

			G3D::CoordinateFrame centerCoord(center);
			G3D::CoordinateFrame rotationCoord(rotate, G3D::Vector3::zero());

			for (int i = 0; i < primitives.size(); i++)
			{
				Primitive* primitive = primitives[i];
				G3D::CoordinateFrame primInCenter = centerCoord.toObjectSpace(primitive->getCoordinateFrame());
				G3D::CoordinateFrame newPrimInCenter = rotationCoord * primInCenter;
				G3D::CoordinateFrame primInWorld = centerCoord * newPrimInCenter;
				PartInstance* part = PartInstance::fromPrimitive(primitive);
				part->setCoordinateFrame(primInWorld);
			}
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::Array<RBX::Primitive *>;
