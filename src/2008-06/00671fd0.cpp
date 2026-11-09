// from server: 100% by EspClaude
// from server: 58% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_8ec9b5cde1252dbf.cpp

// Candidate translation unit (score above; library headers required).
// Native324B allocation0045b425, ctor674210, dtor673a90.
#undef OGRE_NONCLIENT_BUILD
#include "roc_adorn_quad_native_vector_copy_header03c28376dd2c44a8.cpp"
#include "roc_adorn_quad_native_sphere_inline_header09b8961a0e5aa4f5.cpp"
#include "roc_adorn_native_novtable_interface91b88275e0007f5c.cpp"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/Ogre.h"
#include <vector>
#include <map>
#include <cstdio>
#include <exception>
#include <G3D/Ray.h>
#include <cmath>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreStringConverter.h"
#include <G3D/AABox.h>
// Authentic OpenRBX util/IndexBox.h; preserved verbatim.
#ifndef UTIL_INDEXBOX_H
#define UTIL_INDEXBOX_H

#include <G3D/Vector3.h>

namespace RBX {

using G3D::Vector3;

// VTABLE: WEBSERVICE 0x1022cf1c
class IndexBox
{
public:
	IndexBox(const Vector3& min, const Vector3& max);

	virtual ~IndexBox() // vtable+0x00
	{
	}

	// SYNTHETIC: WEBSERVICE 0x100314f0
	// RBX::IndexBox::`scalar deleting destructor'

	Vector3 getFaceNormal(int f) const
	{
		return Vector3(INDEXBOX_FACE_TO_NORMAL[f][0], INDEXBOX_FACE_TO_NORMAL[f][1], INDEXBOX_FACE_TO_NORMAL[f][2]);
	}

	void getFaceCorners(int f, Vector3& v0, Vector3& v1, Vector3& v2, Vector3& v3) const;

	static const int INDEXBOX_FACE_TO_VERTEX[6][4];
	static const float INDEXBOX_FACE_TO_NORMAL[6][3];

private:
	Vector3 corner[8]; // 0x04
};

} // namespace RBX

#endif // UTIL_INDEXBOX_H

// End authentic IndexBox declaration.

namespace Ogre {
class AdornQuadric {
public:
    int normals;
    bool textureCoords;
    int orientation;
    int drawStyle;
    ColourValue colour;
    Vector3 offset;
    AdornQuadric(); // native00685e30; normal constructor call retained.
    void setOffset(const Vector3&); // native00685e10.
    ManualObject* cylinder(SceneManager*,const String&,ManualObject*,float,float,float,int,int);
    ManualObject* disk(SceneManager*,const String&,ManualObject*,float,float,int,int);
};
}

namespace Ogre {
class VisualEngine;
class RbxSubEntity : public SubEntity, public ShadowCaster {
public:
    virtual ~RbxSubEntity();
    // 0084e90c slots 48/4c; bodies 00685820/00685830.
    virtual void setFloat138(float);
    virtual float getFloat138() const;
    void setLodMesh(unsigned int, SubMesh*); // 006850b0
    SubMesh* getLodMesh(unsigned int);       // 006850d0
    void setLod(unsigned int);              // 006850f0
};
class RbxSceneNode : public SceneNode {
    typedef std::map<unsigned long, Matrix4*> TransformMap;
    mutable TransformMap transforms;
public:
    RbxSceneNode(SceneManager*, const String&);
    virtual ~RbxSceneNode();
    virtual void setTransform(unsigned long, const Matrix4&);
    virtual const Matrix4& getTransform(unsigned long) const;
    virtual bool hasTransform(unsigned long) const;
    virtual void setSphere(unsigned long, const Vector4&);
    virtual const Sphere& getSphere(unsigned long) const;
};
class RbxEntityEntry; // Native 2a4 member is a vector; element never instantiated here.
class RbxEntity : public Entity {
    void* field274;
    bool field278, field279, field27a;
    AxisAlignedBox field27c;
    float field29c;
    int field2a0;
    std::vector<RbxEntityEntry> field2a4;
public:
    RbxEntity();
    virtual ~RbxEntity();
    void setMesh(MeshPtr);                 // 0067c520
    void setContext18(void*);              // 0067c510
    RbxSubEntity* addSubEntity(SubMesh*, unsigned int); // 0067d9b0
    void mergeBounds(AxisAlignedBox);      // 007a9c40
};
}

namespace Ogre {
// Opaque pointee only.684b10 initializes character metrics at0; no font vptr.
class RbxFont { public: ~RbxFont(); };
SharedPtr<RbxFont> loadRbxFont(const std::string&); //684eb0 cdecl hidden result.
}
namespace RBX {
// Opaque context view: only observed SceneManager slot4 is accessed.
class AdornContextView { public:
    Ogre::SceneManager* sceneManager() {return *(Ogre::SceneManager**)((char*)this+4);}
    Ogre::Camera* camera() {return *(Ogre::Camera**)((char*)this+8);}
    void* renderContext() {return (char*)this+0x18;}
};
extern Ogre::SharedPtr<Ogre::RbxFont> nativeAdornFont; //962da8.
extern int nativeAdornCount; //97db28.
std::string nativeResolveFile(const char*); //55d0b0.
class AdornRbxGfx : public Adorn {
public:

