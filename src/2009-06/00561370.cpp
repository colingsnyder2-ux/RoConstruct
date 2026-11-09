// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view roc_espclaude_16ced9ced0f478d2.cpp

// Candidate translation unit (score above; library headers required).
#include "RenderLib/Mesh.h"
namespace RBX { namespace Render {
struct MeshX { static unsigned allocVertex(unsigned i); };
class Level2 {
public:
    virtual ~Level2();
    G3D::Array<unsigned> indexArray;
    G3D::RenderDevice::Primitive primitive;
    void appendQuad(unsigned a, unsigned b, unsigned c);
};
void Level2::appendQuad(unsigned a, unsigned b, unsigned c)
{
    switch (primitive)
    {
    case G3D::RenderDevice::TRIANGLES:
        indexArray.append(MeshX::allocVertex(a), MeshX::allocVertex(b), MeshX::allocVertex(c));
        break;
    case G3D::RenderDevice::QUADS:
        indexArray.append(MeshX::allocVertex(a), MeshX::allocVertex(a), MeshX::allocVertex(b), MeshX::allocVertex(c));
        break;
    }
}
}}
