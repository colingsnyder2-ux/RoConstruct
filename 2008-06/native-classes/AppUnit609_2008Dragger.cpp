// Inactive native 2008-06 recovery: rows of the RBX::Dragger unit 0060fea0..00610bee (after the Extents unit
// 0060f3e0..0060fe95; the Lua 5.1.1 library starts at luaL_where 00610bf0). Declarations are the donor
// tool/Dragger.h (read-only; no native header shadows it). Bodies written here:
//   toGrid 0060fea0, intersectingWorldOrOthers 00610130, movePrimitivesDelta 00610270, searchUpFine 00610310,
//   searchDownFine 006103a0, searchUpGross 00610440, searchDownGross 006104e0, safeMoveYDrop 00610830,
//   safeMoveNoDrop 00610930.
// Out-of-unit-recovered rows called here: movePrimitives 0060fef0 and computeExtents(Array) 00610070 (bound by the
// recorder at the original call sites). Step constants from .rdata: 0.1f 0081e704, -0.1f 00843764, 1.2f 00827278,
// -1.2f 00830b6c; the world floor -0.01f 00843760 and the overlap 0.01f 0082748c (intersectingWorldOrOthers).
// The 2008 search functions are not in the donor: their shapes are read from the bytes (one step, then repeat while
// the moved vector is finite and the intersection test keeps the same answer; a Gross search hands over to the
// Fine search in the opposite direction).
// Codegen analog: the recorder proves each body against the bytes; names follow the donor declarations.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "util/Math.h"

namespace RBX
{
	G3D::Vector3 Dragger::toGrid(const G3D::Vector3& v)
	{
		return Math::toGrid(v, dragSnap());
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
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::Array<RBX::Primitive *>;
