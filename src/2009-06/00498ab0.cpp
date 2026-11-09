// from server: 100% by EspClaude
// roc 2009-06 00498ab0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace Ogre {
class Archive;
template<class T> class FactoryObj {
public:
    virtual ~FactoryObj() {}
    virtual const std::string& getType() const = 0;
};
class ArchiveFactory : public FactoryObj<Archive> {
public:
    virtual ~ArchiveFactory() {}
};
class ContentProvider;
std::string makeArchiveType(ContentProvider* provider);
class RbxArchiveFactory : public ArchiveFactory {
public:
    RbxArchiveFactory(ContentProvider* provider);
    const std::string& getType() const;
private:
    ContentProvider* provider;
    std::string mType;
};
RbxArchiveFactory::RbxArchiveFactory(ContentProvider* provider) : provider(provider)
{
    mType = makeArchiveType(this->provider);
}
}
