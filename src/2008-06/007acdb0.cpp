// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { namespace RenderNew {
struct Level { double d[7]; };
class Material { char pad[0xc]; Level* levels; public: Level* getLevel(int i); };
Level* Material::getLevel(int i) { return &levels[i]; }
} }
