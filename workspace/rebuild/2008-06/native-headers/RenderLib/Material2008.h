#pragma once
// RBX::RenderBase::MaterialBase, RBX::Render::Material and RBX::RenderNew::Material (with their Level classes) as
// compiled into the June 2008 client (inactive native recovery).
//
// Non-colliding name: units include the donor RenderLib/Material.h at its original path (a single, non-virtual
// Render::Material), so the 2008 interface is declared here and only included by the native RenderMaterial units. The
// RenderNew level needs the Ogre 1.4.5 client headers (MaterialPtr constructors / destructor are rgmain.dll imports).
//
// Evidence (original Roblox.exe):
//   * RTTI: Render::Material 00875bc4 / RenderNew::Material 00874ac0 -> RenderBase::MaterialBase -> G3D::
//     ReferenceCountedObject; Render::Material::Level 00875be8 / RenderNew::Material::Level 00874ae4 ->
//     RenderBase::MaterialBase::Level (vtable 00874a8c, 12 slots).
//   * MaterialBase has no vtable in the image and its constructor stores none (Material() 007ad960 / 007b80a0 store the
//     ReferenceCountedObject vptr 0081e1e0, then the Material vptr): __declspec(novtable), interface only.
//   * MaterialBase::Level: vtable 00874a8c; every slot but the destructor (slot 1, ??_G 007acd00; the inline destructor
//     007accc0 only stores the vptr) and setBaseTexture (slot 4, 007ad060) is 007accd0, which throws the string literal
//     "shouldn't be here" (0082743c) as const char* (throw info 0090e47c); 007ad060 is the same throw with the
//     by-value reference parameter's unwind state.
//   * Material layout: G3D::Array<Level> at +0x0c (data +0x0c, num +0x10, numAllocated +0x14; Material() zeroes them).
//   * Level layout (RenderNew stride 0x38: getLevel 007acdb0, the Array members 007acd20 / 007acf70 / 007ad4b0;
//     Render stride 0x2c: 007b7590 / 007b7540): +0x04 emptyLevel (Level() 007ad1a0 stores 1, Level(texture, ...)
//     007ad230 stores 0), +0x08 matte reference, +0x0c base-texture reference, +0x10 Color3 (Level(): Color3::white()
//     00514a60), +0x1c specular, +0x20 shiny, +0x24 reflect, +0x28 transparent (constructor argument order of 007ad230;
//     accessor slots 7..10 read +0x1c / +0x20 / +0x24 / +0x28; veryTransparent 007acd70 compares +0x28 with 0.25f);
//     RenderNew adds Ogre::MaterialPtr at +0x2c (MaterialPtr(Material*) / copy / operator= / ~MaterialPtr imports).
//   * Level vtable slots: 0 isEmptyLevel, 1 dtor, 2 baseTexture(RenderDevice*), 3 baseTexture(), 4 setBaseTexture,
//     5 matte, 6 color, 7 specular, 8 shiny, 9 reflect, 10 transparent, 11 configureRenderDevice (Render::Material::
//     Level only, 007b7b10). The overloads are declared in reverse slot order: MSVC places overloaded virtuals in
//     reverse declaration order (checked against 00874ae4 / 00875be8 by the recorder).
//   * Material vtable slots: 0 ??_G, 1 appendEmptyLevel, 2 appendLevel(Color3, ...), 3 appendLevel(texture, Color3,
//     ...), 4 levelCount, 5 getLevel, 6 detailLevel, 7 veryTransparent.
//   * The RenderNew level destructor 007ad310 removes the Ogre material when set: MaterialManager::getSingleton().
//     remove(handle) and LogManager::logMessage("RBX removed " + name).
#include <string>
#include <G3D/Array.h>
#include <G3D/Color3.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Texture.h>
#include "RbxGraphics/TextureProxyBase2008.h"
#include <OgreMaterial.h>

struct NativeRenderMaterialLayout;

namespace RBX
{
	namespace RenderBase
	{
		class __declspec(novtable) MaterialBase : public G3D::ReferenceCountedObject
		{
		public:
			class Level
			{
			public:
				Level()
				{
				}
				virtual bool isEmptyLevel() const                                            // slot 0
				{
					throw "shouldn't be here";
				}
				virtual ~Level()                                                             // slot 1
				{
				}
				virtual TextureProxyBaseRef baseTexture() const                              // slot 3
				{
					throw "shouldn't be here";
				}
				virtual G3D::ReferenceCountedPointer<G3D::Texture> baseTexture(G3D::RenderDevice* rd) const   // slot 2
				{
					throw "shouldn't be here";
				}
				virtual void setBaseTexture(TextureProxyBaseRef texture)                     // slot 4
				{
					throw "shouldn't be here";
				}
				virtual G3D::ReferenceCountedPointer<G3D::Texture> matte(G3D::RenderDevice* rd) const         // slot 5
				{
					throw "shouldn't be here";
				}
				virtual const G3D::Color3& color() const                                     // slot 6
				{
					throw "shouldn't be here";
				}
				virtual float specular() const                                               // slot 7
				{
					throw "shouldn't be here";
				}
				virtual float shiny() const                                                  // slot 8
				{
					throw "shouldn't be here";
				}
				virtual float reflect() const                                                // slot 9
				{
					throw "shouldn't be here";
				}
				virtual float transparent() const                                            // slot 10
				{
					throw "shouldn't be here";
				}
				virtual void configureRenderDevice(G3D::RenderDevice* rd) const             // slot 11
				{
					throw "shouldn't be here";
				}
			};

