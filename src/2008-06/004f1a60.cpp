// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view-dll roc_espeon_materialnativefiltered898f72142e782492.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("RenderLib/Material.h", "roc_espeon_materialnativevirtualordere77950369d2e79d9.cpp")
#pragma include_alias("MaterialFactory.h", "roc_espeon_materialnativecacheheader1b7150d0eb74ebde.cpp")
#include "MaterialFactory.h"
#include "util/ContentProvider.h"

namespace RBX { namespace Render { Material* createMaterial(); } }
static const float specular = 0.9f;
static const float shiny = 50.0f;

namespace RBX
{
	namespace View
	{
		MaterialFactory::MaterialFactory(G3D::TextureManager* textureManager)
		{
			surfacesTexture = new Render::TextureProxy(*textureManager, ContentProvider::singleton().getAssetFile("textures\\surfaces.png"), true);
			fileMeshTexture = new Render::TextureProxy(*textureManager, ContentProvider::singleton().getAssetFile("textures\\JohnTex.png"), false);
			megaTexture = new MegaTextureProxy(*textureManager, ContentProvider::singleton().getAssetFile("textures\\SurfacesStrip.png"));
		}

		G3D::ReferenceCountedPointer<Render::Material> MaterialFactory::getMaterial(Attributes attributes)
		{
 boost::call_once(&initializeCache,once);
 Cache& state=*cache;
 boost::recursive_mutex::scoped_lock lock(state.mutex);

			G3D::ReferenceCountedPointer<Render::Material> material;

			std::map<Attributes, G3D::WeakReferenceCountedPointer<Render::Material>>::iterator iter = state.database.find(attributes);
			if (iter != state.database.end())
			{
				material = iter->second.createStrongPtr();
			}

			if (material.isNull())
			{
				G3D::Color3 color3 = attributes.color.color3();
				G3D::ReferenceCountedPointer<Render::TextureProxy> surfacesTexture = getSurfacesTexture(color3);

				material = Render::createMaterial();
				if (attributes.transparency == 1.0f)
				{
					material->appendEmptyLevel();
				}
				else
				{
					material->appendLevel(surfacesTexture, G3D::Color3::WHITE, specular, shiny, attributes.reflectance, attributes.transparency);
				}

				state.database[attributes] = material;
			}

			return material;
		}

		G3D::ReferenceCountedPointer<Render::Material> MaterialFactory::getMegaMaterial(Attributes attributes)
		{
 boost::call_once(&initializeCache,once);
 Cache& state=*cache;
 boost::recursive_mutex::scoped_lock lock(state.mutex);

			Attributes filteredAttributes = {BrickColor::defaultColor(), attributes.transparency, attributes.reflectance};

			G3D::ReferenceCountedPointer<Render::Material> material;

			std::map<Attributes, G3D::WeakReferenceCountedPointer<Render::Material>>::iterator iter = state.megaDatabase.find(filteredAttributes);
			if (iter != state.megaDatabase.end())
			{
				material = iter->second.createStrongPtr();
			}

			if (material.isNull())
			{
				material = Render::createMaterial();
				if (filteredAttributes.transparency == 1.0f)
				{
					material->appendEmptyLevel();
				}
				else
				{
					material->appendLevel(megaTexture, G3D::Color3::white(), specular, shiny, filteredAttributes.reflectance, filteredAttributes.transparency);
				}

				state.megaDatabase[filteredAttributes] = material;
			}

			return material;
		}

		G3D::ReferenceCountedPointer<Render::TextureProxy> MaterialFactory::getSurfacesTexture(G3D::Color3 tint)
		{
			return surfacesTexture->shade(tint, NULL);
		}
	}
}

namespace G3D { const Color3 Color3::WHITE(1,1,1); }
