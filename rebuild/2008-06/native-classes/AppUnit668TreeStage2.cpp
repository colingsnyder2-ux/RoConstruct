// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::TreeStage (inactive), second batch: tree-walk helpers and the assembly-set rows.
#include <algorithm>
#include "AppUnit668/TreeStage.h"
#include "AppUnit66C/AssemblyStage.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

namespace RBX
{
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
		int which = 0;
		Joint* lightest = 0;
		reconcile(p0, p1, p0 ? p0->getBodyDepth() : 0, p1 ? p1->getBodyDepth() : 0, lightest, which);
		if (!lightest || JointSort::lighterJoint(j, lightest))
		{
			replaceLightest(lightest, j, j->getPrimitive((which + 1) % 2));
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
	Joint* TreeStage::findLightestDownstream(Primitive* p, Primitive*& lightestOther)
	{
		std::set<Primitive*> reachable;
		reachable.insert(p);
		collectTopJoints(p, &reachable);
		Joint* lightest = 0;
		for (std::set<Primitive*>::iterator it = reachable.begin(); it != reachable.end(); ++it)
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
}
