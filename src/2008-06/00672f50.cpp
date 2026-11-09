// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claudeM_854f25b05ca3c1ba.cpp

// Candidate translation unit (score above; library headers required).
// Native324B allocation0045b425, ctor674210, dtor673a90.
#undef OGRE_NONCLIENT_BUILD
#include "roc_adorn_quad_native_vector_copy_header03c28376dd2c44a8.cpp"
/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/
#ifndef __Sphere_H_
#define __Sphere_H_

// Precompiler options
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgrePrerequisites.h"

#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreVector3.h"

namespace Ogre {


    /** A sphere primitive, mostly used for bounds checking. 
    @remarks
        A sphere in math texts is normally represented by the function
        x^2 + y^2 + z^2 = r^2 (for sphere's centered on the origin). Ogre stores spheres
        simply as a center point and a radius.
    */
    class _OgreExport Sphere
    {
    protected:
        Real mRadius;
        Vector3 mCenter;
    public:
        /** Standard constructor - creates a unit sphere around the origin.*/
        Sphere() : mRadius(1.0), mCenter(Vector3::ZERO) {}
        /** Constructor allowing arbitrary spheres. 
            @param center The center point of the sphere.
            @param radius The radius of the sphere.
        */
        __forceinline Sphere(const Vector3& center, Real radius)
            : mRadius(radius), mCenter(center) {}
        __forceinline Sphere(const Vector3& center, Real radius, int)
            : mRadius(radius) { mCenter = center; }

        /** Returns the radius of the sphere. */
        Real getRadius(void) const { return mRadius; }

        /** Sets the radius of the sphere. */
        void setRadius(Real radius) { mRadius = radius; }

        /** Returns the center point of the sphere. */
        const Vector3& getCenter(void) const { return mCenter; }

        /** Sets the center point of the sphere. */
        void setCenter(const Vector3& center) { mCenter = center; }

		/** Returns whether or not this sphere interects another sphere. */
		bool intersects(const Sphere& s) const
		{
            return (s.mCenter - mCenter).squaredLength() <=
                Math::Sqr(s.mRadius + mRadius);
		}
		/** Returns whether or not this sphere interects a box. */
		bool intersects(const AxisAlignedBox& box) const
		{
			return Math::intersects(*this, box);
		}
		/** Returns whether or not this sphere interects a plane. */
		bool intersects(const Plane& plane) const
		{
			return Math::intersects(*this, plane);
		}
		/** Returns whether or not this sphere interects a point. */
		bool intersects(const Vector3& v) const
		{
            return ((v - mCenter).squaredLength() <= Math::Sqr(mRadius));
		}
        

    };

}

#endif


#include "roc_adorn_native_novtable_interface91b88275e0007f5c.cpp"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/Ogre.h"
#include <vector>
#include <map>
#include <cstdio>
#include <exception>
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
    virtual void setSphere(unsigned long, const Sphere&);
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
    std::string uniqueName(); //66fc00.
    void updateColor(const G3D::Color4&,bool); //670400,ret8.
    void worldMatrix(Ogre::Matrix4&); //66fba0,ret4.
    void drawMesh(const Ogre::MeshPtr&,const Ogre::Matrix4&,const Ogre::MaterialPtr&); //671f00,ret12.
    Ogre::SceneManager* sceneManager() {return engine->sceneManager();}
};
typedef char NativeAdornSize[sizeof(AdornRbxGfx)==0x144?1:-1];
typedef char NativeEntitySize[sizeof(Ogre::RbxEntity)==0x2bc?1:-1];
typedef char NativeSceneNodeSize[sizeof(Ogre::RbxSceneNode)==0x248?1:-1];
static Ogre::MeshPtr adornQuadMesh;
extern std::string adornMeshSuffix; // native 0097da68.
void AdornRbxGfx::quad(const G3D::Vector3& v0,const G3D::Vector3& v1,const G3D::Vector3& v2,const G3D::Vector3& v3,const G3D::Color4& color) {
    float y = v0.y-v2.y;
    float z = v0.z-v2.z;
    if (y<0) y=-y;
    if (z<0) z=-z;
    float extent = y>z ? y : z;
    Ogre::Vector3 center(v0.x,(v1.y+v3.y+v2.y+v0.y)*0.25f,(v1.z+v3.z+v0.z+v2.z)*0.25f);
    const G3D::Vector3& position = coordinateFrame.translation;
    Ogre::Sphere bounds(Ogre::Vector3(position.x+center.x,position.y+center.y,position.z+center.z),extent*1.4f);
    const Ogre::Vector3& eye = engine->camera()->getDerivedPosition();
    Ogre::Vector3 delta(position.x-eye.x,position.y-eye.y,position.z-eye.z);
    if (!engine->camera()->isVisible(bounds,0)) return;
    if (delta.squaredLength()>extent*extent*3600.0f) return;
    updateColor(color,false);
    if (!(v0.x==v1.x && v1.x==v2.x && v2.x==v3.x))
        throw std::runtime_error("Bad: quad not handled");
    if (adornQuadMesh.isNull()) {
        Ogre::ManualObject* object = sceneManager()->createManualObject("ln"+uniqueName());
        object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
        object->position(0,0.5f,0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(0);
        object->position(0,-0.5f,0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(1);
        object->position(0,-0.5f,-0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(2);
        object->position(0,0.5f,0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(3);
        object->position(0,-0.5f,-0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(4);
        object->position(0,0.5f,-0.5f); object->normal(Ogre::Vector3(1,0,0)); object->index(5);
        object->end();
        adornQuadMesh = object->convertToMesh(sceneManager()->getName()+adornMeshSuffix,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
        Ogre::Mesh* mesh=adornQuadMesh.getPointer();
        float radius=mesh->getBoundingSphereRadius();
        Ogre::Sphere parameter(mesh->getBounds().getCenter(),radius,0);
        renderNode->setSphere(reinterpret_cast<unsigned long>(adornQuadMesh->getSubMesh(0)),parameter);
    }
    Ogre::Matrix4 world;
    worldMatrix(world);
    Ogre::Matrix4 local;
    local.makeTransform(center,Ogre::Vector3(1,v2.y-v0.y,v2.z-v0.z),Ogre::Quaternion(1,0,0,0));
    world = world * local;
    drawMesh(adornQuadMesh,world,textureMaterial);
}

}
