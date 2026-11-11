// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreGeometryBuilder2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src dcb5e242 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryBuilder2008.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreHardwareBufferManager.h>
#include <vector>
namespace RBX {
// INFERRED: source analog 00679ae0; actual receiver/signature identity still requires proof.
Ogre::VertexData* OgreUtil::createVertexData(const Ogre::Vector3* positions, unsigned int count, const Ogre::Vector3* normals, const G3D::Color4* colors, const float* texCoords)
{
    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::VertexData* vd = new Ogre::VertexData();
    vd->vertexCount = count;
    Ogre::VertexDeclaration* decl = vd->vertexDeclaration;
    unsigned short source = 0;
    decl->addElement(source, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    unsigned int vsize = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    Ogre::HardwareVertexBufferSharedPtr vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(vsize, vd->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    vbuf->writeData(0, vbuf->getSizeInBytes(), positions, true);
    Ogre::VertexBufferBinding* bind = vd->vertexBufferBinding;
    bind->setBinding(source, vbuf);
    ++source;
    if (colors) {
        std::vector<Ogre::uint32> colourData;
        colourData.resize(count);
        for (unsigned int i = 0; i < count; ++i) {
            float ca = colors[i].r;
            float cb = colors[i].r;
            float cg = colors[i].r;
            float cr = colors[i].r;
            Ogre::ColourValue c(cr, cg, cb, ca);
            rs->convertColourValue(c, &colourData[i]);
        }
        decl->addElement(source, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
        unsigned int csize = Ogre::VertexElement::getTypeSize(Ogre::VET_COLOUR);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(csize, vd->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), &colourData[0], true);
        bind->setBinding(source, vbuf);
        ++source;
    }
    if (normals) {
        decl->addElement(source, 0, Ogre::VET_FLOAT3, Ogre::VES_NORMAL);
        unsigned int size = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(size, vd->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), normals, true);
        bind->setBinding(source, vbuf);
        ++source;
    }
    if (texCoords) {
        decl->addElement(source, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);
        unsigned int size = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT2);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(size, vd->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), texCoords, true);
        bind->setBinding(source, vbuf);
    }
    return vd;
}
}
