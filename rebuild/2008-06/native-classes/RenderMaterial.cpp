// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// RBX::Render::Material / Material::Level, optimized RenderLib unit (2008-06, inactive native recovery). Image block
// 007b7540..007b80ef. Several bodies compile to the same bytes as the RenderNew ones and are folded with them in the
// image (levelCount 007acda0, veryTransparent 007acd70, isEmptyLevel 007acef0, baseTexture(rd) 007ad0a0,
// setBaseTexture 007ad0e0, matte 007ad160); the accessor bodies of this unit (007b76a0..007b76d0, 007b7810, and the
// shared 00503cb0) are the ones RenderNew::Material::Level folds onto.
// >>> native-status (generated) -- do not edit >>>
// RenderMaterial | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f583785a | roc native-status --write
#include "RenderLib/Material2008.h"
#include "RenderLib/TextureProxy2008.h"

namespace RBX
{
	namespace Render
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
			  mTransparent(0.0f)
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
			  mTransparent(transparent)
		{
			if (baseTexture.notNull())
				mMatte = dynamic_cast<TextureProxy*>(baseTexture.getPointer())->alphaOnlyVersion();
			if (mTransparent > 0.0f)
				mReflect = 0.0f;
		}

		Material::Level::~Level()
		{
		}

		void Material::Level::configureRenderDevice(G3D::RenderDevice* rd) const
		{
			rd->setColor(color());
			rd->setSpecularCoefficient(specular());
			rd->setShininess(shiny());
			rd->setTexture(0, baseTexture(rd));
			if (mBaseTexture.notNull())
			{
				switch (mBaseTexture->getIntProperty())
				{
				case 0:
					rd->setTextureCombineMode(0, G3D::RenderDevice::TEX_INTERPOLATE);
					break;
				case 1:
					rd->setTextureCombineMode(0, G3D::RenderDevice::TEX_MODULATE);
					break;
				case 2:
					rd->setTextureCombineMode(0, G3D::RenderDevice::TEX_REPLACE);
					break;
				default:
					rd->setTextureCombineMode(0, G3D::RenderDevice::TEX_MODULATE);
					break;
				}
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