		public:
			virtual ~MaterialBase()
			{
			}
			virtual const Level& appendEmptyLevel() = 0;                                     // slot 1
			virtual const Level& appendLevel(TextureProxyBaseRef baseTexture, G3D::Color3 color, float specular,
			                                 float shiny, float reflect, float transparent) = 0;   // slot 3
			virtual const Level& appendLevel(G3D::Color3 color, float specular, float shiny, float reflect,
			                                 float transparent) = 0;                         // slot 2
			virtual size_t levelCount() const = 0;                                           // slot 4
			virtual Level& getLevel(int index) = 0;                                          // slot 5
			virtual const Level* detailLevel(float lvl) const = 0;                           // slot 6
			virtual bool veryTransparent() const = 0;                                        // slot 7
		};
	}

	namespace Render
	{
		class Material : public RenderBase::MaterialBase
		{
			friend struct ::NativeRenderMaterialLayout;

		public:
			class Level : public RenderBase::MaterialBase::Level
			{
				friend class Material;
				friend struct ::NativeRenderMaterialLayout;

			private:
				bool emptyLevel;                                                         // +0x04
				TextureProxyBaseRef mMatte;                                              // +0x08
				TextureProxyBaseRef mBaseTexture;                                        // +0x0c
				G3D::Color3 mColor;                                                      // +0x10
				float mSpecular;                                                         // +0x1c
				float mShiny;                                                            // +0x20
				float mReflect;                                                          // +0x24
				float mTransparent;                                                      // +0x28 (size 0x2c)

			public:
				Level();                                                                 // 007b7840
				Level(TextureProxyBaseRef baseTexture, G3D::Color3 color, float specular, float shiny, float reflect,
				      float transparent);                                                // 007b78b0
				~Level();                                                                // 007b7a60

				virtual bool isEmptyLevel() const;
				virtual TextureProxyBaseRef baseTexture() const;
				virtual G3D::ReferenceCountedPointer<G3D::Texture> baseTexture(G3D::RenderDevice* rd) const;
				virtual void setBaseTexture(TextureProxyBaseRef texture);
				virtual G3D::ReferenceCountedPointer<G3D::Texture> matte(G3D::RenderDevice* rd) const;
				virtual const G3D::Color3& color() const;
				virtual float specular() const;
				virtual float shiny() const;
				virtual float reflect() const;
				virtual float transparent() const;
				virtual void configureRenderDevice(G3D::RenderDevice* rd) const;        // 007b7b10
			};

		private:
			G3D::Array<Level> levels;                                                    // +0x0c (size 0x18)

		public:
			Material();                                                                  // 007b80a0
			virtual ~Material();
			virtual const RenderBase::MaterialBase::Level& appendEmptyLevel();
			virtual const RenderBase::MaterialBase::Level& appendLevel(TextureProxyBaseRef baseTexture,
				G3D::Color3 color, float specular, float shiny, float reflect, float transparent);
			virtual const RenderBase::MaterialBase::Level& appendLevel(G3D::Color3 color, float specular, float shiny,
				float reflect, float transparent);
			virtual size_t levelCount() const;
			virtual RenderBase::MaterialBase::Level& getLevel(int index);
			virtual const RenderBase::MaterialBase::Level* detailLevel(float lvl) const;
			virtual bool veryTransparent() const;
		};
	}

	namespace RenderNew
	{
		class Material : public RenderBase::MaterialBase
		{
			friend struct ::NativeRenderMaterialLayout;

		public:
			class Level : public RenderBase::MaterialBase::Level
			{
				friend class Material;
				friend struct ::NativeRenderMaterialLayout;

			private:
				bool emptyLevel;                                                         // +0x04
				TextureProxyBaseRef mMatte;                                              // +0x08
				TextureProxyBaseRef mBaseTexture;                                        // +0x0c
				G3D::Color3 mColor;                                                      // +0x10
				float mSpecular;                                                         // +0x1c
				float mShiny;                                                            // +0x20
				float mReflect;                                                          // +0x24
				float mTransparent;                                                      // +0x28
				Ogre::MaterialPtr ogreMaterial;                                          // +0x2c (size 0x38)

			public:
				Level();                                                                 // 007ad1a0
				Level(TextureProxyBaseRef baseTexture, G3D::Color3 color, float specular, float shiny, float reflect,
				      float transparent);                                                // 007ad230
				~Level();                                                                // 007ad310

				virtual bool isEmptyLevel() const;
				virtual TextureProxyBaseRef baseTexture() const;
				virtual G3D::ReferenceCountedPointer<G3D::Texture> baseTexture(G3D::RenderDevice* rd) const;
				virtual void setBaseTexture(TextureProxyBaseRef texture);
				virtual G3D::ReferenceCountedPointer<G3D::Texture> matte(G3D::RenderDevice* rd) const;
				virtual const G3D::Color3& color() const;
				virtual float specular() const;
				virtual float shiny() const;
				virtual float reflect() const;
				virtual float transparent() const;
			};

		private:
			G3D::Array<Level> levels;                                                    // +0x0c (size 0x18)

		public:
			Material();                                                                  // 007ad960
			virtual ~Material();
			virtual const RenderBase::MaterialBase::Level& appendEmptyLevel();
			virtual const RenderBase::MaterialBase::Level& appendLevel(TextureProxyBaseRef baseTexture,
				G3D::Color3 color, float specular, float shiny, float reflect, float transparent);
			virtual const RenderBase::MaterialBase::Level& appendLevel(G3D::Color3 color, float specular, float shiny,
				float reflect, float transparent);
			virtual size_t levelCount() const;
			virtual RenderBase::MaterialBase::Level& getLevel(int index);
			virtual const RenderBase::MaterialBase::Level* detailLevel(float lvl) const;
			virtual bool veryTransparent() const;
		};
	}
}
