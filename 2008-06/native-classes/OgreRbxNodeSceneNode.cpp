// Ogre::RbxSceneNode method bodies (inactive native recovery, June 2008 client); see OgreRbxNode/RbxSceneNode2008.h.
// Bodies 00681190..006823ff. Built with the Ogre 1.4.5 client headers; record_native_ogre_rbx_node.py verifies them.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreRbxNodeSceneNode | 2008-06 | 36 byte-exact, inactive (not link-selected)
// 36/38 mapped addresses byte-exact | named 13 | 2 unproved | no mapped strings | by auto (+4) (mixed 3)
// <<< native-status | src 6c2c1a1c | roc native-status --write
#include "OgreRbxNode/RbxSceneNode2008.h"
#include <OgreCamera.h>
#include <OgreRenderQueue.h>
#include <OgreSceneManager.h>
#include <stdexcept>

namespace Ogre
{
	RbxSceneNode::SphereMap* RbxSceneNode::spheres;

	// 00681190: the node keeps its local transform as the derived one and a fixed +/-10000 world box.
	void RbxSceneNode::_update(bool updateChildren, bool parentHasChanged)
	{
		mDerivedOrientation = mOrientation;
		mDerivedPosition = mPosition;
		mDerivedScale = mScale;
		mWorldAABB.setExtents(-10000, -10000, -10000, 10000, 10000, 10000);
	}

	// 006817e0
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

	// 00681560: SceneNode::_findVisibleObjects without the camera visibility test.
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

	// 00681f90
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

	// 006818e0: key 0 is the node's own full transform.
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

	// 00681a00
	bool RbxSceneNode::hasTransform(unsigned long key) const
	{
		TransformMap::const_iterator i = transforms.find(key);
		return i != transforms.end();
	}

	// 006822e0
	void RbxSceneNode::initializeSpheres()
	{
		if (!spheres)
			spheres = new SphereMap;
	}

	// 00682350
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

	// 00682040
	const Sphere& RbxSceneNode::getSphere(const void* key) const
	{
		SphereMap::const_iterator i = spheres->find(key);
		if (i == spheres->end())
			throw std::runtime_error("bsphere map error");
		return i->second;
	}

	// 00682100
	bool RbxSceneNode::hasSphere(const void* key) const
	{
		SphereMap::const_iterator i = spheres->find(key);
		return i != spheres->end();
	}

	// 006821c0
	RbxSceneNode::~RbxSceneNode()
	{
		for (TransformMap::iterator i = transforms.begin(); i != transforms.end(); ++i)
			delete i->second;
		transforms.clear();
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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
