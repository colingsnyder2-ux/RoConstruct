// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbx_scenemgr_create_movable_e87cf5c167b0c1ab.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {

class RbxSceneManager : public SceneManager {
public:
    MovableObject* createMovableObject(const String& name,
        const String& typeName, const NameValuePairList* params = 0);
    MovableObjectCollection* getMovableObjectCollection(const String& typeName);
};

#line 5322 ".\\RbxSceneManager.cpp"
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

}