    AdornContextView* engine;                         // 04, constructor arg.
    std::string label;                    // 08.
    Ogre::MaterialPtr textureMaterial;    // 24.
    Ogre::SceneNode* root;                // 30.
    Ogre::RbxSceneNode* renderNode;        // 34.
    Ogre::MaterialPtr solidMaterial;      // 38.
    int particleCount;                    // 44,670d50 count sum.
    std::vector<Ogre::RbxSubEntity*> freeSubEntities; //48,671d60.
    std::vector<Ogre::RbxSubEntity*> activeSubEntities; //60.
    typedef std::map<std::string,Ogre::MeshPtr> MeshCache;
    MeshCache meshes;                     // 78.
    Ogre::RbxEntity* entity;               // 98.
    Ogre::SceneNode* explosionRoot;        // 9c.
    std::vector<Ogre::SceneNode*> explosionNodes; //a0.
    typedef std::map<std::string,Ogre::SceneNode*> NodeCache;
    NodeCache explosions;                 // b8.
    Ogre::SceneNode* sparkleRoot;          // d8.
    std::vector<Ogre::SceneNode*> sparkleNodes; //dc.
    NodeCache sparkles;                    // f4.
    G3D::CoordinateFrame coordinateFrame; // 114.

    AdornRbxGfx(AdornContextView*);
    virtual ~AdornRbxGfx();
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> createTextureProxy(const std::string& filename);
		virtual void prepareRenderPass();
		virtual void finishRenderPass();
		virtual G3D::Rect2D getViewport() const;
		virtual int getWidth() const;
		virtual int getHeight() const;
		virtual void setTexture(int id, G3D::ReferenceCountedPointer<TextureProxyBase> _texture);
		virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase> _texture) const;
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const;
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const;
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const;
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const;
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign, YAlign yalign, Spacing spacing) const;
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
		virtual void setColor(const G3D::Color4& color);
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void sparkle(); // Native00674790, vtable4c.
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale);
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale);
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale);
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2, const G3D::Vector3& v3, const G3D::Color4& color);
    Ogre::MeshPtr findMesh(std::string); //6712e0.
    void localMatrix(Ogre::Matrix4&,const Ogre::Vector3&,const Ogre::Vector3&,const Ogre::Quaternion&); //66faf0.
    std::string uniqueName(); //66fc00.
    void updateColor(const G3D::Color4&,bool); //670400,ret8.
    void worldMatrix(Ogre::Matrix4&); //66fba0,ret4.
    void drawMesh(const Ogre::MeshPtr&,const Ogre::Matrix4&,const Ogre::MaterialPtr&); //671f00,ret12.
    void cacheMesh(const std::string&,const Ogre::MeshPtr&); //671b60,ret8.
    Ogre::SceneManager* sceneManager() {return engine->sceneManager();}
};
typedef char NativeAdornSize[sizeof(AdornRbxGfx)==0x144?1:-1];
typedef char NativeEntitySize[sizeof(Ogre::RbxEntity)==0x2bc?1:-1];
typedef char NativeSceneNodeSize[sizeof(Ogre::RbxSceneNode)==0x248?1:-1];
static inline void setSphereParam(Ogre::Vector4& p,float r,const Ogre::Vector3& c){p.x=r;p.y=c.x;p.z=c.y;p.w=c.z;}
extern Ogre::MeshPtr adornCylinderMesh; //0097dabc.
extern std::string adornCylinderSuffix; //0097dad4.
Ogre::Vector3 nativeVector(const G3D::Vector3&);
Ogre::ColourValue nativeColour(const G3D::Color4&);
static inline Ogre::Vector4 sphereParam(float r,const Ogre::Vector3& c){return Ogre::Vector4(r,c.x,c.y,c.z);}
void AdornRbxGfx::box(const G3D::AABox& bounds,const G3D::Color4& color,const G3D::Color4&) {
    IndexBox cube(G3D::Vector3(-1,-1,-1),G3D::Vector3(1,1,1));
    char key[64];
    _snprintf(key,64,"c%d%d%d",(int)(color.r*255.0f),(int)(color.g*255.0f),(int)(color.b*255.0f));
    Ogre::MeshPtr mesh=findMesh(key);
    if(mesh.isNull()) {
        Ogre::SceneManager* scene=sceneManager();
        Ogre::ManualObject* object=scene->createManualObject("box"+uniqueName());
        object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
        object->colour(nativeColour(color));
        int index=0;
        for(int face=0;face<6;++face) {
            G3D::Vector3 a,b,c,d;
            cube.getFaceCorners(face,a,b,c,d);
            object->normal(nativeVector(cube.getFaceNormal(face)));
            object->position(nativeVector(a)); object->index(index++);
            object->position(nativeVector(b)); object->index(index++);
            object->position(nativeVector(c)); object->index(index++);
            object->position(nativeVector(a)); object->index(index++);
            object->position(nativeVector(c)); object->index(index++);
            object->position(nativeVector(d)); object->index(index++);
        }
        object->end();
        object->setMaterialName(0,solidMaterial->getName());
        mesh=object->convertToMesh(sceneManager()->getName()+"bmsh"+Ogre::StringConverter::toString(meshes.size()),Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
        cacheMesh(std::string(key),mesh);
        Ogre::Mesh* m=mesh.getPointer();
        float radius=mesh->getBoundingSphereRadius();
        Ogre::Vector4 parameter;
        setSphereParam(parameter,radius,m->getBounds().getCenter());
        renderNode->setSphere(reinterpret_cast<unsigned long>(mesh->getSubMesh(0)),parameter);
    }
    Ogre::Matrix4 world;
    localMatrix(world,Ogre::Vector3(0,0,0),Ogre::Vector3(1,1,1),Ogre::Quaternion(1,0,0,0));
    Ogre::Matrix4 local;
    local.makeTransform(nativeVector(bounds.center()),Ogre::Vector3((bounds.high().x-bounds.low().x)*0.5f,(bounds.high().y-bounds.low().y)*0.5f,(bounds.high().z-bounds.low().z)*0.5f),Ogre::Quaternion(1,0,0,0));
    Ogre::Matrix4 transform=world.concatenate(local);
    drawMesh(mesh,transform,solidMaterial);
}


}

