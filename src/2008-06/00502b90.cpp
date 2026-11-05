// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_reflectiondoubleoffset683f3a95a11fcdc0.cpp

// Candidate translation unit (score above; library headers required).

#include <GLG3D/RenderDevice.h>
#include <GLG3D/LightingParameters.h>
#include <GLG3D/GLCaps.h>
#include <G3D/Array.h>
namespace RBX { namespace Render {
// Virtual call slots observed in 00502b90; matching 2008 material interface.
class Material2008 {public:
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();
 virtual G3D::ReferenceCountedPointer<G3D::Texture> matte(G3D::RenderDevice*)const;
 virtual void slot6();virtual void slot7();virtual void slot8();virtual float reflect()const;
};
struct MeshLevel;
struct RenderSurface2008 {
 G3D::CoordinateFrame cframe; float z; const Material2008* material;float polygonOffset;const MeshLevel*mesh;
};
struct Mesh2008 {static void sendGeometry(const MeshLevel*,G3D::RenderDevice*);};
class RenderScene2008 {public:
 // Target accesses reflect array at280 and lighting at2ec.
 char prefix[0x280];G3D::Array<RenderSurface2008*> reflectProxyArray;char beforeLighting[0x60];G3D::ReferenceCountedPointer<G3D::Lighting> lighting;
 void reflectionPass(G3D::RenderDevice*);
};
		void RenderScene2008::reflectionPass(G3D::RenderDevice* rd)
		{
			if (G3D::GLCaps::supports_GL_EXT_texture_cube_map() && lighting->environmentMap.notNull() && 
				(lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP || 
				lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP_NPOT))
			{
				rd->pushState();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
				rd->setPolygonOffset(-0.2);
				rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLENDEQ_ADD);
				rd->disableLighting();
				rd->configureReflectionMap(1, lighting->environmentMap);
				rd->disableDepthWrite();

				for (int i = 0; i < reflectProxyArray.size(); i++)
				{
					RenderSurface2008* current = reflectProxyArray[i];
					const Material2008* level = current->material;

					rd->setPolygonOffset(current->polygonOffset);
					rd->setObjectToWorldMatrix(current->cframe);
					rd->setTexture(0, level->matte(rd));
					rd->setColor(G3D::Color4(G3D::Color3::white() * level->reflect()));
					Mesh2008::sendGeometry(current->mesh, rd);
				}

				rd->popState();
			}
		}

}}
