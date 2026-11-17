#include "RbxGraphics/AdornRbxGfx2008.h"
#include <OgreSceneNode.h>
#include <OgreMatrix3.h>
#include <OgreMatrix4.h>
#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include "util/Utilities.h"
#include "RenderLib/TextureProxy2008.h"

template class std::map<std::string, Ogre::MeshPtr>;
template class std::_Tree<std::_Tmap_traits<std::string, Ogre::MeshPtr, std::less<std::string>,
                                            std::allocator<std::pair<const std::string, Ogre::MeshPtr> >, false> >;
template class std::map<std::string, Ogre::SceneNode*>;
template class std::_Tree<std::_Tmap_traits<std::string, Ogre::SceneNode*, std::less<std::string>,
                                            std::allocator<std::pair<const std::string, Ogre::SceneNode*> >, false> >;
template class std::vector<Ogre::RbxSubEntity*>;
template class std::vector<Ogre::SceneNode*>;

namespace RBX
{
    static int nameCounter;

    void AdornRbxGfx::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
    {
        objectToWorld = c;
    }

    void AdornRbxGfx::setColor(const G3D::Color4& color)
    {
    }

    void AdornRbxGfx::lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale)
    {
    }

    void AdornRbxGfx::axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale)
    {
    }

    // G3D::Matrix3 / Vector3 and Ogre::Matrix3 / Vector3 share their float layout; the original passes the addresses of
    // objectToWorld.rotation (+0x114) and .translation (+0x138) straight to the Ogre calls.
    void AdornRbxGfx::getObjectToWorld(Ogre::Matrix4& transform, const Ogre::Vector3& offset, const Ogre::Vector3& scale,
                                       const Ogre::Quaternion& rotation)
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        q = q * rotation;
        transform.makeTransform(offset + reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation), scale, q);
    }

    void AdornRbxGfx::getObjectToWorld(Ogre::Matrix4& transform)
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        transform.makeTransform(reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation),
                                Ogre::Vector3(1, 1, 1), q);
    }

    std::string AdornRbxGfx::uniqueName()
    {
        int id = nameCounter++;
        return StringConverter<int>::convertToString(id);
    }

    void AdornRbxGfx::releaseSubEntities()
    {
        for (int i = 0; i < (int)usedSubEntities.size(); ++i)
            freeSubEntities.push_back(usedSubEntities[i]);
        usedSubEntities.clear();
    }

    TextureProxyBaseRef AdornRbxGfx::createTextureProxy(const std::string& filename)
    {
        return new RenderNew::TextureProxy(filename);
    }
}

template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::SceneNode *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> > >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >,std::iterator<std::random_access_iterator_tag,Ogre::RbxSubEntity *,int,Ogre::RbxSubEntity * const *,Ogre::RbxSubEntity * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >,std::iterator<std::random_access_iterator_tag,Ogre::SceneNode *,int,Ogre::SceneNode * const *,Ogre::SceneNode * const &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >,std::iterator<std::random_access_iterator_tag,Ogre::RbxSubEntity *,int,Ogre::RbxSubEntity * *,Ogre::RbxSubEntity * &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >,std::iterator<std::random_access_iterator_tag,Ogre::SceneNode *,int,Ogre::SceneNode * *,Ogre::SceneNode * &> >;
template class std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >;
template class std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::_Node *>;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::iterator>;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> > >;

// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#define BOOST_SIGNALS_SOURCE

#include <boost/signals/detail/named_slot_map.hpp>
#include <cassert>
#include <map>
#include <list>
#include <typeinfo>

