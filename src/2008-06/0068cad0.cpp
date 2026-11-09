// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

namespace Ogre {
    struct SceneManager;
    struct AxisAlignedBox;

    struct AxisAlignedBoxSceneQuery {
        virtual ~AxisAlignedBoxSceneQuery();
        virtual void setQueryMask(unsigned int);
        __declspec(dllimport) void setBox(const AxisAlignedBox&);
        unsigned char data[48];
    };

    struct SceneQueryListener {
        virtual ~SceneQueryListener();
        unsigned char data[36];
    };

    struct DefaultAxisAlignedBoxSceneQuery
        : AxisAlignedBoxSceneQuery, SceneQueryListener {
        __declspec(dllimport) DefaultAxisAlignedBoxSceneQuery(SceneManager*);
    };

    struct RbxAxisAlignedBoxSceneQuery : DefaultAxisAlignedBoxSceneQuery {
        RbxAxisAlignedBoxSceneQuery(SceneManager*);
        virtual ~RbxAxisAlignedBoxSceneQuery();
    };

    struct RbxSceneManager {
        AxisAlignedBoxSceneQuery* createAABBQuery(
            const AxisAlignedBox&, unsigned int);
    };
}

inline Ogre::RbxAxisAlignedBoxSceneQuery::RbxAxisAlignedBoxSceneQuery(
    Ogre::SceneManager* manager)
    : DefaultAxisAlignedBoxSceneQuery(manager)
{
}

Ogre::AxisAlignedBoxSceneQuery* Ogre::RbxSceneManager::createAABBQuery(
    const Ogre::AxisAlignedBox& box, unsigned int mask)
{
    RbxAxisAlignedBoxSceneQuery* query =
        new RbxAxisAlignedBoxSceneQuery(
            reinterpret_cast<SceneManager*>(this));
    query->setBox(box);
    query->setQueryMask(mask);
    return query;
}
