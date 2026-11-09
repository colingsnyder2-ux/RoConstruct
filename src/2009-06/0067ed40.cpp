// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct World;
struct Mechanism {
    char pad0[0xc0];
    World* world;
    int& index();
};
struct MechList {
    Mechanism** data;
    int size;
    int capacity;
    void append(Mechanism* const& m);
};
struct CleanStage { void f(Mechanism* m); };
struct FinalStage { void f(Mechanism* m); };
struct World {
    char pad0[0x38];
    MechList mechanisms;
    char pad1[0xb0 - 0x44];
    FinalStage* finalStage;
    char pad2[4];
    CleanStage* cleanStage;
    void insertMechanism(Mechanism* m);
};
void World::insertMechanism(Mechanism* m)
{
    MechList* list = &mechanisms;
    Mechanism* entry = m;
    int n = list->size;
    m->index() = n;
    list->append(entry);
    m->world = this;
    cleanStage->f(m);
    finalStage->f(m);
}
