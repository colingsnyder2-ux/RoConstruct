#undef OGRE_NONCLIENT_BUILD
#include "PlayerMeshBackend.h"
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <stdexcept>

typedef char SubMeshSize[sizeof(Ogre::SubMesh)==0xc4?1:-1];
typedef char RbxSubMeshSize[sizeof(Ogre::RbxSubMesh)==0xf0?1:-1];
typedef char RbxSubMeshBounds[offsetof(Ogre::RbxSubMesh,bounds)==0xcc?1:-1];
typedef char RbxSubMeshRadius[offsetof(Ogre::RbxSubMesh,radius)==0xec?1:-1];
typedef char VertexDataSize[sizeof(Ogre::VertexData)==0x38?1:-1];
typedef char IndexDataSize[sizeof(Ogre::IndexData)==0x14?1:-1];

Ogre::RbxSubMesh::RbxSubMesh() : prepared(false), edges(0) {} // 00678470
Ogre::RbxSubMesh::~RbxSubMesh() { delete edges; } // 006824e0

namespace PlayerSphereCache {
namespace {
typedef std::map<Key,Ogre::Sphere> SphereMap;
typedef char MapSize[sizeof(SphereMap)==0x20?1:-1];
typedef char PairSize[sizeof(SphereMap::value_type)==0x14?1:-1];
typedef char SphereSize[sizeof(Ogre::Sphere)==0x10?1:-1];
SphereMap* spheres; // 006822e0 allocates once; native has no container teardown here.
}
void set(Key key,const Ogre::Sphere& sphere){ // 00682350, map operations from target.
    if(!spheres)spheres=new SphereMap;
    SphereMap::iterator found=spheres->find(key);
    if(found==spheres->end())found=spheres->insert(SphereMap::value_type(key,Ogre::Sphere())).first;
    found->second=sphere;
}
const Ogre::Sphere& get(Key key){ // Existing00682040 source, genuine SphereMap types.
    SphereMap::const_iterator found=spheres->find(key);
    if(found==spheres->end())throw std::runtime_error("bsphere map error");
    return found->second;
}
bool has(Key key){return spheres->find(key)!=spheres->end();} // 00682100 requires initialized map.
bool remove(Key key){ // 00682150: absence before first allocation is valid.
    if(!spheres)return false;
    SphereMap::iterator found=spheres->find(key);
    if(found==spheres->end())return false;
    spheres->erase(found);return true;
}
unsigned size(){return spheres?static_cast<unsigned>(spheres->size()):0;}
}

