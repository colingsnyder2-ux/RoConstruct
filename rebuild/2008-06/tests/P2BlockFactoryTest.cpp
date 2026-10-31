#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <cstdio>
#include <map>
#undef main
int main(){
    Ogre::Root root("","","p2-block-factory.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P2BlockFactory",64,64,false,&options);
    RBX::View::RenderSurfaceTypes surfaces;
    std::map<PlayerBlockMesh::BlockMesh*,PlayerBlockMesh::MeshRef> owners;
    unsigned before=PlayerBlockMesh::producerCalls();
    for(int i=0;i<512;++i){
        PlayerBlockMesh::MeshRef mesh=PlayerBlockMesh::BlockMesh::create(G3D::Vector3(2,4,6),surfaces,RBX::BrickColor());
        if(mesh->levels.size()!=2 || mesh->levels[0]->indexArray.size()!=104 || mesh->levels[1]->indexArray.size()!=24)return 2;
        bool fresh=owners.find(mesh.getPointer())==owners.end();
        owners[mesh.getPointer()]=mesh;
        if(fresh)for(int level=0;level<2;++level){
            Ogre::AxisAlignedBox bounds;mesh->levels[level]->upload(level!=0,bounds);
            if(bounds.getMinimum()!=Ogre::Vector3(-1,-2,-3) || bounds.getMaximum()!=Ogre::Vector3(1,2,3))return 3;
            if(mesh->levels[level]->backend->indexData->indexBuffer->getType()!=(level?Ogre::HardwareIndexBuffer::IT_32BIT:Ogre::HardwareIndexBuffer::IT_16BIT))return 4;
        }
        if(owners.size()>4)return 5;
    }
    if(owners.size()!=4 || PlayerBlockMesh::producerCalls()-before!=8 || PlayerBlockMesh::cachedMeshes()!=4)return 6;
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::liveLevels()!=8 || PlayerMeshBackend::liveMeshes()!=8 || PlayerBlockMesh::activeReferences()!=512)return 7;
    PlayerBlockMesh::MeshRef retained=owners.begin()->second;owners.clear();
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=2 || PlayerMeshBackend::liveMeshes()!=2 || PlayerBlockMesh::activeReferences()!=128)return 8;
    // Cross the original every-100-creations purge while retaining a live client.
    for(int i=0;i<120;++i){
        PlayerBlockMesh::MeshRef mesh=PlayerBlockMesh::BlockMesh::create(G3D::Vector3(3+i*.01f,4,6),surfaces,RBX::BrickColor());
        if(mesh->levels.size()!=2)return 9;
    }
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=2 || PlayerMeshBackend::liveMeshes()!=2)return 10;
    retained=PlayerBlockMesh::MeshRef();PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 11;
    std::printf("PASS: 512 lookups reuse four paired-level variants; 100-creation purge preserves live owners; complete release\n");
    return 0;
}
