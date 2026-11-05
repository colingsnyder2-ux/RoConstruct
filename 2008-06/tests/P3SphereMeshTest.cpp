#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <cmath>
#include <cstdio>
#undef main

static bool verify(PlayerBlockMesh::Mesh& mesh,const G3D::Vector3& size){
    if(mesh.geometryKind!=2 || mesh.levels.size()!=1 || mesh.shadowBackend)return false;
    PlayerBlockMesh::Level& level=mesh.level0();
    if(level.primitive!=G3D::RenderDevice::QUADS || level.indexArray.size()!=864)return false;
    Ogre::AxisAlignedBox bounds;level.upload(false,bounds);
    if(level.backend->vertexData->vertexCount!=294 || level.backend->indexData->indexCount!=1296)return false;
    if((bounds.getMinimum()+Ogre::Vector3(size.x,size.y,size.z)*.5f).length()>0.00001f ||
        (bounds.getMaximum()-Ogre::Vector3(size.x,size.y,size.z)*.5f).length()>0.00001f)return false;
    Ogre::VertexData* data=level.backend->vertexData;
    const Ogre::VertexElement* position=data->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
    const Ogre::VertexElement* normal=data->vertexDeclaration->findElementBySemantic(Ogre::VES_NORMAL);
    const Ogre::VertexElement* uv=data->vertexDeclaration->findElementBySemantic(Ogre::VES_TEXTURE_COORDINATES);
    Ogre::HardwareVertexBufferSharedPtr pb=data->vertexBufferBinding->getBuffer(position->getSource());
    Ogre::HardwareVertexBufferSharedPtr nb=data->vertexBufferBinding->getBuffer(normal->getSource());
    Ogre::HardwareVertexBufferSharedPtr tb=data->vertexBufferBinding->getBuffer(uv->getSource());
    // Native upload stores separate position/normal/UV streams.
    if(pb.getPointer()==nb.getPointer() || pb.getPointer()==tb.getPointer() || nb.getPointer()==tb.getPointer())return false;
    unsigned char* p=static_cast<unsigned char*>(pb->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
    unsigned char* n=static_cast<unsigned char*>(nb->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
    unsigned char* t=static_cast<unsigned char*>(tb->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
    bool valid=true;
    for(size_t i=0;i<data->vertexCount;++i){
        float *point,*unit,*texture;
        position->baseVertexPointerToElement(p+i*pb->getVertexSize(),&point);
        normal->baseVertexPointerToElement(n+i*nb->getVertexSize(),&unit);
        uv->baseVertexPointerToElement(t+i*tb->getVertexSize(),&texture);
        Ogre::Vector3 scaled(point[0]*2/size.x,point[1]*2/size.y,point[2]*2/size.z);
        if(std::fabs(scaled.length()-1)>0.00001f ||
            (scaled-Ogre::Vector3(unit[0],unit[1],unit[2])).length()>0.00001f ||
            texture[0]!=.125f || texture[1]!=.25f)valid=false;
    }
    tb->unlock();nb->unlock();pb->unlock();return valid;
}

int main(){
    Ogre::Root root("","","p3-sphere-mesh.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P3SphereMesh",64,64,false,&options);
    RBX::View::RenderSurfaceTypes surfaces;
    for(int cycle=0;cycle<32;++cycle){
        PlayerBlockMesh::MeshRef sphere=PlayerBlockMesh::SphereMesh::create(G3D::Vector3(4,4,4),surfaces);
        if(!verify(*sphere,G3D::Vector3(4,4,4)))return 2;
        for(int i=0;i<16;++i){
            PlayerBlockMesh::MeshRef same=PlayerBlockMesh::SphereMesh::create(G3D::Vector3(4,4,4),surfaces);
            if(same.getPointer()!=sphere.getPointer())return 3;
        }
        PlayerBlockMesh::flushUnused();
        if(PlayerBlockMesh::SphereMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=1 ||
            PlayerBlockMesh::activeReferences()!=864 || PlayerMeshBackend::liveMeshes()!=1)return 4;
        sphere=PlayerBlockMesh::MeshRef();PlayerBlockMesh::flushUnused();
        if(PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() ||
            PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 5;
    }
    PlayerBlockMesh::MeshRef retained=PlayerBlockMesh::SphereMesh::create(G3D::Vector3(6,4,2),surfaces);
    if(!verify(*retained,G3D::Vector3(6,4,2)))return 6;
    for(int i=0;i<120;++i){
        PlayerBlockMesh::MeshRef temporary=PlayerBlockMesh::SphereMesh::create(G3D::Vector3(2+i*.01f,4,2),surfaces);
    }
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=1 ||
        PlayerBlockMesh::activeReferences()!=864)return 7;
    retained=PlayerBlockMesh::MeshRef();PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() ||
        PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes() || PlayerSphereCache::size())return 8;
    std::printf("PASS: 294 native sphere vertices/864 retained quad indices/1296 GPU indices; unit normals, ellipsoid scaling, flat UV; 32 lifetimes, shared reuse, 100-creation purge, zero live resources\n");
    return 0;
}