namespace boost { namespace BOOST_SIGNALS_NAMESPACE { namespace detail {

typedef std::list<connection_slot_pair> group_list;
typedef group_list::iterator slot_pair_iterator;
typedef std::map<stored_group, group_list, compare_type> slot_container_type;
typedef slot_container_type::iterator group_iterator;
typedef slot_container_type::const_iterator const_group_iterator;

#if BOOST_WORKAROUND(_MSC_VER, <= 1400)
void named_slot_map_iterator::decrement() { assert(false); }
void named_slot_map_iterator::advance(difference_type) { assert(false); }
#endif

named_slot_map::named_slot_map(const compare_type& compare) : groups(compare)
{
  clear();
}

void named_slot_map::clear()
{
  groups.clear();
  groups[stored_group(stored_group::sk_front)];
  groups[stored_group(stored_group::sk_back)];
  back = groups.end();
  --back;
}

named_slot_map::iterator named_slot_map::begin()
{
  return named_slot_map::iterator(groups.begin(), groups.end());
}

named_slot_map::iterator named_slot_map::end()
{
  return named_slot_map::iterator(groups.end(), groups.end());
}

named_slot_map::iterator
named_slot_map::insert(const stored_group& name, const connection& con,
                       const any& slot, connect_position at)
{
  group_iterator group;
  if (name.empty()) {
    switch (at) {
    case at_front: group = groups.begin(); break;
    case at_back: group = back; break;
    }
  } else {
    group = groups.find(name);
    if (group == groups.end()) {
      slot_container_type::value_type v(name, group_list());
      group = groups.insert(v).first;
    }
  }
  iterator it;
  it.group = group;
  it.last_group = groups.end();

  switch (at) {
  case at_back:
    group->second.push_back(connection_slot_pair(con, slot));
    it.slot_ = group->second.end();
    it.slot_assigned = true;
    --(it.slot_);
    break;

  case at_front:
    group->second.push_front(connection_slot_pair(con, slot));
    it.slot_ = group->second.begin();
    it.slot_assigned = true;
    break;
  }
  return it;
}

void named_slot_map::disconnect(const stored_group& name)
{
  group_iterator group = groups.find(name);
  if (group != groups.end()) {
    slot_pair_iterator i = group->second.begin();
    while (i != group->second.end()) {
      slot_pair_iterator next = i;
      ++next;
      i->first.disconnect();
      i = next;
    }
    groups.erase(group);
  }
}

void named_slot_map::erase(iterator pos)
{
  // Erase the slot
  pos.slot_->first.disconnect();
  pos.group->second.erase(pos.slot_);
}

void named_slot_map::remove_disconnected_slots()
{
  // Remove any disconnected slots
  group_iterator g = groups.begin();
  while (g != groups.end()) {
    slot_pair_iterator s = g->second.begin();
    while (s != g->second.end()) {
      if (s->first.connected()) ++s;
      else g->second.erase(s++);
    }

    // Clear out empty groups
    if (empty(g)) groups.erase(g++);
    else ++g;
  }
}

} } }

#include "v8world/GeoPair2008.h"
#include "util/Math.h"

namespace RBX
{
	GeoPair::GeoPair()
	{
		this->body0 = NULL;
		this->body1 = NULL;
		this->offset0 = NULL;
		this->offset1 = NULL;
	}

	void GeoPair::computeNormalPerpVel(float& normalVel, G3D::Vector3& perpVel, const PairParams& _params)
	{
		G3D::Vector3 body0Velocity = this->body0->getPVUnsafe().linearVelocityAtPoint(_params.position);
		G3D::Vector3 body1Velocity = this->body1->getPVUnsafe().linearVelocityAtPoint(_params.position);
		body1Velocity -= body0Velocity;

		float body1VelDot = _params.normal.dot(body1Velocity);
		normalVel = body1VelDot;
		G3D::Vector3 normalVelMul = _params.normal * body1VelDot;
		perpVel = body1Velocity - normalVelMul;
	}

	void GeoPair::forceToBodies(const G3D::Vector3& _force, const G3D::Vector3& _position)
	{
		this->body0->accumulateForce(-_force, _position);
		this->body1->accumulateForce(_force, _position);
	}

	void GeoPair::computeBallBall(PairParams& _params)
	{
		const PV& body0PV = this->body0->getPVUnsafe();
		const PV& body1PV = this->body1->getPVUnsafe();

		const G3D::Vector3& body0Trans = body0PV.position.translation;
		const G3D::Vector3& body1Trans = body1PV.position.translation;

		_params.normal = body1Trans - body0Trans;
		_params.length = _params.normal.unitize() - this->pairData.radiusSum;
		_params.position = _params.normal * this->pairData.radius0 + body0Trans;
	}

	void GeoPair::computeBallPoint(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;

		_params.position = coord1.pointToWorldSpace(*this->offset1);
		_params.normal = _params.position - pos0;
		_params.length = _params.normal.unitize() - this->pairData.radius0;
	}

	static G3D::Vector3 somemaththing(const G3D::Vector3& normal, const G3D::Vector3& trans)
	{
		return trans - normal * normal.dot(trans);
	}

	void GeoPair::computeBallEdge(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;

		G3D::Vector3 edgePoint = coord1.pointToWorldSpace(*this->offset1);
		G3D::Vector3 edge = Math::getWorldNormal(this->pairData.normalID1, coord1);
		G3D::Vector3 delta = edgePoint - pos0;

		_params.normal = delta - edge * delta.dot(edge);
		_params.position = pos0 + _params.normal;
		_params.length = _params.normal.unitize() - this->pairData.radius0;
	}

	void GeoPair::computeBallPlane(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;
		G3D::Vector3 planePoint = coord1.pointToWorldSpace(*this->offset1);

		_params.normal = -Math::getWorldNormal(this->pairData.normalID1, coord1);

		G3D::Vector3 delta = planePoint - pos0;
		G3D::Vector3 toPlane = _params.normal * delta.dot(_params.normal);

		_params.position = pos0 + toPlane;
		_params.length = toPlane.magnitude() - this->pairData.radius0;
	}

