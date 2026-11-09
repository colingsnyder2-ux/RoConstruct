// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

namespace Ogre {
    struct SceneManager;
    struct Sphere;

    struct SphereSceneQuery {
        virtual ~SphereSceneQuery();
        virtual void setQueryMask(unsigned int);
        __declspec(dllimport) void setSphere(const Sphere&);
        unsigned char data[48];
    };

    struct SceneQueryListener {
        virtual ~SceneQueryListener();
        unsigned char data[20];
    };

    struct DefaultSphereSceneQuery
        : SphereSceneQuery, SceneQueryListener {
        __declspec(dllimport) DefaultSphereSceneQuery(SceneManager*);
    };

    struct RbxSphereSceneQuery : DefaultSphereSceneQuery {
        RbxSphereSceneQuery(SceneManager*);
        virtual ~RbxSphereSceneQuery();
    };

    struct RbxSceneManager {
        SphereSceneQuery* createSphereQuery(const Sphere&, unsigned int);
    };
}

inline Ogre::RbxSphereSceneQuery::RbxSphereSceneQuery(
    Ogre::SceneManager* manager)
    : DefaultSphereSceneQuery(manager)
{
}

Ogre::SphereSceneQuery* Ogre::RbxSceneManager::createSphereQuery(
    const Ogre::Sphere& sphere, unsigned int mask)
{
    RbxSphereSceneQuery* query =
        new RbxSphereSceneQuery(reinterpret_cast<SceneManager*>(this));
    query->setSphere(sphere);
    query->setQueryMask(mask);
    return query;
}
