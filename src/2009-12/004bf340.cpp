// from server: 61% by atomic.potato
typedef void *NodePtr;

extern "C" NodePtr Ogre_Node_removeChild(NodePtr self, NodePtr child);

struct RbxSpatialHashedSceneNode
{
    NodePtr removeChild(NodePtr child);
};

NodePtr RbxSpatialHashedSceneNode::removeChild(NodePtr child)
{
    NodePtr result = Ogre_Node_removeChild(this, child);
    return result;
}
