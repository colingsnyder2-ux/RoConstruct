// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace Ogre {
class __declspec(dllimport) SceneNode {
public:
    virtual ~SceneNode();
    char pad[0x23c];
};
class RbxStaticCluster : public SceneNode {
public:
    int state;
    virtual ~RbxStaticCluster();
};
RbxStaticCluster::~RbxStaticCluster() { state = -2; }
}
