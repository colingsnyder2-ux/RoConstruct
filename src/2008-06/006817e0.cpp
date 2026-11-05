// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_ogre_resume_17f9ce717551bd70.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <stdexcept>
namespace Ogre {
class RbxSceneNode : public SceneNode {
public:
    typedef std::map<unsigned long, Matrix4*> TransformMap;
    mutable TransformMap transforms;
    void _updateBounds();
    void setTransform(unsigned int key, const Matrix4& transform);
    const Matrix4& getTransform(unsigned long key) const;
    const Sphere& getSphere(unsigned long key) const;
    ~RbxSceneNode();
};
void RbxSceneNode::_updateBounds() {
    mWorldAABB.setNull();
    ObjectMap::iterator i;
    for (i = mObjectsByName.begin(); i != mObjectsByName.end(); ++i)
        mWorldAABB.merge(i->second->getWorldBoundingBox(true));
    ChildNodeMap::iterator child;
    for (child = mChildren.begin(); child != mChildren.end(); ++child)
        mWorldAABB.merge(static_cast<SceneNode*>(child->second)->_getWorldAABB());
}
void RbxSceneNode::setTransform(unsigned int key, const Matrix4& transform) {
    std::pair<TransformMap::iterator, bool> result(transforms.find(key), false);
    if (result.first == transforms.end()) result = transforms.insert(TransformMap::value_type(key, new Matrix4));
    *result.first->second = transform;
}
const Matrix4& RbxSceneNode::getTransform(unsigned long key) const {
    if (key) {
        TransformMap::iterator i = transforms.find(key);
        if (i == transforms.end()) throw std::runtime_error("Transform map error");
        return *i->second;
    }
    if (mCachedTransformOutOfDate) {
        mCachedTransform.makeTransform(_getDerivedPosition(), _getDerivedScale(), _getDerivedOrientation());
        mCachedTransformOutOfDate = false;
    }
    return mCachedTransform;
}
RbxSceneNode::~RbxSceneNode() {
    for (TransformMap::iterator i = transforms.begin(); i != transforms.end(); ++i) delete i->second;
    transforms.clear();
}
typedef std::map<unsigned long, Sphere> SphereMap;
extern SphereMap* spheres;
void initializeSpheres() {
    if (!spheres) spheres = new SphereMap;
}
const Sphere& RbxSceneNode::getSphere(unsigned long key) const {
    SphereMap::const_iterator i = spheres->find(key);
    if (i == spheres->end()) throw std::runtime_error("bsphere map error");
    return i->second;
}
}
