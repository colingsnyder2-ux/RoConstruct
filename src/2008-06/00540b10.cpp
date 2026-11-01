// from server: 100% by king_originala
#pragma optimize("g", off)

struct Node;
struct Bucket;

char* __cdecl nodeFlag(Node*);
char* __cdecl rightLink(Node*);
void* __cdecl nodeValue(void*);
Node** __cdecl leftLink(void*);

struct Iterator {
    Node* node;
    Bucket* owner;

    Iterator(Node*, Bucket*);
    bool equal(const Iterator&) const;
    void decrement();
    void* value() const;
};

struct Result {
    Iterator position;
    bool inserted;

    Result(const Iterator&, const bool&);
};

struct Compare {
    bool less(const void*, const void*) const;
};

struct Bucket {
    char padding[8];
    Compare compare;
    char padding2[15];
    Node* head;

    Node** root();
    Iterator end();
    Iterator insertAt(bool, Node*, void*);
    Result insert(void*);
};

Result Bucket::insert(void* value)
{
    struct State {
        Node* current;
        Node* parent;
        char padding[3];
        bool left;
    } state;

    state.current = *root();
    state.parent = head;
    state.left = true;

    while (*nodeFlag(state.current) == 0) {
        state.parent = state.current;
        state.left = compare.less(leftLink(value), nodeValue(state.current));
        state.current = state.left
            ? *leftLink(state.current)
            : *reinterpret_cast<Node**>(rightLink(state.current));
    }

    if (false) {
        return Result(insertAt(state.left, state.parent, value), true);
    } else {
        Iterator position(state.parent, this);

        if (!state.left) {
        } else {
            if (position.equal(end())) {
                return Result(insertAt(true, state.parent, value), true);
            } else {
                position.decrement();
            }
        }

        if (compare.less(nodeValue(position.value()), leftLink(value))) {
            return Result(insertAt(state.left, state.parent, value), true);
        } else {
            return Result(position, false);
        }
    }
}
