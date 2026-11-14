// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor VAR methods; 2008 GL error drain and dirty flag from original assembly.
#include "ViewNew/RenderBaseMesh.h"
#include <GLG3D/VAR.h>
namespace RBX { namespace RenderBase {
extern bool g3dVarDirty;
G3D::VAR Mesh::vertexVAR;
G3D::VAR Mesh::normalVAR;
G3D::VAR Mesh::texCoordVAR;
G3D::VAR Mesh::tangentVAR;
void Mesh::makeVAR()
{
    if (!g3dVarDirty) return;
    {
        GLenum e = glGetError();
        while (e != GL_NO_ERROR) e = glGetError();
        G3D::VARAreaRef area = G3D::VARArea::create(visibleGeometry.vertexArray.size() * 44 + 1024, G3D::VARArea::WRITE_ONCE);
        vertexVAR = G3D::VAR(visibleGeometry.vertexArray, area);
        normalVAR = G3D::VAR(visibleGeometry.normalArray, area);
        texCoordVAR = G3D::VAR(texCoordArray, area);
        tangentVAR = G3D::VAR(tangentArray, area);
        g3dVarDirty = false;
    }
}
void Mesh::beginRender(G3D::RenderDevice* rd, bool useTexCoords, bool useTangent)
{
    makeVAR();
    if (g3dVarDirty) return;
    debugAssert(rd); // inferred disabled invariant
    rd->beginIndexedPrimitives();
    if (vertexVAR.valid()) rd->setVertexArray(vertexVAR);
    if (normalVAR.valid()) rd->setNormalArray(normalVAR);
    if (useTexCoords && texCoordVAR.valid()) rd->setTexCoordArray(0, texCoordVAR);
    if (useTangent && tangentVAR.valid()) rd->setTexCoordArray(2, tangentVAR);
}
void Mesh::setShadowVertex(const G3D::Vector3& v)
{
    debugAssert(visibleGeometry.vertexArray.size() > 0); // inferred disabled invariant
    visibleGeometry.vertexArray[0] = v;
    if (g3dVarDirty) makeVAR();
    else vertexVAR.set(0, v);
}
} }

