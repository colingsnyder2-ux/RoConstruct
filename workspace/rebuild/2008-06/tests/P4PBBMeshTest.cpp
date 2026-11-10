#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <cmath>
#include <cstdio>
#undef main

int main(){
    Ogre::Root root("","","p4-pbb-mesh.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P4PBBMesh",64,64,false,&options);
    RBX::View::RenderSurfaceTypes surfaces;
    for(int cycle=0;cycle<32;++cycle){
        PlayerBlockMesh::MeshRef mesh=new PlayerBlockMesh::PBBMesh(G3D::Vector3(40,8,6),surfaces);
        if(mesh->geometryKind!=0 || mesh->levels.size()!=1 || mesh->level0().indexArray.size()!=24)return 2;
        Ogre::AxisAlignedBox bounds;mesh->level0().upload(false,bounds);
        if(mesh->level0().backend->vertexData->vertexCount!=24 || mesh->level0().backend->indexData->indexCount!=36)return 3;
        if((bounds.getMinimum()+Ogre::Vector3(20,4,3)).length()>.00001f ||
           (bounds.getMaximum()-Ogre::Vector3(20,4,3)).length()>.00001f)return 4;
        Ogre::VertexData* data=mesh->level0().backend->vertexData;
        const Ogre::VertexElement* normal=data->vertexDeclaration->findElementBySemantic(Ogre::VES_NORMAL);
        const Ogre::VertexElement* uv=data->vertexDeclaration->findElementBySemantic(Ogre::VES_TEXTURE_COORDINATES);
        Ogre::HardwareVertexBufferSharedPtr nb=data->vertexBufferBinding->getBuffer(normal->getSource());
        Ogre::HardwareVertexBufferSharedPtr tb=data->vertexBufferBinding->getBuffer(uv->getSource());
        unsigned char* n=static_cast<unsigned char*>(nb->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
        unsigned char* t=static_cast<unsigned char*>(tb->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
        bool valid=true;
        for(size_t i=0;i<data->vertexCount;++i){
            float *direction,*texture;
            normal->baseVertexPointerToElement(n+i*nb->getVertexSize(),&direction);
            uv->baseVertexPointerToElement(t+i*tb->getVertexSize(),&texture);
            int axial=0;
            for(int k=0;k<3;++k){if(std::fabs(direction[k])==1)++axial;else if(std::fabs(direction[k])>.050001f)valid=false;}
            if(axial!=1 || texture[0]!=.125f || texture[1]!=.25f)valid=false;
        }
        tb->unlock();nb->unlock();if(!valid)return 6;
        mesh=PlayerBlockMesh::MeshRef();
        if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 5;
    }
    surfaces.data=RBX::View::STUDS<<(3*RBX::NORM_Y);
    PlayerBlockMesh::MeshRef studs=new PlayerBlockMesh::PBBMesh(G3D::Vector3(40,8,6),surfaces);
    // 004f3650 splits the shorter 6-stud top axis into two texture spans.
    if(studs->level0().indexArray.size()!=28)return 7;
    Ogre::AxisAlignedBox bounds;studs->level0().upload(false,bounds);
    if(studs->level0().backend->vertexData->vertexCount!=28 || studs->level0().backend->indexData->indexCount!=42)return 8;
    studs=PlayerBlockMesh::MeshRef();
    if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 9;
    surfaces.data=0;
    PlayerBlockMesh::MeshRef retained=PlayerBlockMesh::PBBMesh::create(G3D::Vector3(40,8,6),surfaces);
    for(int i=0;i<32;++i){
        PlayerBlockMesh::MeshRef same=PlayerBlockMesh::PBBMesh::create(G3D::Vector3(40,8,6),surfaces);
    }
    if(PlayerBlockMesh::PBBMesh::cachedMeshes()<1 || PlayerBlockMesh::PBBMesh::cachedMeshes()>4)return 10;
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::PBBMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=1)return 11;
    retained=PlayerBlockMesh::MeshRef();PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences())return 12;
    std::printf("PASS: PBB flat faces, GPU bounds and 32 clean lifetimes\n");
    return 0;
}
