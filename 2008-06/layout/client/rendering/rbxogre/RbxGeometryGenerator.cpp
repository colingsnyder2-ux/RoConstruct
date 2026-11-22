#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreSubMesh.h>
#include <OgreHardwareBufferManager.h>

namespace Ogre {
// INFERRED: helper name and pointer types from original 0067c020 and indexed geometry donor.
SubMesh* GeometryBuilder::createIndices(const MeshPtr& mesh, const unsigned short* indices16, const unsigned* indices32, unsigned triangles) {
 boost::call_once(initializeGeometryContext, geometryOnce);
 boost::recursive_mutex::scoped_lock lock(geometryContext->mutex);
 SubMesh* submesh = mesh->createSubMesh();
 size_t count = triangles * 3;
 HardwareIndexBufferSharedPtr buffer = HardwareBufferManager::getSingleton().createIndexBuffer(indices16 ? HardwareIndexBuffer::IT_16BIT : HardwareIndexBuffer::IT_32BIT, count, HardwareBuffer::HBU_STATIC_WRITE_ONLY);
 buffer->writeData(0, buffer->getSizeInBytes(), indices16 ? static_cast<const void*>(indices16) : static_cast<const void*>(indices32), true);
 submesh->useSharedVertices = true;
 submesh->indexData->indexBuffer = buffer;
 submesh->indexData->indexCount = count;
 submesh->indexData->indexStart = 0;
 return submesh;
}
}

#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryBuilder2008.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
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

#undef OGRE_NONCLIENT_BUILD
#include <OgreVertexIndexData.h>
#include <OgreAxisAlignedBox.h>
#include <cmath>

namespace Ogre {
// INFERRED method name; 00679e70 replaces Mesh::sharedVertexData (+0x1e4),
void GeometryBuilder::update(MeshPtr& mesh, const float* vertices, unsigned vertexCount,
    const float* normals, const float* colours, const float* texCoords,
    const Vector3* minimum, const Vector3* maximum)
{
    if (mesh->sharedVertexData) {
        delete mesh->sharedVertexData;
        mesh->sharedVertexData = 0;
    }
    mesh->sharedVertexData = createVertexData(vertices, vertexCount, normals, colours, texCoords);
    Vector3 difference;
    if (minimum && maximum) {
        mesh->_setBounds(AxisAlignedBox(minimum->x, minimum->y, minimum->z,
            maximum->x, maximum->y, maximum->z), true);
        difference.z = maximum->z - minimum->z;
        difference.y = maximum->y - minimum->y;
        difference.x = maximum->x - minimum->x;
        mesh->_setBoundingSphereRadius(static_cast<float>(sqrt(static_cast<double>(difference.squaredLength()))) * 0.5f);
    } else {
        Vector3 low(1.0e9f, 1.0e9f, 1.0e9f), high(-1.0e9f, -1.0e9f, -1.0e9f);
        for (unsigned i = 0; i < 3 * vertexCount; i += 3) {
            if (low.x > vertices[i]) low.x = vertices[i];
            if (low.y > vertices[i + 1]) low.y = vertices[i + 1];
            if (low.z > vertices[i + 2]) low.z = vertices[i + 2];
            if (high.x < vertices[i]) high.x = vertices[i];
            if (high.y < vertices[i + 1]) high.y = vertices[i + 1];
            if (high.z < vertices[i + 2]) high.z = vertices[i + 2];
        }
        mesh->_setBounds(AxisAlignedBox(low.x, low.y, low.z, high.x, high.y, high.z), true);
        difference.z = high.z - low.z;
        difference.y = high.y - low.y;
        difference.x = high.x - low.x;
        mesh->_setBoundingSphereRadius(static_cast<float>(sqrt(static_cast<double>(difference.squaredLength()))) * 0.5f);
    }
}
}

#undef OGRE_NONCLIENT_BUILD
#include <OgrePrerequisites.h>
#include <OgreVector3.h>

// INFERRED: 0067c130 inlines box construction but imports Vector3::length (unlike 0067bcc0).
#pragma push_macro("inline")
#define inline __forceinline
#pragma pop_macro("inline")
#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace Ogre {
// INFERRED: method/signature from 0067c130 analog; fields from original allocation and stores.
RbxSubMesh* GeometryBuilder::createIndexed(const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const unsigned short*indices16,const unsigned*indices32,unsigned triangleCount,Vector3*minimum,Vector3*maximum){
 boost::call_once(initializeGeometryContext,geometryOnce);
 GeometryContext*context=geometryContext;
 boost::recursive_mutex::scoped_lock lock(context->mutex);
 RbxSubMesh*result=new RbxSubMesh;
 result->parent=0;
 result->vertexData=createVertexData(vertices,vertexCount,normals,colours,texCoords);
 result->useSharedVertices=false;
 unsigned indexCount=3*triangleCount;
 HardwareIndexBufferSharedPtr buffer=HardwareBufferManager::getSingleton().createIndexBuffer(indices16?HardwareIndexBuffer::IT_16BIT:HardwareIndexBuffer::IT_32BIT,indexCount,HardwareBuffer::HBU_STATIC_WRITE_ONLY,false);
 buffer->writeData(0,buffer->getSizeInBytes(),indices16?static_cast<const void*>(indices16):indices32,true);
 result->indexData->indexBuffer=buffer;
 result->indexData->indexCount=indexCount;
 result->indexData->indexStart=0;
 {
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  *minimum=low;*maximum=high;
  AxisAlignedBox bounds(low.x,low.y,low.z,high.x,high.y,high.z);
  result->bounds=bounds;
  result->radius=bounds.getHalfSize().length();
 }
 std::string name="sms"+StringConverter::toString(context->counter++);
 context->names[result]=name;
 LogManager::getSingleton().logMessage("RBX cr "+name,LML_NORMAL,false);
 return result;
}
}

#undef OGRE_NONCLIENT_BUILD
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
