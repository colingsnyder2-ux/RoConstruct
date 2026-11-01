// from server: 100% by king_originala
struct Manager;
struct Node;
struct Name;

extern void (__thiscall *sceneNodeConstructor)(Node *, Manager *);
extern const Name &(__thiscall *nodeGetName)(const Node *);
extern void *sceneNodeVtable[];

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Node
{
    void **vtable;
    unsigned char storage[0x224];

    Node(Manager *);
};

struct NodeMap
{
    Node *&operator[](const Name &);
};

struct Manager
{
    unsigned char storage[0x98];
    NodeMap nodes;

    Node *createNode();
};

__forceinline Node::Node(Manager *manager)
{
    sceneNodeConstructor(this, manager);
    vtable = sceneNodeVtable;
}

Node *Manager::createNode()
{
    Node *node = new Node(this);
    nodes[nodeGetName(node)] = node;
    return node;
}
