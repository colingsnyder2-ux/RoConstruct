// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::TreeStage (inactive), second batch: tree-walk helpers and the assembly-set rows.
#include <algorithm>
#include "AppUnit668/TreeStage.h"
#include "AppUnit66C/AssemblyStage.h"
#include "v8kernel/Body2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

namespace RBX
{
	// 00668cd0 (registry func_00668cd0; TreeStage::createAssembly, declared INFERRED in AppUnit668/TreeStage.h; only
	// caller processEdge 00669560): `push 0x78; call new`, Clump(Primitive*) 005e6cf0 under the new-expression EH state.
	// The donor openrbx ClumpStage2.cpp spells this `new Clump(child)` into an Assembly*; in the native layout
	// Assembly is the never-constructed Clump view (AssemblyLayout.h), hence the static_cast (no code).
	Assembly* TreeStage::createAssembly(Primitive* p)
	{
		return static_cast<Assembly*>(new Clump(p));
	}

	// 00669090
	void TreeStage::reconcile(Primitive* left, Primitive* right, int leftDepth, int rightDepth, Joint*& lightest, int& lightestSide)
	{
		for (;;)
		{
			if (leftDepth != rightDepth)
			{
				if (leftDepth > rightDepth)
				{
					--leftDepth;
					left = ascend(0, left, lightest, lightestSide);
				}
				else
				{
					--rightDepth;
					right = ascend(1, right, lightest, lightestSide);
				}
			}
			else
			{
				if (left == right)
					return;
				left = left ? ascend(0, left, lightest, lightestSide) : 0;
				Primitive* nextRight = right ? ascend(1, right, lightest, lightestSide) : 0;
				--rightDepth;
				--leftDepth;
				right = nextRight;
			}
		}
	}

	// 006691e0
	void TreeStage::dirtyAssemblyAndRemove(Assembly* a)
	{
		if (a->inPipeline() && a->downstreamOfStage(this))
		{
			static_cast<AssemblyStage*>(getDownstream())->onAssemblyRemoving(a);
			dirtyAssembly(a);
		}
	}

	// 00669290
	void TreeStage::eraseDirtyAssembly(Assembly* a)
	{
		assemblies.erase(a);
		if (a->inPipeline())
		{
			if (a->downstreamOfStage(this))
				static_cast<AssemblyStage*>(getDownstream())->onAssemblyRemoving(a);
			a->removeFromPipeline(this);
		}
	}

	// 006692e0
	void TreeStage::eraseDirtyAssemblyAndDelete(Assembly* a)
	{
		eraseDirtyAssembly(a);
		delete a;
	}

	// 00668f20
	void TreeStage::cleanAssembly(Assembly* a)
	{
		if (!a->inPipeline())
			a->putInStage(this);
		bool deeper = a->downstreamOfStage(this);
		bool wantDownstream = !a->getAnchored();
		if (deeper != wantDownstream)
		{
			if (wantDownstream)
				static_cast<AssemblyStage*>(getDownstream())->onAssemblyAdded(a);
			else
				static_cast<AssemblyStage*>(getDownstream())->onAssemblyRemoving(a);
		}
		else if (deeper)
			static_cast<AssemblyStage*>(getDownstream())->wakeAssembly(a);
	}

	// 00668fa0
	void TreeStage::cleanEdge(Edge* e)
	{
		Assembly* a0 = e->getPrimitive(0)->getAssemblyNoCheck();
		Assembly* a1 = e->getPrimitive(1)->getAssemblyNoCheck();
		bool deeper = e->downstreamOfStage(this);
		bool wantDownstream = a0 != a1 && (!a0->getAnchored() || a1->getAnchored() == false);
		if (deeper != wantDownstream)
		{
			if (deeper)
				static_cast<AssemblyStage*>(getDownstream())->onEdgeRemoving(e);
			else
				static_cast<AssemblyStage*>(getDownstream())->onEdgeAdded(e);
		}
	}

	// 00669150
	void TreeStage::collectTopJoints(Primitive* p, std::set<Primitive*>* out)
	{
		for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
		{
			if (j->getActive() && static_cast<Edge*>(j)->getEdgeType() == Edge::JOINT && j->getJointType() >= Joint::ANCHOR_JOINT)
			{
				Primitive* other = j->getPrimitive(0);
				if (p == other)
					other = j->getPrimitive(1);
				Primitive* value = other;
				if (other == getTopPrimitive(j))
				{
					out->insert(value);
					collectTopJoints(other, out);
				}
			}
		}
	}

