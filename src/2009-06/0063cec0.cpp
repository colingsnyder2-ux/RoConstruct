// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Instance;
class ServiceProvider;
ServiceProvider* findServiceProvider(Instance* instance);
bool isLocal(Instance* instance, bool flag);
class Accoutrement {
public:
    void update();
    void onEvent(int unused);
};
void Accoutrement::onEvent(int)
{
    Instance* self = reinterpret_cast<Instance*>(this);
    if (findServiceProvider(self) && isLocal(self, true))
        update();
}
}
