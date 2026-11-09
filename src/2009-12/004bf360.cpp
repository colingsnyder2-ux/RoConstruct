// from server: 61% by atomic.potato
typedef const void *RbxString;

struct OgreNode
{
    OgreNode *removeChild(const RbxString &name);
};

extern "C" OgreNode *__stdcall OgreNode_removeChild(OgreNode *, const RbxString &);

struct Ogre_RbxSpatialHashedSceneNode
{
    OgreNode *f(const RbxString &name);
};

Ogre_RbxSpatialHashedSceneNode *g_removeChildObject;

OgreNode *Ogre_RbxSpatialHashedSceneNode::f(const RbxString &name)
{
    OgreNode *result = OgreNode_removeChild((OgreNode *)g_removeChildObject, name);
    return ((OgreNode *)this)->removeChild((const RbxString &)result);
}