	// INFERRED: 005e89f0 (Edge* cdecl): inserts the edge into its primitives' edge lists
	void insertEdgeIntoPrimitives(Edge* e);
	// INFERRED: 005e86a0 (Edge* cdecl): the removal counterpart, called last by onEdgeRemoving 00669c70
	void removeEdgeFromPrimitives(Edge* e);

	class JointSort
	{
	public:
		static bool lighterJoint(const Joint* a, const Joint* b);   // 00668e20
	};

	static Joint::JointType jointTypeOf(Edge* e)
	{
		if (e->getEdgeType() == Edge::JOINT)
			return static_cast<Joint*>(e)->getJointType();
		return Joint::NO_JOINT;
	}

	// 00669b60
	void TreeStage::addJointEdge(Joint* j)
	{
		Primitive* p1 = j->getPrimitive(1);
		Primitive* p0 = j->getPrimitive(0);
		// INFERRED: the two reconcile outputs sit in one 8-byte local (joint +0, side +4; side is zeroed first) and
		// depth0 takes j's home slot; separate Joint* / int locals put the joint in j's home slot instead.
		struct
		{
			Joint* joint;
			int side;
		} lightest;
		lightest.side = 0;
		lightest.joint = 0;
		int depth0 = p0 ? p0->getBodyDepth() : 0;
		int depth1 = p1 ? p1->getBodyDepth() : 0;
		reconcile(p0, p1, depth0, depth1, lightest.joint, lightest.side);
		if (!lightest.joint || JointSort::lighterJoint(j, lightest.joint))
		{
			replaceLightest(lightest.joint, j, j->getPrimitive((lightest.side + 1) % 2));
			dirty = true;
		}
	}

	// 00669c00
	void TreeStage::onEdgeAdded(Edge* e)
	{
		jointTypeOf(e);
		insertEdgeIntoPrimitives(e);
		e->putInStage(this);
		if (jointTypeOf(e) >= Joint::ANCHOR_JOINT)
			addJointEdge(static_cast<Joint*>(e));
		else
			addPendingEdge(e);
	}

