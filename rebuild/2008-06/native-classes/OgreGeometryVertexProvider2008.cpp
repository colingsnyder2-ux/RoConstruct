// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreHardwareBufferManager.h>
#include <vector>
namespace Ogre {
// Inferred receiver and signature; adapted from existing vertex-data implementation.
Ogre::VertexData* GeometryBuilder::createVertexData(const float* positions, unsigned int count, const float* normals, const float* colors, const float* texCoords)
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
            float ca = colors[i * 4];
            float cb = colors[i * 4];
            float cg = colors[i * 4];
            float cr = colors[i * 4];
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
