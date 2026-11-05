// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_codex_alias_55cb3ee98c5c3f01.cpp

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
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreSceneNode.h"
#include <map>
#include <G3D/Ray.h>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreStringConverter.h"
#include <algorithm>
#include <cmath>
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
namespace Ogre {
class RbxSceneNode:public SceneNode {
 typedef std::map<unsigned long, Matrix4*> TransformMap;
 mutable TransformMap transforms;
public:
 RbxSceneNode(SceneManager*,const String&);
 virtual ~RbxSceneNode();
 virtual void setTransform(unsigned long,const Matrix4&);
 virtual const Matrix4&getTransform(unsigned long)const;
 virtual bool hasTransform(unsigned long)const;
 virtual void setSphere(unsigned long,const Sphere&);
 virtual const Sphere&getSphere(unsigned long)const;
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
    __declspec(noalias) void localMatrix(Ogre::Matrix4&,const Ogre::Vector3&,const Ogre::Vector3&,const Ogre::Quaternion&); //0066faf0,ret16.
    std::string uniqueName(); // 0066fc00: genuine string hidden-result return.
    __declspec(noinline) void updateColor(const G3D::Color4&,int); // 00670400, ret8.
    void worldMatrix(Ogre::Matrix4&); // 0066fba0, ret4.
    void drawMesh(const Ogre::MeshPtr&,const Ogre::Matrix4&,const Ogre::MaterialPtr&); // 00671f00, ret12.
};

// Observed native conversion helpers006784d0/006784f0: hidden result plus
// one source reference, copy all three/four real float components.
Ogre::Vector3 nativeVector(const G3D::Vector3&);
Ogre::ColourValue nativeColour(const G3D::Color4&);
class AdornMeshCache { public: Ogre::MeshPtr& operator[](const std::string&); };
static inline Ogre::ManualObject* emitUnitSphere(Ogre::SceneManager* scene, const std::string& name, Ogre::AdornQuadric& quadric) { return quadric.sphere(scene,name,0,1,17,17); }
void AdornRbxGfx::sphere(const G3D::Sphere& value,const G3D::Color4& color,const G3D::Color4&) {
    Ogre::AdornQuadric quadric;
    int section=0;
    updateColor(G3D::Color4(color.r*0.8f,color.g*0.8f,color.b*0.8f,color.a*0.8f),0);
    std::string key("sph0001");
    Ogre::MeshPtr mesh=findMesh(key);
    if(mesh.isNull()) {
        Ogre::ManualObject* object=emitUnitSphere((*(Ogre::SceneManager**)((char*)(*(void**)((char*)this+4))+4)),"sph"+uniqueName(),quadric);
        for(;section<(int)object->getNumSections();++section)
            object->setMaterialName(section,(*(Ogre::MaterialPtr*)((char*)this+0x24))->getName());
        const unsigned int meshCounter=*(unsigned int*)((char*)this+0x94);
        mesh=object->convertToMesh((*(Ogre::SceneManager**)((char*)(*(void**)((char*)this+4))+4))->getName()+"smsh"+Ogre::StringConverter::toString(meshCounter),Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
        (*(AdornMeshCache*)((char*)this+0x78))[key]=mesh;
        Ogre::Mesh* sphereMesh=mesh.getPointer();
        float radius=sphereMesh->getBoundingSphereRadius();
        Ogre::Sphere parameter(sphereMesh->getBounds().getCenter(),radius);
        for(int i=0;i<mesh->getNumSubMeshes();++i) {
            (*(Ogre::RbxSceneNode**)((char*)this+0x34))->setSphere((unsigned long)mesh->getSubMesh((unsigned short)i),parameter);
        }
    }
    Ogre::Matrix4 world;
    localMatrix(world,Ogre::Vector3(value.center.x,value.center.y,value.center.z),Ogre::Vector3(value.radius,value.radius,value.radius),Ogre::Quaternion(1,0,0,0));
    drawMesh(mesh,world,*(Ogre::MaterialPtr*)((char*)this+0x24));
}
}
