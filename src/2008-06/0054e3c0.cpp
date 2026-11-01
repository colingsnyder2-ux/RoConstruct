// from server: 100% by king_originala
#pragma optimize("", off)

struct Node;
struct Mesh;

struct Iterator {
    Node* node;
    Mesh* owner;

    Iterator(Node*, Mesh*);
    bool operator==(const Iterator&) const;
    Iterator& operator--();
    Node* get() const;
};

struct Pair {
    Iterator position;
    bool inserted;

    Pair(const Iterator&, const bool&);
};

struct Compare {
    bool operator()(const int&, const int&) const;
};

struct Mesh {
    char padding[8];
    Compare compare;
    char padding2[15];
    Node* sentinel;

    Node** root();
    Iterator end();
    Iterator insert(bool, Node*, Node*);
    Pair find(Node*);
};

extern signed char* __cdecl isNil(Node*);
extern int* __cdecl nodeValue(Node*);
extern int* __cdecl keyValue(Node*);
extern char* __cdecl leftChild(Node*);
extern Node** __cdecl rightChild(Node*);

Pair Mesh::find(Node* key)
{
    struct Locals {
        Node* current;
        Node* parent;
        char padding[3];
        bool before;
    } local;

    local.current = *root();
    local.parent = sentinel;
    local.before = true;

    while (*isNil(local.current) == 0) {
        local.parent = local.current;
        local.before = compare(*keyValue(key), *nodeValue(local.current));
        local.current = local.before
            ? *rightChild(local.current)
            : *reinterpret_cast<Node**>(leftChild(local.current));
    }

    if (false) {
        return Pair(insert(local.before, local.parent, key), true);
    } else {
        Iterator position(local.parent, this);
        if (!local.before) {
        } else {
            if (position == end()) {
                return Pair(insert(true, local.parent, key), true);
            } else {
                --position;
            }
        }

        if (compare(*nodeValue(position.get()), *keyValue(key))) {
            return Pair(insert(local.before, local.parent, key), true);
        } else {
            return Pair(position, false);
        }
    }
}
