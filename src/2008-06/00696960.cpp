// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll roc_fork_ccf250026627378f.cpp

// Candidate translation unit (score above; library headers required).
// Roblox's exe-side Ogre::RbxSceneManager (RTTI name) over the inherited, imported
// SceneManager layout (target offsets equal SceneManager's, e.g. 0x4268). Client-import
// context: target calls Root::getSingleton/getMovableObjectFactory through rgmain.dll's IAT
// while calling getMovableObjectCollection directly. Bodies are verbatim Ogre 1.4.9; the
// target's OGRE_EXCEPT __LINE__ values (5314, 5431) sit four lines past 1.4.9's, and
// its data proves __FILE__ ".\RbxSceneManager.cpp" and "RbxSceneManager::" source names.
#undef OGRE_NONCLIENT_BUILD
#include "OgreStableHeaders.h"
#include "OgreSceneManager.h"
#include "OgreMovableObject.h"
#include "OgreException.h"
#include "OgreRoot.h"

namespace Ogre {

class RbxSceneManager : public SceneManager
{
protected:
	MovableObjectCollection* getMovableObjectCollection(const String& typeName);
	const MovableObjectCollection* getMovableObjectCollection(const String& typeName) const;
public:
	void setWorldGeometry(const String& filename);
	void setWorldGeometry(DataStreamPtr& stream, const String& typeName = StringUtil::BLANK);
	MovableObject* createMovableObject(const String& name,
		const String& typeName, const NameValuePairList* params = 0);
	void destroyMovableObject(const String& name, const String& typeName);
	void destroyMovableObject(MovableObject* m);
	void destroyAllMovableObjectsByType(const String& typeName);
	void destroyAllMovableObjects(void);
	MovableObject* getMovableObject(const String& name, const String& typeName) const;
	bool hasMovableObject(const String& name, const String& typeName) const;
	MovableObjectIterator getMovableObjectIterator(const String& typeName);
	void injectMovableObject(MovableObject* m);
};

#line 1301 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setWorldGeometry(const String& filename)
{
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}
//-----------------------------------------------------------------------
void RbxSceneManager::setWorldGeometry(DataStreamPtr& stream,
	const String& typeName)
{
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}

#line 5281 ".\\RbxSceneManager.cpp"
RbxSceneManager::MovableObjectCollection*
RbxSceneManager::getMovableObjectCollection(const String& typeName)
{
	// lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::iterator i =
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
	{
		// create
		MovableObjectCollection* newCollection = new MovableObjectCollection();
		mMovableObjectCollectionMap[typeName] = newCollection;
		return newCollection;
	}
	else
	{
		return i->second;
	}
}
//---------------------------------------------------------------------
const RbxSceneManager::MovableObjectCollection*
RbxSceneManager::getMovableObjectCollection(const String& typeName) const
{
	// lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::const_iterator i =
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
			"Object collection named '" + typeName + "' does not exist.",
			"RbxSceneManager::getMovableObjectCollection");
	}
	else
	{
		return i->second;
	}
}
//---------------------------------------------------------------------
MovableObject* RbxSceneManager::createMovableObject(const String& name,
	const String& typeName, const NameValuePairList* params)
{
	MovableObjectFactory* factory =
		Root::getSingleton().getMovableObjectFactory(typeName);
	// Check for duplicate names
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		if (objectMap->map.find(name) != objectMap->map.end())
		{
			OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM,
				"An object of type '" + typeName + "' with name '" + name
				+ "' already exists.",
				"RbxSceneManager::createMovableObject");
		}

		MovableObject* newObj = factory->createInstance(name, this, params);
		objectMap->map[name] = newObj;
		return newObj;
	}

}
//---------------------------------------------------------------------
void RbxSceneManager::destroyMovableObject(const String& name, const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	MovableObjectFactory* factory =
		Root::getSingleton().getMovableObjectFactory(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		MovableObjectMap::iterator mi = objectMap->map.find(name);
		if (mi != objectMap->map.end())
		{
			factory->destroyInstance(mi->second);
			objectMap->map.erase(mi);
		}
	}
}
//---------------------------------------------------------------------
void RbxSceneManager::destroyAllMovableObjectsByType(const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	MovableObjectFactory* factory =
		Root::getSingleton().getMovableObjectFactory(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::iterator i = objectMap->map.begin();
		for (; i != objectMap->map.end(); ++i)
		{
			// Only destroy our own
			if (i->second->_getManager() == this)
			{
				factory->destroyInstance(i->second);
			}
		}
		objectMap->map.clear();
	}
}
//---------------------------------------------------------------------
void RbxSceneManager::destroyAllMovableObjects(void)
{
	// Lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::iterator ci = mMovableObjectCollectionMap.begin();

	for(;ci != mMovableObjectCollectionMap.end(); ++ci)
	{
		MovableObjectCollection* coll = ci->second;

		// lock map mutex
		OGRE_LOCK_MUTEX(coll->mutex)

		if (Root::getSingleton().hasMovableObjectFactory(ci->first))
		{
			// Only destroy if we have a factory instance; otherwise must be injected
			MovableObjectFactory* factory =
				Root::getSingleton().getMovableObjectFactory(ci->first);
			MovableObjectMap::iterator i = coll->map.begin();
			for (; i != coll->map.end(); ++i)
			{
				if (i->second->_getManager() == this)
				{
					factory->destroyInstance(i->second);
				}
			}
		}
		coll->map.clear();
	}

}
//---------------------------------------------------------------------
MovableObject* RbxSceneManager::getMovableObject(const String& name, const String& typeName) const
{
	const MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::const_iterator mi = objectMap->map.find(name);
		if (mi == objectMap->map.end())
		{
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
				"Object named '" + name + "' does not exist.",
				"RbxSceneManager::getMovableObject");
		}
		return mi->second;
	}

}
//-----------------------------------------------------------------------
bool RbxSceneManager::hasMovableObject(const String& name, const String& typeName) const
{
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::const_iterator i =
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
		return false;

	{
		OGRE_LOCK_MUTEX(i->second->mutex)
		return (i->second->map.find(name) != i->second->map.end());
	}
}

//---------------------------------------------------------------------
RbxSceneManager::MovableObjectIterator
RbxSceneManager::getMovableObjectIterator(const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	// Iterator not thread safe! Warned in header.
	return MovableObjectIterator(objectMap->map.begin(), objectMap->map.end());
}
//---------------------------------------------------------------------
void RbxSceneManager::destroyMovableObject(MovableObject* m)
{
	destroyMovableObject(m->getName(), m->getMovableType());
}
//---------------------------------------------------------------------
void RbxSceneManager::injectMovableObject(MovableObject* m)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(m->getMovableType());
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		objectMap->map[m->getName()] = m;
	}
}

}
