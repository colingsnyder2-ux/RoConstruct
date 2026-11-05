// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_5a636a8fbb4dd2a2.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
namespace Ogre {
class RbxSceneManager : public SceneManager {
public:
    Entity* createEntity(const String& entityName, PrefabType ptype);
    Entity* createEntity(const String& entityName, const String& meshName);
};
#line 421 ".\\RbxSceneManager.cpp"
Entity* RbxSceneManager::createEntity(const String& entityName, PrefabType ptype)
{
    switch (ptype)
    {
    case PT_PLANE:
        return createEntity(entityName, "Prefab_Plane");
	case PT_CUBE:
		return createEntity(entityName, "Prefab_Cube");
	case PT_SPHERE:
		return createEntity(entityName, "Prefab_Sphere");

        break;
    }

    OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
        "Unknown prefab type for entity " + entityName,
        "RbxSceneManager::createEntity");
}
}
