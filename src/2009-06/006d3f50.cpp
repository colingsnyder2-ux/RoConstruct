// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <functional>
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
struct myLess
{
	bool operator()(const G3D::Vector3& a, const G3D::Vector3& b) const;
};
class BlockTemplate;
typedef std::map<G3D::Vector3, BlockTemplate*, myLess> BlockTemplates;
struct Holder { BlockTemplates m; int n; Holder() : m(myLess()), n(0) {} };
Holder* blockTemplates;
void initBlockTemplates()
{
	static Holder h;
	blockTemplates = &h;
}
}
