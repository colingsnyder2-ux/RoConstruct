// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// RBX::RenderNew::Material / Material::Level with the RenderBase::MaterialBase::Level defaults, optimized RenderLib unit
// (2008-06, inactive native recovery). Image block 007accc0..007ad9cf.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// RenderMaterialNew | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 37cb3a93 | roc native-status --write
#include "RenderLib/Material2008.h"
#include <OgreMaterialManager.h>
#include <OgreLogManager.h>

namespace RBX
{
	namespace RenderNew
	{
		size_t Material::levelCount() const
		{
			return levels.size();
		}

		RenderBase::MaterialBase::Level& Material::getLevel(int index)
		{
			return levels[index];
		}

		const RenderBase::MaterialBase::Level* Material::detailLevel(float lvl) const
		{
			if (levelCount() == 0)
			{
				return NULL;
			}
			else
			{
				int sizeMinusOne = levels.size() - 1;
				int level = lvl * levels.size();

				if (level <= 0)
					level = 0;
				else if (level >= sizeMinusOne)
					level = sizeMinusOne;

				const Level& detail = levels[level];
				return detail.isEmptyLevel() ? NULL : &detail;
			}
		}

		bool Material::veryTransparent() const
		{
			return levels.size() > 0 && levels[0].mTransparent > 0.25f;
		}

		bool Material::Level::isEmptyLevel() const
		{
			return emptyLevel;
		}

		// The accessors below compile to the same bytes as the Render::Material::Level ones and are folded with them
		// in the image (007b7810 / 007b76a0 / 007b76b0 / 007b76c0 / 00503cb0 / 007b76d0).
		TextureProxyBaseRef Material::Level::baseTexture() const
		{
			return mBaseTexture;
		}

		const G3D::Color3& Material::Level::color() const
		{
			return mColor;
		}

		float Material::Level::specular() const
		{
			return mSpecular;
		}

		float Material::Level::shiny() const
		{
			return mShiny;
		}

		float Material::Level::reflect() const
		{
			return mReflect;
		}

		float Material::Level::transparent() const
		{
			return mTransparent;
		}

		G3D::ReferenceCountedPointer<G3D::Texture> Material::Level::baseTexture(G3D::RenderDevice* rd) const
		{
			if (mBaseTexture.isNull())
				return NULL;
			else
				return mBaseTexture->resolve(rd);
		}

		void Material::Level::setBaseTexture(TextureProxyBaseRef texture)
		{
			mBaseTexture = texture;
		}

		G3D::ReferenceCountedPointer<G3D::Texture> Material::Level::matte(G3D::RenderDevice* rd) const
		{
			if (mMatte.isNull())
				return NULL;
			else
				return mMatte->resolve(rd);
		}

		Material::Level::Level()
			: emptyLevel(true),
			  mColor(G3D::Color3::white()),
			  mSpecular(0.0f),
			  mShiny(0.0f),
			  mReflect(0.0f),
			  mTransparent(0.0f),
			  ogreMaterial(NULL)
		{
		}

		Material::Level::Level(TextureProxyBaseRef baseTexture, G3D::Color3 color, float specular, float shiny,
		                       float reflect, float transparent)
			: emptyLevel(false),
			  mBaseTexture(baseTexture),
			  mColor(color),
			  mSpecular(specular),
			  mShiny(shiny),
			  mReflect(reflect),
			  mTransparent(transparent),
			  ogreMaterial(NULL)
		{
		}

		Material::Level::~Level()
		{
			if (!ogreMaterial.isNull())
			{
				std::string name = ogreMaterial->getName();
				Ogre::MaterialManager::getSingleton().remove(ogreMaterial->getHandle());
				Ogre::LogManager::getSingleton().logMessage("RBX removed " + name);
			}
		}

		Material::Material()
		{
		}

		Material::~Material()
		{
		}

		const RenderBase::MaterialBase::Level& Material::appendEmptyLevel()
		{
			return levels.next();
		}

		const RenderBase::MaterialBase::Level& Material::appendLevel(TextureProxyBaseRef baseTexture, G3D::Color3 color,
			float specular, float shiny, float reflect, float transparent)
		{
			levels.append(Level(baseTexture, color, specular, shiny, reflect, transparent));
			return levels.last();
		}

		const RenderBase::MaterialBase::Level& Material::appendLevel(G3D::Color3 color, float specular, float shiny,
			float reflect, float transparent)
		{
			levels.append(Level(NULL, color, specular, shiny, reflect, transparent));
			return levels.last();
		}
	}
}
