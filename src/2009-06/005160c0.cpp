// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class AggregatingSceneManagerFactory {
public:
    AggregatingSceneManagerFactory();
    static void initialise();
private:
    char pad[0x50];
    static AggregatingSceneManagerFactory* singleton;
};
void AggregatingSceneManagerFactory::initialise()
{
    if (!singleton)
        singleton = new AggregatingSceneManagerFactory();
}
}
