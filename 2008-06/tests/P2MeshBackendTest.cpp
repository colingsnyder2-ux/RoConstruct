#undef OGRE_NONCLIENT_BUILD
#include "PlayerMeshBackend.h"
#include <cstdio>
#include <cmath>
int main() {
    Ogre::Root root("","","p2-backend.log");
    root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* renderers=root.getAvailableRenderers();
    Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<renderers->size();++i)
        if((*renderers)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*renderers)[i];
    if(!renderer)return 1;
    root.setRenderSystem(renderer);
    renderer->setConfigOption("Full Screen","No");
    root.initialise(false);
    Ogre::NameValuePairList options; options["hidden"]="true";
    root.createRenderWindow("P2MeshBackend",64,64,false,&options);
    const float vertices[]={-2,-1,-3, 2,-1,-3, -2,4,3};
    const float normals[]={0,1,0, 0,1,0, 0,1,0};
    const float uvs[]={0,0, 1,0, 0,1};
    const unsigned short indices16[]={0,1,2};
    const unsigned indices32[]={0,1,2};
    for(int i=0;i<32;++i) {
        Ogre::Vector3 low,high;
        Ogre::RbxSubMesh* mesh=PlayerMeshBackend::createIndexed(vertices,3,normals,0,uvs,
            i%2?0:indices16,i%2?indices32:0,1,low,high);
        if(PlayerMeshBackend::liveMeshes()!=1 || mesh->parent || mesh->useSharedVertices)return 2;
        if(low!=Ogre::Vector3(-2,-1,-3) || high!=Ogre::Vector3(2,4,3))return 3;
        if(mesh->vertexData->vertexCount!=3 || mesh->indexData->indexCount!=3)return 4;
        if(mesh->indexData->indexBuffer->getType()!=(i%2?Ogre::HardwareIndexBuffer::IT_32BIT:Ogre::HardwareIndexBuffer::IT_16BIT))return 5;
        if(!mesh->vertexData->vertexDeclaration->findElementBySemantic(Ogre::VES_NORMAL) ||
           !mesh->vertexData->vertexDeclaration->findElementBySemantic(Ogre::VES_TEXTURE_COORDINATES))return 6;
        if(std::fabs(mesh->radius-std::sqrt(77.0f)*0.5f)>1e-5f)return 7;
        Ogre::HardwareVertexBufferSharedPtr verticesHeld=mesh->vertexData->vertexBufferBinding->getBuffer(0);
        Ogre::HardwareIndexBufferSharedPtr indicesHeld=mesh->indexData->indexBuffer;
        PlayerMeshBackend::destroyIndexed(mesh);
        if(PlayerMeshBackend::liveMeshes()!=0)return 8;
        if(verticesHeld.useCount()!=1 || indicesHeld.useCount()!=1)return 9;
    }
    std::puts("PASS: native submesh layout, both index widths, asymmetric bounds, channels and 32 teardown cycles");
    return 0;
}
