// roc 2009-12 0049a680  unit: Ogre::RbxMeshPartAdapter::??fillVertices::?L::FileLoader  size: 3 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049a680
//
// 0049a680  d9ee                 fldz 
// 0049a682  c3                   ret 
// copied from an identical function in another client (function ?f@Ogre_RbxMeshPartAdapter@ns_ROCX00002e@@QAEMXZ)

namespace ns_ROCX00002e {
struct Ogre_RbxMeshPartAdapter {
    char pad[868];
    float m_x;
    float f();
};

float Ogre_RbxMeshPartAdapter::f() {
    return 0.0f;
}
}
