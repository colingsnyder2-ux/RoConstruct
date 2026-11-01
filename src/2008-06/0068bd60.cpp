// from server: 100% by tester
// Ogre::RbxSceneManager: destroys all movable objects of one factory type.
#define V1(n) virtual void n();
#define V4(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3)
#define V16(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3)
#define V64(n) V16(n##0) V16(n##1) V16(n##2) V16(n##3)

struct MovableObjectFactory;
extern const char* FACTORY_TYPE_NAME_0068bd60_0068b880;

struct SceneManager {
    V64(a) V64(b) V64(c) V16(d)
    virtual void destroyAllMovableObjectsByType(const char* typeName);
};

struct RbxSceneManager : SceneManager {
    void destroyAllObjects();
};

void RbxSceneManager::destroyAllObjects()
{
    destroyAllMovableObjectsByType(FACTORY_TYPE_NAME_0068bd60_0068b880);
}
