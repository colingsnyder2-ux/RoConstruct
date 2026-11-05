// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view-dll roc_espclaude_b47519bdb6ee2bec.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("RenderLib/Material.h", "roc_espeon_materialnativevirtualordere77950369d2e79d9.cpp")
#include "RenderLib/Material.h"
#include "v8datamodel/BrickColor.h"
#include <GLG3D/TextureManager.h>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace exeboost {
inline bool interlocked_bit_test_and_set(long* x, long bit) { return _interlockedbittestandset(x, bit) != 0; }
struct TimedMutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!interlocked_bit_test_and_set(&active_count, 30)) {
                SetEvent(get_event());
            }
        }
    }
};
struct recursive_mutex {
    long recursion_count;
    long locking_thread_id;
    TimedMutex mutex;
    void lock();
    void unlock() {
        if (!--recursion_count) {
            _InterlockedExchange(&locking_thread_id, 0);
            mutex.unlock();
        }
    }
    struct scoped_lock { recursive_mutex* m; bool held; scoped_lock(recursive_mutex& p) : m(&p), held(false) { m->lock(); held = true; } ~scoped_lock() { if (held) m->unlock(); } };
};
}

namespace RBX
{
	namespace View
	{
		class MaterialFactory
		{
			struct Attributes
			{
				const BrickColor color;
				const float transparency;
				const float reflectance;
				const int extra;

				bool operator<(const Attributes&) const;
			};


 struct Cache {
 std::map<Attributes,G3D::WeakReferenceCountedPointer<Render::Material> > database;
 std::map<Attributes,G3D::WeakReferenceCountedPointer<Render::Material> > megaDatabase;
 exeboost::recursive_mutex mutex;
 };
 static Cache* cache;
 static void initializeCache();
		private:
			G3D::ReferenceCountedPointer<Render::TextureProxy> megaTexture;
			G3D::ReferenceCountedPointer<Render::TextureProxy> surfacesTexture;
			G3D::ReferenceCountedPointer<Render::TextureProxy> fileMeshTexture;
			G3D::ReferenceCountedPointer<Render::Material> fileMeshMaterial;



		public:
			G3D::ReferenceCountedPointer<Render::Material> getMegaMaterial(Attributes);
			G3D::ReferenceCountedPointer<Render::Material> getFileMeshMaterial();
			G3D::ReferenceCountedPointer<Render::Material> getMaterial(Attributes attributes);

			MaterialFactory(G3D::TextureManager* textureManager);
		private:
			G3D::ReferenceCountedPointer<Render::TextureProxy> getSurfacesTexture(G3D::Color3 tint);
		};
		
		class MegaTextureProxy : public Render::TextureProxy
		{
			friend class MaterialFactory;

		private:
			float _stripWidth;
		public:
			static const size_t numStrips = 20;

		private:
			MegaTextureProxy(G3D::TextureManager& textureManager, const std::string& file)
				: Render::TextureProxy(textureManager, file, false),
				  _stripWidth(0.0f)
			{
			}
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice*);
		};
	}
}

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
 if (!cache) initializeCache();
 Cache& state=*cache;
 exeboost::recursive_mutex::scoped_lock lock(state.mutex);

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
 if (!cache) initializeCache();
 Cache& state=*cache;
 exeboost::recursive_mutex::scoped_lock lock(state.mutex);

			Attributes filteredAttributes = {BrickColor::defaultColor(), attributes.transparency, attributes.reflectance, 0};

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

