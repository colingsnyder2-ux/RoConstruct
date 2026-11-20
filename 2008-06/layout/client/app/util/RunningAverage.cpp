#include "v8world/JointStage2008.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include "util/RunningAverage.h"
#include "util/Math.h"

namespace RBX
{
	class ClumpStage : public IWorldStage
	{
	private:
		std::set<Edge*> set10;                       // +0x10 INFERRED: see ClumpStage2008.h

	public:
		ClumpStage(IStage* upstream, World* world); // 0064cfd0
		~ClumpStage();                              // 0064cf50

		virtual StageType getStageType();           // slot 1 (CLUMP_STAGE, folded constant)
		virtual void onEdgeAdded(Edge* e);          // slot 4 (0064cec0)
		virtual void onEdgeRemoving(Edge* e);       // slot 5 (0064cf10)
	};

	JointStage::JointStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new ClumpStage(this, world), world)
	{
	}

	IStage::StageType JointStage::getStageType()
	{
		return JOINT_STAGE;
	}

	JointStage::~JointStage()
	{
	}

	bool JointStage::edgeHasPrimitivesDownstream(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);
		if (p0->inPipeline() && p1->inPipeline() && p0->downstreamOfStage(this) && p1->downstreamOfStage(this))
			return true;
		return false;
	}

	void JointStage::insertToListAndMap(Edge* e)
	{
		Joint* j = rbx_static_cast<Joint*>(e);
		incompleteJoints.insert(j);
		if (Primitive* p0 = j->getPrimitive(0))
			jointMap.insert(std::make_pair(p0, j));
		if (Primitive* p1 = j->getPrimitive(1))
			jointMap.insert(std::make_pair(p1, j));
	}

	void JointStage::removeFromMap(Joint* j, Primitive* p)
	{
		if (p)
		{
			typedef std::multimap<Primitive*, Joint*>::iterator Iterator;
			Iterator it;
			for (it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); ++it)
			{
				if (it->second == j)
				{
					jointMap.erase(it);
					return;
				}
			}
		}
	}

	void JointStage::onEdgeAdded(Edge* e)
	{
		e->putInStage(this);
		if (edgeHasPrimitivesDownstream(e))
			getDownstreamWS()->onEdgeAdded(e);
		else
			insertToListAndMap(e);
	}

	void JointStage::onEdgeRemoving(Edge* e)
	{
		if (e->downstreamOfStage(this))
		{
			getDownstreamWS()->onEdgeRemoving(e);
		}
		else
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			incompleteJoints.erase(j);
			removeFromMap(j, j->getPrimitive(0));
			removeFromMap(j, j->getPrimitive(1));
		}
		e->removeFromStage(this);
	}

	bool RunningAverageState::withinTolerance(const G3D::CoordinateFrame& cofm, float radius, float tolerance)
	{
		G3D::Vector3 deltaPos = Math::vector3Abs(this->position - cofm.translation);
		if (Math::maxAxisLength(deltaPos) > tolerance)
			return false;
		Quaternion deltaAngles = Quaternion(cofm.rotation) * radius;
		if ((this->angles - deltaAngles).maxComponent() > tolerance)
			return false;
		return true;
	}
}

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Joint *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> > >;
template class std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1>;
template class std::_Tree<std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1> >;
template class std::_Tree<std::_Tset_traits<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *>,0> >;
template class std::allocator<RBX::Joint *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *>,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >;
