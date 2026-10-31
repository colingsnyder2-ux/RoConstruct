#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <cstdio>
#undef main
int main() {
    Ogre::Root root("","","p2-block-mesh.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P2BlockMesh",64,64,false,&options);
    for(int i=0;i<32;++i) {
        RBX::View::RenderSurfaceTypes surfaces;
        if(i%3)surfaces.data=1u<<(3*RBX::NORM_Y); // Studded top exercises tiled face generation.
        PlayerBlockMesh::MeshRef mesh=new PlayerBlockMesh::BlockMesh(G3D::Vector3(2,4,6),surfaces,RBX::BrickColor());
        PlayerBlockMesh::Level& level=mesh->level0();
        if(!level.dirty || level.sharedIndex!=-1 || level.backend)return 2;
        if(level.indexArray.size()<24 || level.indexArray.size()%4)return 3;
        if(PlayerBlockMesh::activeReferences()!=static_cast<unsigned>(level.indexArray.size()))return 4;
        Ogre::AxisAlignedBox bounds;level.upload(i%2!=0,bounds);
        if(level.dirty || !level.backend)return 5;
        if(bounds.getMinimum()!=Ogre::Vector3(-1,-2,-3) || bounds.getMaximum()!=Ogre::Vector3(1,2,3))return 6;
        if(level.backend->indexData->indexCount!=static_cast<unsigned>(level.indexArray.size()*3/2))return 7;
        Ogre::RbxSubMesh* uploaded=level.backend;
        level.upload(i%2!=0,bounds);
        if(level.backend!=uploaded || PlayerMeshBackend::liveMeshes()!=1)return 10;
        PlayerBlockMesh::MeshRef retained=mesh;mesh=PlayerBlockMesh::MeshRef();
        if(PlayerBlockMesh::liveLevels()!=1 || PlayerMeshBackend::liveMeshes()!=1)return 8;
        retained=PlayerBlockMesh::MeshRef();
        if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 9;
    }
    std::printf("PASS: %u recovered flat producers, smooth/tiled faces, both upload widths, retained ownership and teardown\n",PlayerBlockMesh::producerCalls());
    return 0;
}
