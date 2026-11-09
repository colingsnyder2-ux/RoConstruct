// from server: 100% by king_originala
struct Node;
struct Group;

struct Receiver {
    char pad0[0x14];
    Receiver* parent;
    char pad18[0x1C];
    int state;
    void reset(int value);
};

struct Node {
    char pad0[0x5C];
    Group* group;
    char pad60[0x40];
    Receiver* receiver;
    void* getShape();
};

struct Group {
    char pad0[0x1C];
    Node* root;
    char pad20[4];
    void* shape;
    void remove(Node* node);
    void reset(int value);
};

struct Edge {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int isSpecial();
    virtual int v4();
    virtual int getType();
    char pad4[8];
    Node* first;
    Node* second;
};

struct InsertResult {
    unsigned int data[3];
};

struct Pending {
    InsertResult insert(Node* const& node);
};

extern "C" void __cdecl apply(Node*, Edge*, Node*);
extern "C" void __cdecl attach(Node*, Edge*, Node*);
extern "C" void __cdecl assign(Node*, Edge*, Node*);

struct Stage {
    char pad0[0x14];
    bool dirty;
    char pad15[0x23];
    Pending pending;

    Group* create(Node* node);
    void invalidate(void* shape);
    void prepare(Group* group);
    void remove(Group* group);
    void process(Edge* edge, Node* node);
};

void Stage::process(Edge* edge, Node* node)
{
    Node* other = edge->first;
    if (node == other)
        other = edge->second;

    Group* group = other->group;
    bool isRoot = group && group->root == other;

    if (!edge->isSpecial()) {
        int type = edge->getType();
        if (type == 6 || type == 7) {
            if (group == node->group &&
                other->receiver->parent == node->receiver &&
                other->receiver->state == 0) {
                apply(node, edge, other);
                return;
            }

            if (group) {
                if (isRoot) {
                    remove(group);
                } else {
                    invalidate(group->shape);
                    group->remove(other);
                }
            }

            invalidate(node->getShape());
            attach(node, edge, other);
            return;
        }
    }

    if (isRoot) {
        invalidate(group->shape);
        other->receiver->reset(0);
        group->reset(0);
    } else {
        if (group) {
            invalidate(group->shape);
            group->remove(other);
        }
        group = create(other);
    }

    if (!edge->isSpecial() && edge->getType() == 8) {
        invalidate(node->getShape());
        prepare(group);
        assign(node, edge, other);
        return;
    }

    int type = edge->getType();
    if (type == 9 || type == 5) {
        node = reinterpret_cast<Node*>(group);
        pending.insert(node);
        dirty = true;
    }
}
