// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Destructor analog for 00548a90 (the class built by 00548570): deletes the
// submesh at +0x80 (scalar deleting dtor 0054ac70), then under the registry lock
// (00407130/00407160) logs and erases it from the registry (00054ab40 instance,
// name 0054b3a0, find 0054bd00, erase 0054b520).
#include <string>
#include <map>

namespace Ogre {
enum LogMessageLevel { LML_TRIVIAL = 1, LML_NORMAL = 2, LML_CRITICAL = 3 };
class LogManager {
public:
    __declspec(dllimport) static LogManager& getSingleton();
    __declspec(dllimport) void logMessage(const std::string& message, LogMessageLevel lml, bool maskDebug);
};
}

class SubMesh {
public:
    ~SubMesh();
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
    typedef std::map<SubMesh*, std::string> Map;
    static Registry* instance();
    const std::string& name(SubMesh* const& mesh);
    Map::iterator find(SubMesh* const& mesh);
    Map::iterator erase(Map::const_iterator where);
    char header[0x24];
    Mutex mutex;
};

class Base {
public:
    Base();
    virtual ~Base();
    char data[8];
};

class MemberA { public: MemberA(); ~MemberA(); char data[0x0c]; };
class MemberB { public: MemberB(); ~MemberB(); char data[0x34]; };
class MemberC { public: MemberC(); ~MemberC(); char data[0x18]; };
class MemberD { public: MemberD(); ~MemberD(); char data[0x18]; };

class Object : public Base {
public:
    virtual ~Object();
    MemberA a;
    MemberB b;
    float scale;
    MemberC c;
    MemberD d;
    SubMesh* subMesh;
    int second;
};

Object::~Object()
{
    int removed;
    if (subMesh) {
        delete subMesh;
        Registry* registry = Registry::instance();
        Lock lock(registry->mutex, true);
        do {} while (0);
        Ogre::LogManager::getSingleton().logMessage("RBX rm " + registry->name(subMesh) + " shd", Ogre::LML_NORMAL, false);
        registry->erase(registry->find(subMesh));
    }
}
