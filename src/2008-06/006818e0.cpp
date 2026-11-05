// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_34708910126535a9.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <stdexcept>
namespace Ogre {
class RbxSceneNode : public SceneNode {
public:
    typedef std::map<unsigned long, Matrix4*> TransformMap;
    mutable TransformMap transforms;
    void setTransform(unsigned int key, const Matrix4& transform);
    const Matrix4& getTransform(unsigned long key) const;
};
void RbxSceneNode::setTransform(unsigned int key, const Matrix4& transform) {
    TransformMap::iterator i = transforms.find(key);
    if (i == transforms.end()) i = transforms.insert(TransformMap::value_type(key, new Matrix4)).first;
    *i->second = transform;
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
}
