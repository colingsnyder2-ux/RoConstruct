#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <cmath>
#include <cstdio>
#undef main

int main(){
    Ogre::Root root("","","p4-cylinder-mesh.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P4CylinderMesh",64,64,false,&options);
    RBX::View::RenderSurfaceTypes surfaces;
    for(int cycle=0;cycle<32;++cycle){
        PlayerBlockMesh::MeshRef mesh=new PlayerBlockMesh::CylinderMesh(G3D::Vector3(4,4,4),surfaces);
        if(mesh->geometryKind!=3 || mesh->levels.size()!=1 || mesh->level0().indexArray.size()!=216)return 2;
        Ogre::AxisAlignedBox bounds;mesh->level0().upload(false,bounds);
        float radial=6.0f/static_cast<float>(std::sqrt(10.0));
        if((bounds.getMinimum()+Ogre::Vector3(2,radial,radial)).length()>.00001f ||
           (bounds.getMaximum()-Ogre::Vector3(2,radial,radial)).length()>.00001f)return 3;
        Ogre::VertexData* data=mesh->level0().backend->vertexData;
        const Ogre::VertexElement* position=data->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
        Ogre::HardwareVertexBufferSharedPtr buffer=data->vertexBufferBinding->getBuffer(position->getSource());
        unsigned char* bytes=static_cast<unsigned char*>(buffer->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));
        bool valid=true;
        for(size_t i=0;i<data->vertexCount;++i){
            float* p;position->baseVertexPointerToElement(bytes+i*buffer->getVertexSize(),&p);
            float r=std::sqrt(p[1]*p[1]+p[2]*p[2]);
            if(r>2.00001f || (std::fabs(p[0])<1.99999f && std::fabs(r-2)>0.00001f))valid=false;
        }
        buffer->unlock();if(!valid)return 5;
        mesh=PlayerBlockMesh::MeshRef();
        if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 4;
    }
    PlayerBlockMesh::MeshRef retained=PlayerBlockMesh::CylinderMesh::create(G3D::Vector3(4,4,4),surfaces);
    for(int i=0;i<16;++i){
        PlayerBlockMesh::MeshRef same=PlayerBlockMesh::CylinderMesh::create(G3D::Vector3(4,4,4),surfaces);
        if(same.getPointer()!=retained.getPointer())return 6;
    }
    for(int i=0;i<120;++i){
        PlayerBlockMesh::MeshRef temporary=PlayerBlockMesh::CylinderMesh::create(G3D::Vector3(4+i*.01f,4,4),surfaces);
    }
    PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::CylinderMesh::cachedMeshes()!=1 || PlayerBlockMesh::liveLevels()!=1)return 7;
    retained=PlayerBlockMesh::MeshRef();PlayerBlockMesh::flushUnused();
    if(PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences())return 8;
    std::printf("PASS: cylinder geometry and 32 clean lifetimes\n");
    return 0;
}
