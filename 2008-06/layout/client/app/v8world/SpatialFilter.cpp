#undef _RELEASEASSERT
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

	void TreeStage::dirtyAssemblyAndRemove(Assembly* a)
	{
		if (a->inPipeline() && a->downstreamOfStage(this))
		{
			static_cast<AssemblyStage*>(getDownstream())->onAssemblyRemoving(a);
			dirtyAssembly(a);
		}
	}

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

	void TreeStage::eraseDirtyAssemblyAndDelete(Assembly* a)
	{
		eraseDirtyAssembly(a);
		delete a;
	}

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

	TreeStage::TreeStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new AssemblyStage(this, world), world)
		, maxTreeDepth(0)
		, dirty(false)
	{
	}

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
