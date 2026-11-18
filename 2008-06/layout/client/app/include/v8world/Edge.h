#pragma once
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

		Sim::EdgeState getEdgeState() const
		{
			return edgeState;
		}
		void setEdgeState(Sim::EdgeState state)
		{
			edgeState = state;
		}
		bool getInEdgeList() const                     // INFERRED: donor Edge.h inline over +0x1c (TreeStage 00669340 reads / sets it)
		{
			return inEdgeList;
		}
		void setInEdgeList(bool value)
		{
			inEdgeList = value;
		}
		Primitive* getPrimitive(int i) const           // donor Edge.h inline; the Joints2008.h / Contact2008.h includers
		{                                              // call it (exact bodies built against the donor copy)
			return *(&this->prim0 + i);
		}
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
}
