// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Inactive native 2008-06 recovery: RBX::EdgeList::removeEdge 005e8610 (?removeEdge@EdgeList@RBX@@QAEXPAVEdge@2@@Z) and
// RBX::EdgeList::insertEdge 005e8990 (?insertEdge@EdgeList@RBX@@QAEXPAVEdge@2@@Z) of v8world/Primitive.cpp (the
// Primitive unit 005e7420..005e89ed). Flags: the sibling rows of native-classes/PrimitiveState.cpp (/fp:fast).
// Callees: G3D::Array<Edge*>::resize 005e6540 / append 005e6640 and G3D::Array<Primitive*>::resize 00599a70 /
// append 0059a190 (G3D 6.09 Array.h templates, instantiated here as COMDATs).
//
// EdgeList (owner +0x0, edges +0x4, otherPrimitives +0x10) is native-headers/v8world/Primitive2008.h.
// Unit-local redeclaration (pattern of PrimitiveState.cpp / BlockBlockContactStep.cpp): RBX::Edge is copied from
// native-headers/AppUnit658/Edge.h (same base, fields, offsets and slots) plus inline accessors that the bodies
// need and that header lacks (its fields are private, with no accessors). The binary inlines them: both bodies
// pick +0x14 / +0x18 with `cmp owner, [e+0xc]` (prim0), and insertEdge picks the other primitive the same way.
// Their names are analog names after the donor Edge.h getNext / setNext / otherPrimitive (proposal in the batch result).
#include <G3D/Array.h>
#include "v8world/Primitive2008.h"

namespace RBX
{
	namespace Sim
	{
		enum EdgeState
		{
			UNDEFINED,
			STEPPING,
			SLEEPING,
			TOUCHING,
			TOUCHING_SLEEPING
		};
	}

	class __declspec(novtable) Edge : public IPipelined
	{
	public:
		enum EdgeType
		{
			JOINT,
			CONTACT
		};

	private:
		Sim::EdgeState edgeState;                      // +0x8
		Primitive* prim0;                              // +0xc
		Primitive* prim1;                              // +0x10
		int index0;                                    // +0x14 (index in prim0's EdgeList, -1 = none)
		int index1;                                    // +0x18 (index in prim1's EdgeList, -1 = none)
		bool inEdgeList;                               // +0x1c

	public:
		Edge(Primitive* prim0, Primitive* prim1);      // 00659260
		virtual ~Edge() {}                             // slot 0

		virtual EdgeType getEdgeType() const = 0;      // slot 3
		virtual void setPrimitive(int i, Primitive* p);   // slot 4 (00659290)

		// Not in AppUnit658/Edge.h (proposal); inlined in 005e8610 / 005e8990.
		Primitive* otherPrimitive(const Primitive* p) const
		{
			return p == prim0 ? prim1 : prim0;
		}
		int getIndex(const Primitive* p) const
		{
			return p == prim0 ? index0 : index1;
		}
		void setIndex(const Primitive* p, int index)
		{
			if (p == prim0)
				index0 = index;
			else
				index1 = index;
		}
	};

	// 005e8990
	void EdgeList::insertEdge(Edge* e)
	{
		e->setIndex(owner, edges.size());
		edges.append(e);
		otherPrimitives.append(e->otherPrimitive(owner));
	}

	// 005e8610. Byte-identical to the original with relocations masked (138 B), but not credited: the prover binds this
	// unit's G3D::Array<Primitive*>::resize to 005025c0 while the original calls 00599a70 (both are folded
	// Array<pointer>::resize COMDATs, registry names ?resize@?$Array@VVector3@G3D@@ and ?resize@?$Array@PBX@G3D@@).
	// Rejected first: resize(size() - 1, false) after edges[size() - 1] (150 B, `index` spilled) and after last()
	// (138 B, this in esi instead of ebx); popDiscard() reaches the array sizes through the array pointers as the original.
	void EdgeList::removeEdge(Edge* e)
	{
		int index = e->getIndex(owner);
		Edge* lastEdge = edges.last();
		Primitive* lastPrimitive = otherPrimitives.last();
		edges[index] = lastEdge;
		otherPrimitives[index] = lastPrimitive;
		edges.popDiscard();
		otherPrimitives.popDiscard();
		lastEdge->setIndex(owner, index);
		e->setIndex(owner, -1);
	}
}
