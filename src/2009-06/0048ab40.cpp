// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace Ogre {
class Resource;
class __declspec(dllimport) ManualResourceLoader {
public:
    ManualResourceLoader() {}
    virtual ~ManualResourceLoader() {}
    virtual void prepareResource(Resource* r) {}
    virtual void loadResource(Resource* r) = 0;
};
template<class T> struct ChainLink {
    T* owner;
    ~ChainLink() { owner = static_cast<T*>(this); }
};
class RbxManualResourceLoaderChain : public ManualResourceLoader, public ChainLink<RbxManualResourceLoaderChain> {
public:
    virtual ~RbxManualResourceLoaderChain() {}
    virtual void loadResource(Resource* r);
};
RbxManualResourceLoaderChain* make() { return new RbxManualResourceLoaderChain; }
}
