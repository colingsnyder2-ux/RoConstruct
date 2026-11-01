// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <string>
namespace Ogre {
class Archive;
template<class T> class FactoryObj {
public:
    virtual ~FactoryObj() {}
    virtual const std::string& getType() const = 0;
    virtual T* createInstance(const std::string& name) = 0;
    virtual void destroyInstance(T*) = 0;
};
extern template class __declspec(dllimport) FactoryObj<Archive>;
class __declspec(novtable) ArchiveFactory : public FactoryObj<Archive> {
public:
    virtual ~ArchiveFactory() {}
};
class RbxArchiveFactory : public ArchiveFactory {
public:
    int flag;
    std::string type;
    virtual ~RbxArchiveFactory();
    const std::string& getType() const;
    Archive* createInstance(const std::string& name);
    void destroyInstance(Archive*);
};
extern void* g_rbxArchive;
RbxArchiveFactory::~RbxArchiveFactory()
{
    if (flag == 0)
        g_rbxArchive = 0;
}
}
