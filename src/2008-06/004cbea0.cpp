// from server: 100% by king_originala
struct Link {
    unsigned int tagged;
    Link* left;
    Link* right;
};

struct Tag {
    bool value;
};

struct Position {
    Tag tag;
    Link* link;
};

struct Node {
    char padding0[8];
    double key;
    char padding1[80];
    Link link;
};

struct Context {
    long reserved;
    Node* object;
};

extern "C" void __cdecl attach(Link*, Position, Link*);

struct S {
    bool find(double*, Position*, Tag);
    Node* insert(Node*, Node*);
    Node* f(Node*, Node*);
};

Node* S::f(Node* source, Node* candidate)
{
    Position position;
    position.tag.value = false;

    if (!find(&source->key, &position, position.tag))
        return position.link
            ? reinterpret_cast<Node*>(
                reinterpret_cast<char*>(position.link) - 0x60)
            : 0;

    Node* result = insert(source, candidate);
    if (result == candidate) {
        Node* parent = (this
            ? reinterpret_cast<Context*>(
                reinterpret_cast<char*>(this) - 12)
            : 0)->object;

        attach(candidate ? &candidate->link : 0,
               position,
               parent ? &parent->link : 0);
    }
    return result;
}
