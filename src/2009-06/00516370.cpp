// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view-dll roc_espclaude_78b0363e33271e0d.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("RenderLib/Material.h", "roc_espeon_materialnativevirtualordere77950369d2e79d9.cpp")

#include "RenderLib/Material.h"
#include "v8datamodel/BrickColor.h"
#include <GLG3D/TextureManager.h>
#include <boost/thread/once.hpp>
#include <boost/thread/recursive_mutex.hpp>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedExchange(volatile long*, long);
#pragma intrinsic(_InterlockedExchange)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace ExeBoost {
struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, 0x80000000);
        if (!(old_count & 0x40000000) && (old_count > offset))
        {
            if (!(_interlockedbittestandset(&active_count, 30) != 0))
                SetEvent(get_event());
        }
    }
};
struct recursive_mutex {
    long recursion_count;
    long locking_thread_id;
    basic_timed_mutex mutex;
    void lock();
    void unlock() { if (!--recursion_count) { _InterlockedExchange(&locking_thread_id, 0); mutex.unlock(); } }
    struct scoped_lock {
        recursive_mutex* m;
        bool is_locked;
        explicit scoped_lock(recursive_mutex& m_) : m(&m_), is_locked(false) { m->lock(); is_locked = true; }
        ~scoped_lock() { if (is_locked) m->unlock(); }
    };
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
				const int useSurfaces;

				bool operator<(const Attributes&) const;
			};


 struct Cache {
 std::map<Attributes,G3D::WeakReferenceCountedPointer<Render::Material> > database;
 std::map<Attributes,G3D::WeakReferenceCountedPointer<Render::Material> > megaDatabase;
 ExeBoost::recursive_mutex mutex;
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
		G3D::ReferenceCountedPointer<Render::Material> MaterialFactory::getMaterial(Attributes attributes)
		{
			if (!cache)
				initializeCache();
			Cache& state = *cache;
			ExeBoost::recursive_mutex::scoped_lock lock(state.mutex);

			G3D::ReferenceCountedPointer<Render::Material> material;

			std::map<Attributes, G3D::WeakReferenceCountedPointer<Render::Material> >::iterator iter = state.database.find(attributes);
			if (iter != state.database.end())
			{
				material = iter->second.createStrongPtr();
			}

			if (material.isNull())
			{
				G3D::Color3 color3 = attributes.color.color3();
				material = Render::createMaterial();
				if (attributes.transparency == 1.0f)
				{
					material->appendEmptyLevel();
				}
				else if (attributes.useSurfaces)
				{
					G3D::ReferenceCountedPointer<Render::TextureProxy> surfacesTexture = getSurfacesTexture(color3);
					material->appendLevel(surfacesTexture, G3D::Color3::WHITE, specular, shiny, attributes.reflectance, attributes.transparency);
				}
				else
				{
					material->appendLevel(NULL, color3, specular, shiny, attributes.reflectance, attributes.transparency);
				}

				state.database[attributes] = material;
			}

			return material;
		}
	}
}

namespace G3D { const Color3 Color3::WHITE(1,1,1); }
