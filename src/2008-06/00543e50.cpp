// from server: 100% by king_originala
#pragma optimize("", off)

struct Node;
struct Key;
struct S;

char* __cdecl nodeFlag(Node*);
char* __cdecl leftLink(Node*);
char* __cdecl rightLink(Node*);
const Key* __cdecl nodeKey(Node*);

struct Compare {
    bool compare(const Key&, const Key&);
};

struct Iterator {
    Node* node;
    S* owner;
    void initialize(Node*, S*);
};

struct Pair {
    Iterator first;
    Iterator second;
    Pair(const Iterator&, const Iterator&);
};

struct S {
    char padding[8];
    Compare comparator;
    char remaining[15];
    Node* head;

    char* root();
    Pair equalRange(const Key&);
};

Pair S::equalRange(const Key& key) {
    struct Frame {
        Node* upper;
        Iterator second;
        Node* lower;
        Node* current;
        Iterator first;
    } frame;

    frame.current = *reinterpret_cast<Node**>(root());
    frame.lower = head;
    frame.upper = head;

    while (!*nodeFlag(frame.current)) {
        if (comparator.compare(*nodeKey(frame.current), key)) {
            frame.current = *reinterpret_cast<Node**>(leftLink(frame.current));
        } else {
            if (*nodeFlag(frame.upper) &&
                comparator.compare(key, *nodeKey(frame.current))) {
                frame.upper = frame.current;
            }
            frame.lower = frame.current;
            frame.current = *reinterpret_cast<Node**>(rightLink(frame.current));
        }
    }

    frame.current = *nodeFlag(frame.upper)
        ? *reinterpret_cast<Node**>(root())
        : *reinterpret_cast<Node**>(rightLink(frame.upper));

    while (!*nodeFlag(frame.current)) {
        if (comparator.compare(key, *nodeKey(frame.current))) {
            frame.upper = frame.current;
            frame.current = *reinterpret_cast<Node**>(rightLink(frame.current));
        } else {
            frame.current = *reinterpret_cast<Node**>(leftLink(frame.current));
        }
    }

    frame.first.initialize(frame.lower, this);
    frame.second.initialize(frame.upper, this);
    return Pair(frame.first, frame.second);
}
