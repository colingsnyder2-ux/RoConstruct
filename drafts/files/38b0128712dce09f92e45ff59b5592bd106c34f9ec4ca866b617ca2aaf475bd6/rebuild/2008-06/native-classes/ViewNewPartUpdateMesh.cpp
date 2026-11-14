// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partsurface-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::Part::updateMesh 004ef930 (inactive; Part vtable 00826f94 slot 10, 2508 bytes, `ret`,
// EH frame 007cace8). Not in any build list. DRAFT, NOT COMPILED: parked on the header gaps listed under BLOCKED.
// Sibling bodies: Decal / Texture::updateMesh in native-classes/ViewNewPartSurfaceUpdate2008.cpp (same size / radius tail).
//
// Evidence (decoded from the 2008-06 bytes; every call below is an original call site):
//   surfaces   six times PartInstance::getSurfaces 00598de0 -> Surfaces::operator[](NormalId 0..5) 005ecc00 ->
//              Surface::getSurfaceType 005f1290, mapped by a 4-entry switch (jump tables 004f0280..004f02d0): SurfaceType
//              1..4 -> RenderSurfaceType 1..4, anything else -> 0; packed three bits per face into one word (masks
//              0xffc7 / 0xfe3f / 0xf1ff / 0x8fff / 0x7fff, shifts 3 / 6 / 9 / 12 / 15; kept at [esp+0x14]).
//   size       PartInstance::getPartSizeXml 00598cd0 copied to a local Vector3.
//   megatex    Part::usesMegaTexture 004e5f80 true:
//              parent = partInstance->getParent() (+0x104); NULL -> plain brick (below).
//              dynamic_cast<ModelInstance*>(parent) (RTTI 00932a40) -> 004e7ff0 (ModelInstance: first IModelModifier in
//              its modifier vector that dynamic_casts to Clothing, RTTI 00936980; analog name findClothing), else NULL;
//              Humanoid::modelIsCharacter 005d9a20 (parent). Both non-NULL, else plain brick.
//              Two ContentId locals (ctor 0043d050): pants [esp+0x54], shirt [esp+0x34]; for each child of parent
//              (children shared_ptr +0x108, vector begin 0068fef0 / end 0068ff20, checked iterators) that dynamic_casts to
//              Clothing: if pants empty (size +0x14) and Clothing outfit1 (+0x134, size at +0x148) non-empty, pants =
//              outfit1 (ContentId::operator= 0043d0a0); same for shirt and outfit2 (+0x154 / +0x168).
//              Character limbs (Humanoid getTorso 005d8b10, getLeftArm 005d8e10, getRightArm 005d8f10, getLeftLeg 005d8c10,
//              getRightLeg 005d8d10): torso needs shirt or pants, arms need shirt, legs need pants; otherwise plain brick.
//              Limb mesh: the 7-argument brick factory 004e54e0 (hidden RCP result, &size, RenderSurfaceTypes 0, BrickColor
//              PartInstance +0x1e4, three table pointers, 0.0063725486f [00826fd8]) with the .data tables
//                torso     00941568 / 00941448 / 009415e0      leftArm   00941598 / 00941448 / 00941610
//                rightArm  00941580 / 00941448 / 009415f8      leftLeg   009415c8 / 00941448 / 00941640
//                rightLeg  009415b0 / 00941448 / 00941628
//              (00941448: six floats 1/3, 0, 1/6, 1/3, 0, 1/3; the others: six ints each, face -> template region).
//              Plain brick: BrickMesh cache create 004e58b0 (hidden RCP result, &size, surfaces, BrickColor +0x1e4).
//   no megatex specialShape (+0xd4) NULL: PartInstance part type (+0x1dc) 0 Sphere 004eea30, 1 PBB 004edb20, 2 Cylinder
//              (along X) 004eef30 = MeshFactory<...>::create(size, surfaces), raw pointer stored with setPointer 00598fa0.
//              specialShape: size.{x,y,z} = scale (+0x134) * size; meshType (+0x130, jump table 004f02e0):
//              0 Head 004ef430, 1 Torso 004ee530, 2 Wedge 004ee030, 3 Sphere 004eea30, 4 Cylinder 004eef30, 6 PBB 004edb20
//              (stored through 004dc4e0), 5 FileMesh::create 00500b90 (ServiceProvider::create<ContentProvider> 00465210
//              (partInstance), size, getMeshId 004e5f20).
//   tail       radius (Chunk +0x1c) = sqrt(2.0 [00826fd0]) * max(|x|, |y|, |z|) * 0.5f [00819bac] (as in Decal::updateMesh).
//
// BLOCKED (header proposals reported in the batch result; this file is a reconstruction draft, not a proof):
//   1. ViewNew/QuadVolume.h RenderSurfaceTypes has only `data`: needs the donor setSurfaceType(NormalId, RenderSurfaceType)
//      (inline, 3-bit fields) and the RenderSurfaceType enum (donor tools/rbxgs RbxView/QuadVolume.h).
//   2. The limb factory 004e54e0 is only an INFERRED free function in ViewNewBrickCacheRecovery2008.cpp
//      (createSpecialBrick with int arguments); its owner must declare it with the table pointer types, and the five
//      .data tables 00941448..00941640 need declarations (owner unit unknown).
//   3. v8datamodel/ModelInstance.h: the Clothing modifier finder 004e7ff0 (template or member; analog name).
//   4. v8datamodel/Clothing.h: outfit1 / outfit2 are protected; the bytes read them inline from this unit, so a public
//      inline accessor (or friend) is needed.
//   5. A Humanoid header that shares a unit with the part-embedded PartInstance.h (Humanoid2008.h with
//      NATIVE_HUMANOID2008_DONOR_CONNECTOR, as Humanoid2008Parts.cpp does) - not yet tried here.
// Placeholder names used below until the proposals land (none is an original name): RenderSurfaceType / setSurfaceType
// (donor names), ModelInstance::findClothing (004e7ff0), Clothing::getOutfit1 / getOutfit2 (+0x134 / +0x154),
// BrickMesh::createCharacter (004e54e0) and the table names torsoFaces .. rightLegTemplate / characterRegions
// (00941448..00941640).
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "ViewNew/PartChunk.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/SpecialShape.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Clothing.h"
#include "humanoid/Humanoid2008.h"
#include "ViewNew/SphereMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/TorsoMesh.h"
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/BrickMesh.h"
#include "ViewNew/FileMesh.h"
#include <cmath>

