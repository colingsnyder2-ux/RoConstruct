// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_adorn_box_sphere_material_12e9a5f1f803fc53.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <RbxGraphics/Adorn.h>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreSceneManager.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreManualObject.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreCamera.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreMesh.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreMaterial.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreSphere.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreResourceGroupManager.h"
#include <stdexcept>
#include <G3D/Ray.h>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreStringConverter.h"
#include <algorithm>
#include <cmath>
#include <G3D/Box.h>
#include <stdio.h>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreMaterialManager.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreTechnique.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgrePass.h"
namespace Ogre {
// Same native field declaration as the recovered GLU generator units.
class AdornQuadric {
public:
    int normals;
    bool textureCoords;
    int orientation;
    int drawStyle;
    ColourValue colour;
    Vector3 offset;
    AdornQuadric();
    ManualObject* sphere(SceneManager*,const String&,ManualObject*,float,int,int);
};
}
namespace RBX {
class AdornRbxGfx : public Adorn {
public:
    void sphere(const G3D::Sphere&,const G3D::Color4&,const G3D::Color4&);
    void box(const G3D::AABox&,const G3D::Color4&,const G3D::Color4&);
    void cacheMesh(const std::string&,const Ogre::MeshPtr&); //00671b60 ret8
    void quad(const G3D::Vector3&,const G3D::Vector3&,const G3D::Vector3&,const G3D::Vector3&,const G3D::Color4&);
    void cylinderAlongX(float,float,const G3D::Color4&,const G3D::Color4&);
    void ray(const G3D::Ray&,const G3D::Color4&,float);
    Ogre::MeshPtr findMesh(std::string); //006712e0, native by-value string.
    void localMatrix(Ogre::Matrix4&,const Ogre::Vector3&,const Ogre::Vector3&,const Ogre::Quaternion&); //0066faf0,ret16.
    std::string uniqueName(); // 0066fc00: genuine string hidden-result return.
    __declspec(noinline) void updateColor(const G3D::Color4&,int); // 00670400, ret8.
    void worldMatrix(Ogre::Matrix4&); // 0066fba0, ret4.
    void drawMesh(const Ogre::MeshPtr&,const Ogre::Matrix4&,const Ogre::MaterialPtr&); // 00671f00, ret12.
};

// Observed native conversion helpers006784d0/006784f0: hidden result plus
// one source reference, copy all three/four real float components.
Ogre::Vector3 nativeVector(const G3D::Vector3&);
Ogre::ColourValue nativeColour(const G3D::Color4&);
static const float faceNormals[18]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
void AdornRbxGfx::box(const G3D::AABox& bounds,const G3D::Color4& color,const G3D::Color4&) {
    G3D::Box cube(G3D::Vector3(-1,-1,-1),G3D::Vector3(1,1,1));
    char key[64];
    _snprintf(key,64,"c%d%d%d",(int)(color.r*255.0f),(int)(color.g*255.0f),(int)(color.b*255.0f));
    Ogre::MeshPtr mesh=findMesh(key);
    if(mesh.isNull()) {
        void* engine=*(void**)((char*)this+4);
        Ogre::SceneManager* scene=*(Ogre::SceneManager**)((char*)engine+4);
        Ogre::ManualObject* object=scene->createManualObject("box"+uniqueName());
        object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
        object->colour(nativeColour(color));
        int index=0;
        int face=0;
        for(const float* normal=faceNormals;normal<faceNormals+18;normal+=3,++face) {
            G3D::Vector3 a(0,0,0),b(0,0,0),c(0,0,0),d(0,0,0);
            cube.getFaceCorners(face,a,b,c,d);
            object->normal(nativeVector(G3D::Vector3(normal[0],normal[1],normal[2])));
            object->position(nativeVector(a)); object->index(index++);
            object->position(nativeVector(b)); object->index(index++);
            object->position(nativeVector(c)); object->index(index++);
            object->position(nativeVector(a)); object->index(index++);
            object->position(nativeVector(c)); object->index(index++);
            object->position(nativeVector(d)); object->index(index++);
        }
        object->end();
        const Ogre::MaterialPtr& material=*(Ogre::MaterialPtr*)((char*)this+0x38);
        object->setMaterialName(0,material->getName());
        mesh=object->convertToMesh(scene->getName()+"bmsh"+Ogre::StringConverter::toString(*(unsigned int*)((char*)this+0x94)),Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
        cacheMesh(key,mesh);
        float radius=mesh->getBoundingSphereRadius();
        Ogre::Vector3 center=mesh->getBounds().getCenter();
        Ogre::Vector4 parameter(radius,center.x,center.y,center.z);
        void* node=*(void**)((char*)this+0x34);
        typedef void (__thiscall *SetParameter)(void*,size_t,const Ogre::Vector4&);
        ((SetParameter)(*(void***)node)[113])(node,(size_t)mesh->getSubMesh(0),parameter);
    }
    Ogre::Matrix4 world;
    localMatrix(world,Ogre::Vector3(0,0,0),Ogre::Vector3(1,1,1),Ogre::Quaternion(1,0,0,0));
    Ogre::Matrix4 local;
    G3D::Vector3 center((bounds.low().x+bounds.high().x)*0.5f,(bounds.low().y+bounds.high().y)*0.5f,(bounds.low().z+bounds.high().z)*0.5f);
    local.makeTransform(nativeVector(center),Ogre::Vector3((bounds.high().x-bounds.low().x)*0.5f,(bounds.high().y-bounds.low().y)*0.5f,(bounds.high().z-bounds.low().z)*0.5f),Ogre::Quaternion(1,0,0,0));
    drawMesh(mesh,world.concatenate(local),*(Ogre::MaterialPtr*)((char*)this+0x38));
}

void AdornRbxGfx::updateColor(const G3D::Color4& color,int variant) {
    char name[64];
    _snprintf(name,64,"adrnClr%.3f%.3f%.3f%.3f%d",color.r,color.g,color.b,color.a,variant);
    (*(Ogre::MaterialPtr*)((char*)this+0x24))=Ogre::MaterialManager::getSingleton().getByName(name);
    if(!(*(Ogre::MaterialPtr*)((char*)this+0x24)).isNull()) return;
    (*(Ogre::MaterialPtr*)((char*)this+0x24))=Ogre::MaterialManager::getSingleton().create(name,"General",false,0,0);
    Ogre::Pass* pass=(*(Ogre::MaterialPtr*)((char*)this+0x24))->getTechnique(0)->getPass(0);
    pass->setAmbient(color.r,color.g,color.b);
    pass->setDiffuse(color.r,color.g,color.b,color.a);
    pass->setSpecular(color.r,color.g,color.b,color.a);
    pass->setShininess(10.0f);
    (*(Ogre::MaterialPtr*)((char*)this+0x24))->setLightingEnabled(true);
}
class AdornMeshCache { public: Ogre::MeshPtr& operator[](const std::string&); };
void AdornRbxGfx::sphere(const G3D::Sphere& value,const G3D::Color4& color,const G3D::Color4&) {
    Ogre::AdornQuadric quadric;
    updateColor(G3D::Color4(color.r*0.8f,color.g*0.8f,color.b*0.8f,color.a*0.8f),0);
    std::string key("sph0001");
    Ogre::MeshPtr mesh=findMesh(key);
    if(mesh.isNull()) {
        void* engine=*(void**)((char*)this+4);
        Ogre::SceneManager* scene=*(Ogre::SceneManager**)((char*)engine+4);
        Ogre::ManualObject* object=quadric.sphere(scene,"sph"+uniqueName(),0,1,17,17);
        for(int i=0;i<(int)object->getNumSections();++i)
            object->setMaterialName(i,(*(Ogre::MaterialPtr*)((char*)this+0x24))->getName());
        mesh=object->convertToMesh(scene->getName()+"smsh"+Ogre::StringConverter::toString(*(unsigned int*)((char*)this+0x94)),Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
        (*(AdornMeshCache*)((char*)this+0x78))[key]=mesh;
        float radius=mesh->getBoundingSphereRadius();
        Ogre::Vector3 center=mesh->getBounds().getCenter();
        Ogre::Vector4 parameter(radius,center.x,center.y,center.z);
        for(int i=0;i<mesh->getNumSubMeshes();++i) {
            void* node=*(void**)((char*)this+0x34);
            typedef void (__thiscall *SetParameter)(void*,size_t,const Ogre::Vector4&);
            ((SetParameter)(*(void***)node)[113])(node,(size_t)mesh->getSubMesh((unsigned short)i),parameter);
        }
    }
    Ogre::Matrix4 world;
    localMatrix(world,Ogre::Vector3(value.center.x,value.center.y,value.center.z),Ogre::Vector3(value.radius,value.radius,value.radius),Ogre::Quaternion(1,0,0,0));
    drawMesh(mesh,world,*(Ogre::MaterialPtr*)((char*)this+0x24));
}
}
