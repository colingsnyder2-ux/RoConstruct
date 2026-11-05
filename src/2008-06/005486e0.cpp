// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 005486e0: releases a level's submesh (registry/lock as in
// 00548a90, scene removal 00682150) and its slot in the shared mesh 009738b8,
// logging both removals through Ogre::LogManager.
#include <string>
#include <map>

namespace Ogre {
enum LogMessageLevel { LML_TRIVIAL = 1, LML_NORMAL = 2, LML_CRITICAL = 3 };
class LogManager {
public:
    __declspec(dllimport) static LogManager& getSingleton();
    __declspec(dllimport) void logMessage(const std::string& message, LogMessageLevel lml, bool maskDebug);
};
class StringConverter {
public:
    __declspec(dllimport) static std::string toString(int val, unsigned short width, char fill, int flags);
};
class SubMesh;
class Mesh {
public:
    __declspec(dllimport) unsigned short getNumSubMeshes() const;
    __declspec(dllimport) SubMesh* getSubMesh(unsigned short index) const;
};
template<class T>
class SharedPtr {
public:
    __declspec(dllimport) T* operator->() const;
    T* pointer;
};
}

class LevelMesh {
public:
    ~LevelMesh();
};

class SlotData {
public:
    ~SlotData();
};

struct SubMeshView {
    char header[0x0c];
    SlotData* data;
};

class Mutex { };
class Lock {
public:
    Lock(Mutex& mutex, bool initialLock);
    ~Lock();
    void* section;
};

class Registry {
public:
    typedef std::map<LevelMesh*, std::string> Map;
    static Registry* instance();
    const std::string& name(LevelMesh* const& mesh);
    Map::iterator find(LevelMesh* const& mesh);
    Map::iterator erase(Map::const_iterator where);
    int header[0x24 / 4];
    Mutex mutex;
};

void removeFromScene(const void* mesh);
extern Ogre::SharedPtr<Ogre::Mesh> sharedMesh;

class Level {
public:
    void release();
    int header[0x1c / 4];
    bool dirty;
    int index;
    LevelMesh* subMesh;
};

void Level::release()
{
    int removed;
    dirty = true;
    if (subMesh) {
        delete subMesh;
        removeFromScene(subMesh);
        Registry* registry = Registry::instance();
        Lock lock(registry->mutex, true);
        do {} while (0);
        Ogre::LogManager::getSingleton().logMessage("RBX rm " + registry->name(subMesh), Ogre::LML_NORMAL, false);
        registry->erase(registry->find(subMesh));
        subMesh = 0;
    }
    if (index > 0) {
        do {} while (0);
        int count = sharedMesh->getNumSubMeshes();
        do {} while (0);
        SlotData*& data = reinterpret_cast<SubMeshView*>(sharedMesh->getSubMesh(index))->data;
        delete data;
        data = 0;
        Ogre::LogManager::getSingleton().logMessage("RBX rm sm" + Ogre::StringConverter::toString(index, 0, ' ', 0), Ogre::LML_NORMAL, false);
        removeFromScene(sharedMesh->getSubMesh(index));
    }
}
