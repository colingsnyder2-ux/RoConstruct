#pragma once
// 2008-06 native RBX::RenderBase::Chunk / AggregateChunk (inactive). Named *2008.h so it never shadows the donor
// RenderLib/Chunk.h (a later source base whose Chunk lives in RBX::Render and has a different layout).
//   Chunk          no RTTI vtable of its own: the constructor 004e8160 stores only the ReferenceCountedObject vtable
//                  0081e1e0 (__declspec(novtable), as in the donor). Base G3D::ReferenceCountedObject (+0x0..+0xb).
//                  ctor 004e8160 (out of line; thiscall, one float): +0xc / +0x10 = NULL, +0x14 = 0.0f,
//                  +0x18 = polygonOffset, +0x1c = G3D::inf() (static double 0096f018 / guard 0096f020),
//                  +0x20 WeakReferenceCountedPointer<AggregateChunk> (vtable 00826ea0, pointer +0x24 = NULL),
//                  RenderStats::chunkCount (0097288c) += 1.
//                  dtor 004e81d0: chunkCount -= 1; if (+0x10) (+0xc)->removeSubEntity(+0x10) (Ogre::RbxEntity
//                  unit, 0067d2d0: erases the pointer from a std::vector and deletes it through its virtual dtor).
//                  size 0x28 (AggregateChunk's first own member is +0x28).
//                  Virtual slots (AggregateChunk vtable 0082d258): 0 ~Chunk, 1 cachesShadows, 2 renderShadows
//                  (ret 0x10), 3 castsShadows, 4 cullable, 5 getMaterial, 6 getMesh, 7 cframe, 8 / 9 the
//                  +0x14 float setter / getter (004e5b60 / 004e5b70, header-inline O2 bodies; names not proven).
//   AggregateChunk RTTI 0082d258 -> Chunk -> ReferenceCountedObject (all mdisp 0). new 0x108 (0053ffc3 before the
//                  ctor 00551f30, /Od). ctor stores: material +0x28, mesh +0x2c (RCP ctors 004f0810),
//                  _cframe +0x30 (CoordinateFrame ctor 004782d0), _castsShadows +0x60 / _cullable +0x61 (slots 3 / 4
//                  of the first chunk), shadowSource +0x68 (GLight ctor 00514390; doubles -> 8-aligned),
//                  shadowVAR +0xb8 (VAR ctor 00489470), shadowIndexArray +0xd8 (Array ctor 00481520),
//                  shadowIndexArray16 +0xe4 (005527f0), components +0xf0 (std::vector ctor 00540560).
//                  dtor 00552160 destroys them in reverse order. Element types of the arrays follow the donor.
#include <G3D/ReferenceCount.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/GLight.h>
#include <G3D/Array.h>
#include <GLG3D/VAR.h>
#include "ViewNew/RenderBaseMesh.h"
#include "RenderLib/RenderStats.h"     // donor: RenderStats::chunkCount (0097288c) and the aggregate counters
#include <vector>

struct NativeRenderSceneLayout;

namespace G3D
{
	class RenderDevice;
}

namespace Ogre
{
	class RbxSubEntity; // incomplete: only owned through a pointer
	class RbxEntity     // exe-local Ogre::Entity subclass (RTTI .?AVRbxEntity@Ogre@@); only the call used here
	{
	public:
		void removeSubEntity(RbxSubEntity* subEntity); // 0067d2d0
	};
}

namespace RBX
{
	namespace RenderBase
	{
		class AggregateChunk;
		class MaterialBase; // RTTI .?AVMaterialBase@RenderBase@RBX@@; declared by the material owner (RenderLib/Material2008.h)

		// 00551730: new RenderNew::Material (0x18, ctor 007ad960) when the render-mode global 00942ec4 is 0, new
		// Render::Material (0x18, ctor 007b80a0) when it is 1, else throws std::exception; returns the raw pointer in eax
		// (cdecl, no arguments). Called by the AggregateChunk ctor 005520b5 and the ViewNew part chunks. The name is the
		// donor's analog, not proven by the image; the body is not recovered (the global is unnamed).
		MaterialBase* createMaterial();

		class __declspec(novtable) Chunk : public G3D::ReferenceCountedObject
		{
			friend struct ::NativeRenderSceneLayout;
		public:
			Ogre::RbxEntity* entity;                                  // +0x0c
			Ogre::RbxSubEntity* subEntity;                            // +0x10
		protected:
			float sortValue;                                          // +0x14 (0.0f; slots 8 / 9)
		public:
			const float polygonOffset;                                // +0x18
			float radius;                                             // +0x1c
			G3D::WeakReferenceCountedPointer<AggregateChunk> aggregate; // +0x20

		public:
			virtual ~Chunk();                                         // 004e81d0
			virtual bool cachesShadows() const
			{
				return false;
			}
			virtual void renderShadows(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance)
			{
			}
			virtual bool castsShadows() const = 0;
			virtual bool cullable() const = 0;
			virtual G3D::ReferenceCountedPointer<MaterialBase> getMaterial() = 0;
			virtual G3D::ReferenceCountedPointer<Mesh> getMesh() = 0;
			virtual const G3D::CoordinateFrame& cframe() = 0;
			virtual void setSortValue(float value);                   // 004e5b60
			virtual float getSortValue() const;                       // 004e5b70

			// SimpleSceneManager::invalidateModel 004d7320 (inlined there)
			void releaseEntity()
			{
				if (subEntity)
					entity->removeSubEntity(subEntity);
				subEntity = NULL;
				entity = NULL;
			}

			Chunk(float polygonOffset);                               // 004e8160
		};

		class AggregateChunk : public Chunk
		{
			friend struct ::NativeRenderSceneLayout;
		private:
			G3D::ReferenceCountedPointer<MaterialBase> material;         // +0x28
			G3D::ReferenceCountedPointer<Mesh> mesh;                 // +0x2c
			G3D::CoordinateFrame _cframe;                            // +0x30
			bool _castsShadows;                                      // +0x60
			bool _cullable;                                          // +0x61
			G3D::GLight shadowSource;                                // +0x68
			G3D::VAR shadowVAR;                                      // +0xb8
			G3D::Array<unsigned int> shadowIndexArray;               // +0xd8
			G3D::Array<unsigned short> shadowIndexArray16;           // +0xe4
		public:
			std::vector<G3D::ReferenceCountedPointer<Chunk> > components; // +0xf0
			static bool randomColors;                                // 009738a0 (read by the ctor 0055203b / 005520a6)

		public:
			virtual ~AggregateChunk();                               // 00552160
			virtual bool cachesShadows() const;                      // 005526d0
			virtual void renderShadows(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance); // 00552300
			virtual bool castsShadows() const;                       // 00552690
			virtual bool cullable() const;                           // 005526b0
			virtual G3D::ReferenceCountedPointer<MaterialBase> getMaterial(); // 005526e0
			virtual G3D::ReferenceCountedPointer<Mesh> getMesh();    // 00552720
			virtual const G3D::CoordinateFrame& cframe();            // 00552760

			AggregateChunk(const G3D::ReferenceCountedPointer<Chunk>& firstChunk); // 00551f30
		};
	}
}
