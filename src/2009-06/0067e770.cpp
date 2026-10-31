// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Mechanism { public: virtual ~Mechanism(); };
class Engine { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void removeMechanism(Mechanism* m); };
class World {
    char pad0[0x78];
    int numMechanisms;
    char pad1[0xb8 - 0x7c];
    Engine* engine;
public:
    void removeMechanism(Mechanism* m);
};
void World::removeMechanism(Mechanism* m)
{
    engine->removeMechanism(m);
    delete m;
    numMechanisms--;
}
}
