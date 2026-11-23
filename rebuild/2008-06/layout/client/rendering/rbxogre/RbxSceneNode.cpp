// =============================================================================
// RbxSceneNode.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/rbxogre/RbxSceneNode.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "OgreRbxNode/RbxSceneNode2008.h"
#include <OgreCamera.h>
#include <OgreRenderQueue.h>
#include <OgreSceneManager.h>
#include <stdexcept>

namespace Ogre
{
	RbxSceneNode::SphereMap* RbxSceneNode::spheres;

	void RbxSceneNode::_update(bool updateChildren, bool parentHasChanged)
	{
		mDerivedOrientation = mOrientation;
		mDerivedPosition = mPosition;
		mDerivedScale = mScale;
		mWorldAABB.setExtents(-10000, -10000, -10000, 10000, 10000, 10000);
	}

	void RbxSceneNode::_updateBounds(void)
	{
		mWorldAABB.setNull();
		ObjectMap::iterator i;
		for (i = mObjectsByName.begin(); i != mObjectsByName.end(); ++i)
			mWorldAABB.merge(i->second->getWorldBoundingBox(true));
		ChildNodeMap::iterator child;
		for (child = mChildren.begin(); child != mChildren.end(); ++child)
			mWorldAABB.merge(static_cast<SceneNode*>(child->second)->_getWorldAABB());
	}

	void RbxSceneNode::_findVisibleObjects(Camera* cam, RenderQueue* queue, VisibleObjectsBoundsInfo* visibleBounds,
	                                       bool includeChildren, bool displayNodes, bool onlyShadowCasters)
	{
		ObjectMap::iterator iobj;
		ObjectMap::iterator iobjend = mObjectsByName.end();
		for (iobj = mObjectsByName.begin(); iobj != iobjend; ++iobj)
		{
			iobj->second->_notifyCurrentCamera(cam);
			if (iobj->second->isVisible() && (!onlyShadowCasters || iobj->second->getCastShadows()))
			{
				iobj->second->_updateRenderQueue(queue);
				if (visibleBounds)
				{
					visibleBounds->merge(iobj->second->getWorldBoundingBox(true),
						iobj->second->getWorldBoundingSphere(true), cam);
				}
			}
		}

		if (includeChildren)
		{
			ChildNodeMap::iterator child, childend;
			childend = mChildren.end();
			for (child = mChildren.begin(); child != childend; ++child)
			{
				SceneNode* sceneChild = static_cast<SceneNode*>(child->second);
				sceneChild->_findVisibleObjects(cam, queue, visibleBounds, includeChildren, displayNodes,
					onlyShadowCasters);
			}
		}

		if (displayNodes)
			queue->addRenderable(this);

		if (mShowBoundingBox || (mCreator && mCreator->getShowBoundingBoxes()))
			_addBoundingBoxToQueue(queue);
	}

	void RbxSceneNode::setTransform(unsigned int key, const Matrix4& transform)
	{
		TransformMap::iterator i = transforms.find(key);
		if (i == transforms.end())
		{
			std::pair<TransformMap::iterator, bool> result;
			result = transforms.insert(std::make_pair(key, new Matrix4));
			i = result.first;
		}
		*i->second = transform;
	}

	const Matrix4& RbxSceneNode::getTransform(unsigned long key) const
	{
		if (key)
		{
			TransformMap::const_iterator i = transforms.find(key);
			if (i == transforms.end())
				throw std::runtime_error("Transform map error");
			return *i->second;
		}
		if (mCachedTransformOutOfDate)
		{
			mCachedTransform.makeTransform(_getDerivedPosition(), _getDerivedScale(), _getDerivedOrientation());
			mCachedTransformOutOfDate = false;
		}
		return mCachedTransform;
	}

	bool RbxSceneNode::hasTransform(unsigned long key) const
	{
		TransformMap::const_iterator i = transforms.find(key);
		return i != transforms.end();
	}

	void RbxSceneNode::initializeSpheres()
	{
		if (!spheres)
			spheres = new SphereMap;
	}

	void RbxSceneNode::setSphere(SubMesh* key, const Sphere& sphere)
	{
		initializeSpheres();
		SphereMap::iterator i = spheres->find(key);
		if (i == spheres->end())
		{
			std::pair<SphereMap::iterator, bool> result;
			result = spheres->insert(std::make_pair(key, Sphere()));
			i = result.first;
		}
		i->second = sphere;
	}

	const Sphere& RbxSceneNode::getSphere(const void* key) const
	{
		SphereMap::const_iterator i = spheres->find(key);
		if (i == spheres->end())
			throw std::runtime_error("bsphere map error");
		return i->second;
	}

	bool RbxSceneNode::hasSphere(const void* key) const
	{
		SphereMap::const_iterator i = spheres->find(key);
		return i != spheres->end();
	}

	RbxSceneNode::~RbxSceneNode()
	{
		for (TransformMap::iterator i = transforms.begin(); i != transforms.end(); ++i)
			delete i->second;
		transforms.clear();
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<void const * const,Ogre::Sphere> > >;
template class std::_Tmap_traits<unsigned long,Ogre::Matrix4 *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> >,0>;
template class std::_Tmap_traits<void const *,Ogre::Sphere,std::less<void const *>,std::allocator<std::pair<void const * const,Ogre::Sphere> >,0>;
template class std::_Tree<std::_Tmap_traits<unsigned long,Ogre::Matrix4 *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> >,0> >;
template class std::_Tree<std::_Tmap_traits<void const *,Ogre::Sphere,std::less<void const *>,std::allocator<std::pair<void const * const,Ogre::Sphere> >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<unsigned long,Ogre::Matrix4 *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<void const *,Ogre::Sphere,std::less<void const *>,std::allocator<std::pair<void const * const,Ogre::Sphere> >,0> >::_Node *>;
template class std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> >;
template class std::allocator<std::pair<void const * const,Ogre::Sphere> >;
template class std::list<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *>,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> > >;
template class std::list<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Node *>,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Node *> > >;
template class std::map<unsigned long,Ogre::Matrix4 *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,Ogre::Matrix4 *> > >;
template class stdext::_Hash<stdext::_Hmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MovableObject *,stdext::hash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> >,0> >;
template class stdext::_Hash<stdext::_Hmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::Node *,stdext::hash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Node *> >,0> >;

#undef OGRE_NONCLIENT_BUILD
namespace Ogre
{
// INFERRED: name and pointer type; original 00682150 erases from the sphere map.
bool eraseSphere(const void* key) {
 if (!RbxSceneNode::spheres) return false;
 RbxSceneNode::SphereMap::iterator i = RbxSceneNode::spheres->find(key);
 if (i != RbxSceneNode::spheres->end()) {
  RbxSceneNode::spheres->erase(i);
  return true;
 }
 return false;
}
}
