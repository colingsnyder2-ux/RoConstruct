// from server: 100% by king_originala
struct Node {
    char padding[0x1c];
    bool marked;
};

struct InsertResult {
    void* first;
    void* second;
    bool inserted;
};

struct Container {
    InsertResult insert(Node* const& node);
};

struct TreeStage {
    char padding0[0x14];
    bool active;
    char padding1[0x43];
    Container pending;

    void fallback(Node* node);
    void process(Node* node);
};

void TreeStage::process(Node* node)
{
    if (active) {
        bool marked = node->marked;
        Node* value = node;
        if (!marked) {
            pending.insert(value);
            active = true;
            node->marked = true;
        }
    } else {
        fallback(node);
    }
}