	// 00669870
	TreeStage::TreeStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new AssemblyStage(this, world), world)
		, maxTreeDepth(0)
		, dirty(false)
	{
	}

	// 00669340
	void TreeStage::addPendingEdge(Edge* e)
	{
		if (dirty)
		{
			bool inList = e->getInEdgeList();
			Edge* value = e;
			if (!inList)
			{
				edges.insert(value);
				dirty = true;
				e->setInEdgeList(true);
			}
		}
		else
		{
			cleanEdge(e);
		}
	}

	// 00669560
	void TreeStage::processEdge(Edge* e, Primitive* from)
	{
		Primitive* other = e->getPrimitive(0);
		if (from == other)
			other = e->getPrimitive(1);
		Assembly* a = static_cast<Assembly*>(other->getClump());
		bool isRoot = a && a->getRootPrimitive() == other;
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint::JointType type = static_cast<Joint*>(e)->getJointType();
			if (type == Joint::WELD_JOINT || type == Joint::SNAP_JOINT)
			{
				if (a == from->getClump() && other->getBody()->getParent() == from->getBody() && !other->getBody()->getLink())
				{
					Clump::updateRigidChild(from, static_cast<Joint*>(e), other);
					return;
				}
				if (a)
				{
					if (isRoot)
						eraseDirtyAssemblyAndDelete(a);
					else
					{
						dirtyAssemblyAndRemove(a->getAssembly());
						a->removePrimitive(other);
					}
				}
				dirtyAssemblyAndRemove(from->getAssembly());
				Clump::addRigidChild(from, static_cast<Joint*>(e), other);
				return;
			}
		}
		if (isRoot)
		{
			dirtyAssemblyAndRemove(a->getAssembly());
			other->getBody()->setParent(NULL);
			a->setParent(NULL);
		}
		else
		{
			if (a)
			{
				dirtyAssemblyAndRemove(a->getAssembly());
				a->removePrimitive(other);
			}
			a = createAssembly(other);
		}
		if (e->getEdgeType() == Edge::JOINT && static_cast<Joint*>(e)->getJointType() == Joint::MOTOR_JOINT)
		{
			dirtyAssemblyAndRemove(from->getAssembly());
			eraseDirtyAssembly(a);
			Assembly::addMotorChild(from, static_cast<MotorJoint*>(static_cast<Joint*>(e)), other);
			return;
		}
		Joint::JointType type = static_cast<Joint*>(e)->getJointType();
		if (type == Joint::FREE_JOINT || type == Joint::ANCHOR_JOINT)
			dirtyAssembly(a);
	}

	// 006697a0
	void TreeStage::walkEdges(Edge* e, Primitive* from, int depth)
	{
		maxTreeDepth = std::max(maxTreeDepth, depth);
		processEdge(e, from);
		Primitive* p = e->otherPrimitive(from);
		for (Edge* next = p->getFirstEdge(); next; next = p->getNextEdge(next))
		{
			if (next->getEdgeType() == Edge::JOINT && static_cast<Joint*>(next)->getJointType() >= Joint::ANCHOR_JOINT)
			{
				if (static_cast<Joint*>(next)->getActive())
				{
					Primitive* other = next->getPrimitive(0);
					if (p == other)
						other = next->getPrimitive(1);
					if (other && other != from)
						walkEdges(next, p, depth + 1);
				}
			}
			else
			{
				Edge* value = next;
				if (!next->getInEdgeList())
				{
					edges.insert(value);
					dirty = true;
					next->setInEdgeList(true);
				}
			}
		}
	}

	// 006699a0
	// The iterator is declared before the loop and assigned: 00669a02..00669a12 load begin() (`mov eax, [eax]`) and copy
	// it into the loop register (`mov ebx, eax`); the for-init declaration form fuses the two (`mov ebx, [eax]`).
	Joint* TreeStage::findLightestDownstream(Primitive* p, Primitive*& lightestOther)
	{
		std::set<Primitive*> reachable;
		reachable.insert(p);
		collectTopJoints(p, &reachable);
		Joint* lightest = 0;
		std::set<Primitive*>::iterator it;
		for (it = reachable.begin(); it != reachable.end(); ++it)
		{
			Primitive* q = *it;
			for (Joint* j = q->getFirstJoint(); j; j = q->getNextJoint(j))
			{
				if (!j->getActive() && static_cast<Edge*>(j)->getEdgeType() == Edge::JOINT && j->getJointType() >= Joint::ANCHOR_JOINT)
				{
					Primitive* other = j->otherPrimitive(q);
					if (!other || reachable.find(other) == reachable.end())
					{
						if (!lightest || JointSort::lighterJoint(j, lightest))
						{
							lightest = j;
							lightestOther = other;
						}
					}
				}
			}
		}
		return lightest;
	}

	// 00669410: cleanAssembly 00668f20 over assemblies +0x38 (the iterator declared before the loop, as in
	// findLightestDownstream), the inline clear (_Erase 00669050), then cleanEdge 00668fa0 / inEdgeList +0x1c = false /
	// erase 0064aa20 of edges.begin() while edges +0x58 is non-empty (size +0x74), and dirty +0x14 = false.
	void TreeStage::process()
	{
		if (dirty)
		{
			std::set<Assembly*>::iterator it;
			for (it = assemblies.begin(); it != assemblies.end(); ++it)
			{
				cleanAssembly(*it);
			}
			assemblies.clear();

			while (edges.size() != 0)
			{
				std::set<Edge*>::iterator e = edges.begin();
				cleanEdge(*e);
				(*e)->setInEdgeList(false);
				edges.erase(e);
			}

			dirty = false;
		}
	}

	// 00669c70: getTopPrimitive 005e7490 is called before lightestOther is zeroed (00669c9a..00669caa), so the top
	// primitive is a named local ahead of it; findLightestDownstream 006699a0, replaceLightest 00669940, dirty +0x14;
	// other edges go to 00669710; then IPipelined::removeFromStage 00645840 and 005e86a0.
	void TreeStage::onEdgeRemoving(Edge* e)
	{
		if (jointTypeOf(e) >= Joint::ANCHOR_JOINT)
		{
			Joint* j = static_cast<Joint*>(e);
			if (j->getActive())
			{
				Primitive* top = getTopPrimitive(j);
				Primitive* lightestOther = 0;
				Joint* lightest = findLightestDownstream(top, lightestOther);
				replaceLightest(j, lightest, lightestOther);
				dirty = true;
			}
		}
		else
		{
			onEdgeRemovingNonJoint(e);
		}
		e->removeFromStage(this);
		removeEdgeFromPrimitives(e);
	}

	// 00669710: edges that are not anchoring joints (onEdgeRemoving 00669c70): the downstream onEdgeRemoving (slot 5)
	// when the edge is downstream of this stage, then edges +0x58 erase-by-key 005e9f60 and inEdgeList +0x1c = false.
	// The key copy is stored before the inEdgeList test (00669741), as in walkEdges.
	void TreeStage::onEdgeRemovingNonJoint(Edge* e)
	{
		if (e->downstreamOfStage(this))
		{
			static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(e);
		}
		Edge* value = e;
		if (e->getInEdgeList())
		{
			edges.erase(value);
			e->setInEdgeList(false);
		}
	}
}
