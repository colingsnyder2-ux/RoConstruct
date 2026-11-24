// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <map>
#include <string>

// INFERRED: no Ogre headers are guaranteed on the include path, so this is a minimal local
// layout. The map sits at +0x4268 and MovableObjectCollection is 0x20 bytes (the new(0x20) in
// the disassembly). Vendor body is Ogre 1.4.9 SceneManager::getMovableObjectCollection.
namespace Ogre {

class MovableObject;

class SceneManager
{
public:
	struct MovableObjectCollection
	{
		std::map<std::string, MovableObject*> map;
		// INFERRED: remaining bytes are the auto-mutex, not touched here.
		char mutexPad[0x18];
	};

	typedef std::map<std::string, MovableObjectCollection*> MovableObjectCollectionMap;

protected:
	char pad[0x4268];
	MovableObjectCollectionMap mMovableObjectCollectionMap; // +0x4268

	MovableObjectCollection* getMovableObjectCollection(const std::string& typeName);
};

SceneManager::MovableObjectCollection*
SceneManager::getMovableObjectCollection(const std::string& typeName)
{
	MovableObjectCollectionMap::iterator i = mMovableObjectCollectionMap.find(typeName);
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

}
