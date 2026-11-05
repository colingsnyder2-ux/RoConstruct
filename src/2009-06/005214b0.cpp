// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_46ecda0c9215b4cb.cpp

// Candidate translation unit (score above; library headers required).
#include <RenderLib/Mesh.h>
#include <util/NormalId.h>

namespace RBX { namespace View {
class RenderSurfaceTypes
{
public:
    size_t data;
    RenderSurfaceTypes() : data(0) {}
    unsigned int hashCode() const { return data; }
    bool operator==(const RenderSurfaceTypes& other) const { return data == other.data; }
};
}}
inline unsigned int hashCode(const RBX::View::RenderSurfaceTypes& t) { return t.hashCode(); }

#include <G3D/Table.h>
#include <intrin.h>
#include <windows.h>
namespace boost {
class thread_resource_error { public: thread_resource_error(); thread_resource_error(const thread_resource_error&); virtual ~thread_resource_error(); char pad[0xc]; };
namespace detail {
struct basic_timed_mutex {
    long active_count; void* event;
    void* get_event() {
        void* current_event=event;
        if(!current_event) {
            void* const new_event=CreateEventA(0,0,0,0);
            if(!new_event) throw thread_resource_error();
            void* const old_event=(void*)_InterlockedCompareExchange((long volatile*)&event,(long)new_event,0);
            if(old_event!=0) { CloseHandle(new_event); return old_event; }
            else return new_event;
        }
        return current_event;
    }
    void unlock() {
        long const offset=0x80000000;
        long const old_count=_InterlockedExchangeAdd(&active_count,offset);
        if(!(old_count&0x40000000) && (old_count>offset)) {
            if(!_interlockedbittestandset(&active_count,30)) SetEvent(get_event());
        }
    }
};
struct basic_recursive_mutex {
    long recursion_count; long locking_thread_id; basic_timed_mutex mutex;
    void lock();
    void unlock() { if(!--recursion_count) { _InterlockedExchange(&locking_thread_id,0); mutex.unlock(); } }
};
}
class recursive_mutex : public detail::basic_recursive_mutex {
public:
    struct scoped_lock { recursive_mutex* m; bool is_locked; explicit scoped_lock(recursive_mutex& m_):m(&m_),is_locked(false){ m->lock(); is_locked=true; } ~scoped_lock(){ if(is_locked) m->unlock(); } };
};
}
#include <boost/thread/once.hpp>
#include <map>

void flushUnusedMeshCache();
namespace RBX {
namespace View {

class SphereMesh : public Render::Mesh
{
public:
    SphereMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
};

template<class Mesh, size_t numMeshes>
class MeshFactory
{
public:
    class DecalKey
    {
    private:
        G3D::Vector3 size;
        NormalId face;
    public:
        bool operator<(const DecalKey&) const;
    };
    class TextureKey : protected DecalKey
    {
    private:
        G3D::Vector2 studsPerTile;
    public:
        bool operator<(const TextureKey&) const;
    };
    struct Variations
    {
        G3D::ReferenceCountedPointer<Render::Mesh> meshes[numMeshes];
    };
    struct Cache
    {
        G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> > cache1;
        boost::recursive_mutex mutex;
        std::map<DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > decalCache;
        std::map<TextureKey, G3D::ReferenceCountedPointer<Render::Mesh> > textureCache;
        int count;
    };
    static Cache* cache;
    static boost::once_flag cacheOnce;
    static void initCache();
    static Cache* getCache();
    static void flushUnused();
};

template<class Mesh, size_t numMeshes>
void MeshFactory<Mesh, numMeshes>::flushUnused()
{
    boost::call_once(initCache, cacheOnce);
    Cache* c = getCache();
    boost::recursive_mutex::scoped_lock lock(c->mutex);

    for (typename G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> >::Iterator it = c->cache1.begin(); it != c->cache1.end(); it++)
    {
        G3D::Table<G3D::Vector3, Variations>& sizeCache = it->value;
        for (typename G3D::Table<G3D::Vector3, Variations>::Iterator it2 = sizeCache.begin(); it2 != sizeCache.end(); it2++)
        {
            for (size_t i = 0; i < numMeshes; ++i)
            {
                if (it2->value.meshes[i].notNull() && it2->value.meshes[i].isLastReference())
                    it2->value.meshes[i] = NULL;
            }
        }
    }

    for (typename std::map<DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> >::iterator it = c->decalCache.begin(); it != c->decalCache.end(); ++it)
    {
        if (it->second.notNull() && it->second.isLastReference())
            it->second = NULL;
    }

    for (typename std::map<TextureKey, G3D::ReferenceCountedPointer<Render::Mesh> >::iterator it = c->textureCache.begin(); it != c->textureCache.end(); ++it)
    {
        if (it->second.notNull() && it->second.isLastReference())
            it->second = NULL;
    }
}

template class MeshFactory<SphereMesh, 4>;
}
}

