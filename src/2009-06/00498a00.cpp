// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace Ogre {
typedef std::string String;
class __declspec(dllimport) Archive {
public:
    Archive(const String& name, const String& archType);
    virtual ~Archive();
    char pad[0x3c - 4];
};
class Thing;
String makeType(Thing* t);
class RbxArchive : public Archive {
public:
    RbxArchive(const String& name, const String& archType, Thing* t) : Archive(name, archType), mThing(t) {}
    virtual ~RbxArchive();
    Thing* mThing;
};
class RbxArchiveFactory {
public:
    virtual ~RbxArchiveFactory();
    Thing* mThing;
    Archive* createInstance(const String& name);
};
Archive* RbxArchiveFactory::createInstance(const String& name)
{
    return new RbxArchive(name, makeType(mThing), mThing);
}
}
