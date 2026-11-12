#pragma once
// 2008-06 native RBX::Edge (inactive), declared under a non-colliding name: v8world/Edge.h is the donor header, whose
// Edge keeps Edge* next0 / next1 links at +0x14 / +0x18 and whose base comes from the donor v8world/IPipelined.h. This
// header builds on native-headers/v8kernel/IPipelined2008.h and must not be included in a unit that also reaches the
// donor v8world/Edge.h (for example through v8world/Contact2008.h).
//
// Read from the 2008-06 binary (tests/record_native_app_unit658.py checks the offsets and the two bodies):
//   RTTI     BallBallContact 008436bc -> Contact -> Edge -> IPipelined, all at mdisp 0. Edge has no vtable of its own:
//            Edge(prim0, prim1) 00659260 stores no vtable, and Contact() 00606c20 stores only the most-derived one, so it
//            is __declspec(novtable) like IPipelined.
//   slots    after IPipelined's 0..2: 3 getEdgeType (pure here; Contact's folded `mov eax, 1` 007286a0), 4 setPrimitive
//            00659290 (slot 4 of every Ball/Block contact vtable, world-shapes-working.json).
//   fields   Edge(prim0, prim1) 00659260: currentStage +0x4 = 0 (IPipelined), +0x8 = 0, prim0 +0xc, prim1 +0x10,
//            +0x14 = +0x18 = -1, +0x1c (byte) = false. setPrimitive 00659290 stores p to +0xc when i == 0, else to +0x10.
//            +0x14 / +0x18 hold the edge's index in prim0's / prim1's EdgeList (Primitive2008.h: getNextContact
//            005e7be0 compares `index + 1` with contacts.edges.size()); -1 = not in a list. +0x8 is a 4-byte state
//            zeroed by the constructor; its name and enum (edgeState / Sim::EdgeState, UNDEFINED = 0) follow the donor
//            shape. +0x1c is the donor inEdgeList flag. Contact's own fields start at +0x20 (Contact2008.h: lastContactStep
//            +0x20 written after Edge(prim0, prim1) in 00606c20), so sizeof(Edge) is 0x20.
#include "v8kernel/IPipelined2008.h"

struct NativeAppUnit658Layout;

namespace RBX
{
	class Primitive;

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
		friend struct ::NativeAppUnit658Layout; // tests/record_native_app_unit658.py offset checks

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
	};
}
