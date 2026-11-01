// from server: 100% by king_originala
struct Item;

struct Owner {
    char padding[0x5c];
    Item* item;
};

struct Node {
    char padding0[0x0c];
    Owner* owner;
    char padding1[0x14];
    bool marked;
};

struct TreeStage {
    void detach(Node* node);
    void remove(Item* item);
    void attach(Node* node, void* context, int flag);
    void change(Node* previous, Node* next, void* context);
};

void TreeStage::change(Node* previous, Node* next, void* context)
{
    if (previous) {
        detach(previous);
        previous->marked = false;
        if (!next) {
            remove(previous->owner->item);
            return;
        }
    }

    if (next) {
        detach(next);
        next->marked = true;
        attach(next, context, 0);
    }
}