namespace RBX
{
	namespace ViewNew
	{
		// INFERRED: SurfaceType -> RenderSurfaceType switch inlined six times (jump tables 004f0280..004f02d0).
		static inline RenderSurfaceType toRenderSurfaceType(SurfaceType surfaceType)
		{
			switch (surfaceType)
			{
			case 1: return STUDS;
			case 2: return INLET;
			case 3: return WELD;
			case 4: return GLUE;
			default: return FLAT;
			}
		}

		static inline float maxf(float a, float b)
		{
			return a > b ? a : b;
		}

		// 004ef930
		void Part::updateMesh()
		{
			RenderSurfaceTypes surfaces;
			for (int face = 0; face < 6; ++face)   // unrolled in the bytes (NormalId 0..5)
				surfaces.setSurfaceType((NormalId)face, toRenderSurfaceType(partInstance->getSurfaces()[(NormalId)face].getSurfaceType()));

			G3D::Vector3 size = partInstance->getPartSizeXml();

			if (usesMegaTexture())
			{
				Instance* parent = partInstance->getParent();
				Clothing* clothing = NULL;
				Humanoid* humanoid = NULL;
				if (parent)
				{
					ModelInstance* model = dynamic_cast<ModelInstance*>(parent);
					clothing = model ? model->findClothing() : NULL;      // 004e7ff0 (analog name)
					humanoid = Humanoid::modelIsCharacter(parent);
				}
				if (parent && clothing && humanoid)
				{
					ContentId pants;
					ContentId shirt;
					if (const Instances* children = parent->getChildren())
					{
						for (Instances::const_iterator it = children->begin(); it != children->end(); ++it)
						{
							if (Clothing* c = dynamic_cast<Clothing*>(it->get()))
							{
								if (pants.isNull() && !c->getOutfit1().isNull())
									pants = c->getOutfit1();
								if (shirt.isNull() && !c->getOutfit2().isNull())
									shirt = c->getOutfit2();
							}
						}
					}

					PartInstance* part = partInstance.get();
					bool special =
						(part == humanoid->getTorso() && (!pants.isNull() || !shirt.isNull())) ||
						(part == humanoid->getLeftArm() && !shirt.isNull()) ||
						(part == humanoid->getRightArm() && !shirt.isNull()) ||
						(part == humanoid->getLeftLeg() && !pants.isNull()) ||
						(part == humanoid->getRightLeg() && !pants.isNull());
					if (special)
					{
						const float scale = 0.0063725486f;   // 00826fd8
						if (part == humanoid->getTorso())
							mesh = BrickMesh::createCharacter(size, RenderSurfaceTypes(), partInstance->getColor(), torsoFaces, characterRegions, torsoTemplate, scale);
						else if (part == humanoid->getLeftArm())
							mesh = BrickMesh::createCharacter(size, RenderSurfaceTypes(), partInstance->getColor(), leftArmFaces, characterRegions, leftArmTemplate, scale);
						else if (part == humanoid->getRightArm())
							mesh = BrickMesh::createCharacter(size, RenderSurfaceTypes(), partInstance->getColor(), rightArmFaces, characterRegions, rightArmTemplate, scale);
						else if (part == humanoid->getLeftLeg())
							mesh = BrickMesh::createCharacter(size, RenderSurfaceTypes(), partInstance->getColor(), leftLegFaces, characterRegions, leftLegTemplate, scale);
						else if (part == humanoid->getRightLeg())
							mesh = BrickMesh::createCharacter(size, RenderSurfaceTypes(), partInstance->getColor(), rightLegFaces, characterRegions, rightLegTemplate, scale);
					}
					else
					{
						mesh = BrickMesh::create(size, surfaces, partInstance->getColor());
					}
				}
				else
				{
					mesh = BrickMesh::create(size, surfaces, partInstance->getColor());
				}
			}
			else if (!specialShape)
			{
				switch (partInstance->getPartType())
				{
				case 0: mesh = SphereMesh::create(size, surfaces); break;
				case 1: mesh = PBBMesh::create(size, surfaces); break;
				case 2: mesh = CylinderAlongXMesh::create(size, surfaces); break;
				}
			}
			else
			{
				const G3D::Vector3& scale = specialShape->getScale();
				size.x = scale.x * size.x;
				size.y = scale.y * size.y;
				size.z = scale.z * size.z;
				switch (specialShape->getMeshType())
				{
				case 2: mesh = WedgeMesh::create(size, surfaces); break;
				case 0: mesh = HeadMesh::create(size, surfaces); break;
				case 1: mesh = TorsoMesh::create(size, surfaces); break;
				case 3: mesh = SphereMesh::create(size, surfaces); break;
				case 4: mesh = CylinderAlongXMesh::create(size, surfaces); break;
				case 6: mesh = PBBMesh::create(size, surfaces); break;
				case 5: mesh = FileMesh::create(ServiceProvider::create<ContentProvider>(partInstance.get()), size, specialShape->getMeshId()); break;
				}
			}

			float s2 = (float)sqrt(2.0);
			float ax = fabs(size.x), ay = fabs(size.y), az = fabs(size.z);
			radius = s2 * maxf(maxf(ax, ay), az) * 0.5f;
		}
	}
}
