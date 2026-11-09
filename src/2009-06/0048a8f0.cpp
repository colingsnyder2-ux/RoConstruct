// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace Ogre {
class Resource;
class __declspec(dllimport) ManualResourceLoader { public: ManualResourceLoader() {} virtual ~ManualResourceLoader() {} virtual void loadResource(Resource*) = 0; };
}
struct B2 { void* p; };
class Loader : public Ogre::ManualResourceLoader, public B2 { public: ~Loader(); void loadResource(Ogre::Resource*); };
Loader::~Loader() { B2* b = this; b->p = static_cast<Loader*>(b); }
