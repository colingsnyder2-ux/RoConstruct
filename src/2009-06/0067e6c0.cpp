// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Engine { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void step(int); };
class World { char pad[0xb8]; Engine* engine; public: void update(int a); };
void World::update(int a) { engine->step(a); }
}
