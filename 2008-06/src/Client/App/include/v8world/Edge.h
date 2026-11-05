#pragma once
#include "v8world/IPipelined.h"

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
	public:
		enum EdgeType
		{
			JOINT,
			CONTACT
		};

	private:
		Sim::EdgeState edgeState;
		Primitive* prim0;
		Primitive* prim1;
		int index0;
		int index1;
		bool inEdgeList;
  
	public:
		Edge(Primitive* prim0, Primitive* prim1);
		virtual ~Edge() 
		{
		}

		bool getInEdgeList() const;
		void setInEdgeList(bool);
		virtual EdgeType getEdgeType() const = 0;
		Sim::EdgeState getEdgeState() const;
		void setEdgeState(Sim::EdgeState);
		Primitive* getPrimitive(int i) const
		{
			return *(&this->prim0 + i);
		}
		Primitive* otherPrimitive(int) const;
		Primitive* otherPrimitive(const Primitive* p) const
		{
			return p == prim0 ? prim1 : prim0;
		}
		int getPrimitiveId(const Primitive*) const;
		int getIndex(const Primitive* p) const
		{
			return p == prim0 ? index0 : index1;
		}
		void setIndex(const Primitive* p, int i)
		{
			if (p == prim0)
				index0 = i;
			else
				index1 = i;
		}
		bool links(Primitive*, Primitive*) const;
		bool links(const Primitive* p) const
		{
			return p == prim0 || p == prim1;
		}
		virtual void setPrimitive(int i, Primitive* p);
	};
}