namespace PlayerMeshBackend {
namespace {
struct Context {
    std::map<Ogre::RbxSubMesh*,std::string> names;
    int counter;
    boost::recursive_mutex mutex;
    Context() : counter(0) {}
};
typedef char ContextSize[sizeof(Context)==0x30?1:-1];
typedef char ContextMutex[offsetof(Context,mutex)==0x24?1:-1];
Context* context;
boost::once_flag once = BOOST_ONCE_INIT;
void closeContext() { delete context; }
void openContext() { context = new Context; std::atexit(closeContext); }

// 00679ae0, existing OgreUtil::createVertexData body using real SDK declarations.
Ogre::VertexData* createVertexData(const float* positions, unsigned count,
    const float* normals, const float* colors, const float* texCoords) {
    using namespace Ogre;
    RenderSystem* rs = Root::getSingleton().getRenderSystem();
    VertexData* vd = new VertexData;
    vd->vertexCount = count;
    VertexDeclaration* decl = vd->vertexDeclaration;
    unsigned short source = 0;
    decl->addElement(source,0,VET_FLOAT3,VES_POSITION);
    HardwareVertexBufferSharedPtr buffer = HardwareBufferManager::getSingleton().createVertexBuffer(
        VertexElement::getTypeSize(VET_FLOAT3),count,HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    buffer->writeData(0,buffer->getSizeInBytes(),positions,true);
    vd->vertexBufferBinding->setBinding(source++,buffer);
    if(colors) {
        std::vector<RGBA> converted(count);
        for(unsigned i=0;i<count;++i) {
            // Target repeats component r in all four channels; preserve recovered behavior.
            ColourValue colour(colors[i*4],colors[i*4],colors[i*4],colors[i*4]);
            rs->convertColourValue(colour,&converted[i]);
        }
        decl->addElement(source,0,VET_COLOUR,VES_DIFFUSE);
        buffer = HardwareBufferManager::getSingleton().createVertexBuffer(
            VertexElement::getTypeSize(VET_COLOUR),count,HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        buffer->writeData(0,buffer->getSizeInBytes(),&converted[0],true);
        vd->vertexBufferBinding->setBinding(source++,buffer);
    }
    if(normals) {
        decl->addElement(source,0,VET_FLOAT3,VES_NORMAL);
        buffer = HardwareBufferManager::getSingleton().createVertexBuffer(
            VertexElement::getTypeSize(VET_FLOAT3),count,HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        buffer->writeData(0,buffer->getSizeInBytes(),normals,true);
        vd->vertexBufferBinding->setBinding(source++,buffer);
    }
    if(texCoords) {
        decl->addElement(source,0,VET_FLOAT2,VES_TEXTURE_COORDINATES);
        buffer = HardwareBufferManager::getSingleton().createVertexBuffer(
            VertexElement::getTypeSize(VET_FLOAT2),count,HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        buffer->writeData(0,buffer->getSizeInBytes(),texCoords,true);
        vd->vertexBufferBinding->setBinding(source,buffer);
    }
    return vd;
}
}

// 0067c130: detached RbxSubMesh, its own vertex data, and 16/32-bit index upload.
Ogre::RbxSubMesh* createIndexed(const float* vertices,unsigned vertexCount,
    const float* normals,const float* colours,const float* texCoords,
    const unsigned short* indices16,const unsigned* indices32,unsigned triangles,
    Ogre::Vector3& minimum,Ogre::Vector3& maximum) {
    using namespace Ogre;
    boost::call_once(openContext,once);
    boost::recursive_mutex::scoped_lock lock(context->mutex);
    RbxSubMesh* result = new RbxSubMesh;
    result->parent = 0;
    result->vertexData = createVertexData(vertices,vertexCount,normals,colours,texCoords);
    result->useSharedVertices = false;
    unsigned count = triangles*3;
    HardwareIndexBufferSharedPtr buffer = HardwareBufferManager::getSingleton().createIndexBuffer(
        indices16?HardwareIndexBuffer::IT_16BIT:HardwareIndexBuffer::IT_32BIT,
        count,HardwareBuffer::HBU_STATIC_WRITE_ONLY,false);
    buffer->writeData(0,buffer->getSizeInBytes(),indices16?static_cast<const void*>(indices16):indices32,true);
    result->indexData->indexBuffer = buffer;
    result->indexData->indexCount = count;
    result->indexData->indexStart = 0;
    Vector3 low(1e9f,1e9f,1e9f),high(-1e9f,-1e9f,-1e9f);
    for(unsigned i=0;i<3*vertexCount;i+=3) {
        if(low.x>vertices[i])low.x=vertices[i]; if(low.y>vertices[i+1])low.y=vertices[i+1]; if(low.z>vertices[i+2])low.z=vertices[i+2];
        if(high.x<vertices[i])high.x=vertices[i]; if(high.y<vertices[i+1])high.y=vertices[i+1]; if(high.z<vertices[i+2])high.z=vertices[i+2];
    }
    minimum=low; maximum=high;
    AxisAlignedBox bounds(low,high);
    result->bounds=bounds;
    result->radius=bounds.getHalfSize().length();
    std::string name="sms"+StringConverter::toString(context->counter++);
    context->names[result]=name;
    LogManager::getSingleton().logMessage("RBX cr "+name,LML_NORMAL,false);
    return result;
}

// Typed ownership counterpart of 005486e0's +24 branch. Bounds-cache removal
// remains the Level owner's responsibility; this unit owns only backend resources.
void destroyIndexed(Ogre::RbxSubMesh* mesh) {
    boost::recursive_mutex::scoped_lock lock(context->mutex);
    std::map<Ogre::RbxSubMesh*,std::string>::iterator found=context->names.find(mesh);
    Ogre::LogManager::getSingleton().logMessage("RBX rm "+found->second,Ogre::LML_NORMAL,false);
    context->names.erase(found);
    delete mesh;
}
unsigned liveMeshes() {
    if(!context)return 0;
    boost::recursive_mutex::scoped_lock lock(context->mutex);
    return static_cast<unsigned>(context->names.size());
}
}
