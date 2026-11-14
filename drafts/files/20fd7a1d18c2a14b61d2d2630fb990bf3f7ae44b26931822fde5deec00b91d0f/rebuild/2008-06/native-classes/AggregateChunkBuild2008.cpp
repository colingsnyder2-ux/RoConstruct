// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Native 00552270 / 00552300. Original assembly and donor RenderLib/Chunk.cpp.
// Inactive until dependency, ABI and runtime gates pass.
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/Material2008.h"
#include <GLG3D/RenderDevice.h>

namespace RBX { namespace RenderBase {
void AggregateChunk::makeMesh()
{
    mesh = Mesh::aggregate(components, _cframe, radius);
}

void AggregateChunk::renderShadows(G3D::RenderDevice* rd, const G3D::GLight& light,
    bool caps, float shadowVertexDistance)
{
    do {} while (0);
    if (light != shadowSource) {
        shadowSource = light;
        shadowIndexArray.clear();
        shadowIndexArray16.clear();
        if (material->veryTransparent()) return;

        static G3D::Array<G3D::Vector3> shadowVertex;
        shadowVertex.clear();
        shadowVertex.push_back(-light.position.xyz().direction() * shadowVertexDistance);
        do {} while (0);
        G3D::Vector3 worldLight = light.position.xyz().direction();
        mesh->computeDirectionalShadowVolume(cframe(), worldLight, shadowIndexArray, shadowVertex, caps);
        if (shadowVertex.size() < 65536) {
            int size = shadowIndexArray.size();
            shadowIndexArray16.resize(size);
            for (int i = 0; i < size; ++i)
                shadowIndexArray16[i] = shadowIndexArray[i];
            shadowIndexArray.clear();
        }
        G3D::ReferenceCountedPointer<G3D::VARArea> area = G3D::VARArea::create(
            shadowVertex.size() * 12, G3D::VARArea::WRITE_EVERY_FEW_FRAMES);
        shadowVAR = G3D::VAR(shadowVertex, area);
    }
    if (shadowIndexArray.size() > 0) {
        rd->beginIndexedPrimitives();
        rd->setVertexArray(shadowVAR);
        rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray);
        rd->endIndexedPrimitives();
    } else if (shadowIndexArray16.size() > 0) {
        rd->beginIndexedPrimitives();
        rd->setVertexArray(shadowVAR);
        rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray16);
        rd->endIndexedPrimitives();
    }
}
} }
