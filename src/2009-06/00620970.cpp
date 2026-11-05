// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { template<class T> class weak_ptr { public: T* px; void* pn; }; }
namespace G3D { class Vector3 { public: float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} }; }
namespace RBX {
class PartInstance;
class RootInstance;
class MegaDragger {
public:
    MegaDragger(PartInstance* p, std::vector<boost::weak_ptr<PartInstance> >& parts, RootInstance* root, int x = 0);
    ~MegaDragger();
    char d[0x30];
};
class RootInstance {
public:
    enum MoveType { A, B };
    void moveSafe(MegaDragger& d, G3D::Vector3 move, MoveType moveType);
    void moveSafe(std::vector<boost::weak_ptr<PartInstance> >& partArray, G3D::Vector3 move, MoveType moveType);
};
void RootInstance::moveSafe(std::vector<boost::weak_ptr<PartInstance> >& partArray, G3D::Vector3 move, MoveType moveType)
{
    MegaDragger megaDragger(0, partArray, this);
    moveSafe(megaDragger, move, moveType);
}
}