	void GeoPair::computePointPlane(RBX::PairParams& _params)
	{
		_params.position = this->body0->getPVUnsafe().position.pointToWorldSpace(*offset0);
		const G3D::CoordinateFrame& body1PV = this->body1->getPVUnsafe().position;
		G3D::Vector3 body1worldSpace = body1PV.pointToWorldSpace(*offset1);
		_params.normal = -Math::getWorldNormal(this->pairData.normalID1, body1PV);
		_params.length = _params.normal.dot(body1worldSpace - _params.position);
	}

	// is this actually an inline?
	__forceinline float unkClampInline(float d, float max)
	{
		if (fabs(d) > max)
			return max * Math::sign(d);

		return d;
	}

	void GeoPair::computeEdgeEdgePlane(RBX::PairParams& _params)
	{
		const G3D::CoordinateFrame& body0PV = this->body0->getPVUnsafe().position;
		const G3D::CoordinateFrame& body1PV = this->body1->getPVUnsafe().position;

		//world space defines
		G3D::Vector3 body0worldSpace = body0PV.pointToWorldSpace(*this->offset0);
		G3D::Vector3 body1worldSpace = body1PV.pointToWorldSpace(*this->offset1);
		//normals
		G3D::Vector3 body0Normal = Math::getWorldNormal(this->pairData.normalID0, body0PV);
		G3D::Vector3 body1Normal = Math::getWorldNormal(this->pairData.normalID1, body1PV);
		//calcs
		G3D::Vector3 bodyWorldSpaceDelta = body1worldSpace - body0worldSpace;
		float bodyNormalDot = body0Normal.dot(body1Normal);
		float compareResult = 1.0f - bodyNormalDot * bodyNormalDot;
		_params.normal = -Math::getWorldNormal(this->pairData.planeID, body1PV.rotation);
		if ( compareResult > 0.00001 )
		{
			float body1Dot = -bodyWorldSpaceDelta.dot(body1Normal);
			float body0Dot = bodyWorldSpaceDelta.dot(body0Normal);
			float theSinner = (body0Dot + (bodyNormalDot * body1Dot)) / compareResult;
			theSinner = unkClampInline(theSinner, 6.0f);
			_params.position = body0Normal * theSinner + body0worldSpace;
			_params.length = _params.normal.dot(body1worldSpace - _params.position);
		}
		else
		{
			_params.position = body0worldSpace;
			_params.length = 0.0;
		}
	}

	void GeoPair::computeEdgeEdge(RBX::PairParams& _params)
	{
		const G3D::CoordinateFrame& body0coord = this->body0->getPVUnsafe().position;
		const G3D::CoordinateFrame& body1coord = this->body1->getPVUnsafe().position;

		//world space defines
		G3D::Vector3 body0worldSpace = body0coord.pointToWorldSpace(*this->offset0);
		G3D::Vector3 body1worldSpace = body1coord.pointToWorldSpace(*this->offset1);
		//normals
		G3D::Vector3 body0Normal = Math::getWorldNormal(this->pairData.normalID0, body0coord);
		G3D::Vector3 body1Normal = Math::getWorldNormal(this->pairData.normalID1, body1coord);
		//calcs
		G3D::Vector3 bodyWorldSpaceDelta = body1worldSpace - body0worldSpace;
		float bodyNormalDot = body0Normal.dot(body1Normal);
		float body0Dot = bodyWorldSpaceDelta.dot(body0Normal);
		float body1Dot = -bodyWorldSpaceDelta.dot(body1Normal);
		float compareResult = 1.0f - bodyNormalDot * bodyNormalDot;
		if ( compareResult > 0.000001f )
		{
			float bodyDotCalc1 = (body0Dot + body1Dot * bodyNormalDot) * (1.0f / compareResult);
			float bodyDotCalc2 = (body1Dot + body0Dot * bodyNormalDot) * (1.0f / compareResult);
			const G3D::Vector3 body0NormalDotCalc = body0worldSpace + (body0Normal * bodyDotCalc1);
			const G3D::Vector3 body1NormalDotCalc = body1worldSpace + (body1Normal * bodyDotCalc2);
			_params.position = (body1NormalDotCalc + body0NormalDotCalc) * 0.5f;
			_params.normal = body0NormalDotCalc - body1NormalDotCalc;
			_params.length = -_params.normal.unitize();

		}
		else
		{
			_params.position = body0worldSpace;
			_params.normal = body0Normal;
			_params.length = 0.0f;
		}
	}
}
