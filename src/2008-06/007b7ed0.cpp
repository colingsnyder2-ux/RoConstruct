// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { template<class T> class Array { T* data; int num; int numAllocated; public:
 void resize(int n, bool shrinkIfNecessary = true); T& next() { resize(num + 1, false); return data[num - 1]; } }; }
namespace RBX { namespace Render {
struct Level { int d[11]; };
class Material { char pad[0xc]; G3D::Array<Level> levels; public: Level& addLevel(); };
Level& Material::addLevel() { return levels.next(); } } }
