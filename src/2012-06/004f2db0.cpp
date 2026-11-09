// roc 2012-06 004f2db0  unit: Ogre::RbxMeshPartAdapter::??fillVertices::?BA::FileLoader  size: 3 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f2db0
//
// 004f2db0  d9ee                 fldz 
// 004f2db2  c3                   ret 
// copied from an identical function in another client (function ?f@Ogre_RbxMeshPartAdapter@ns_ROCX000089@@QAEMXZ)

namespace ns_ROCX000089 {
struct Ogre_RbxMeshPartAdapter {
    char pad[868];
    float m_x;
    float f();
};

float Ogre_RbxMeshPartAdapter::f() {
    return 0.0f;
}
}
