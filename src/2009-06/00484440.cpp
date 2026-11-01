// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace Ogre {
class __declspec(dllimport) SceneNode {
public:
	virtual ~SceneNode();
	void removeAllChildren();
};
class RbxSpatialHashedSceneNode : public SceneNode {
public:
	void removeAllChildren();
	void detachAll();
};
void RbxSpatialHashedSceneNode::removeAllChildren()
{
	detachAll();
	SceneNode::removeAllChildren();
}
}
