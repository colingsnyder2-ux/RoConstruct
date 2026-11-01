// from server: 100% by king_originala
struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual bool active();
};

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void remove(Node*);
};

struct Collection {
    unsigned char storage[0x20];
    void remove(Node* const*);
};

struct PhysicsService {
    unsigned char padding0[0x88];
    Manager* manager;
    unsigned char padding1[0x38];
    Collection collection;
    int count;

    void remove(Node*);
};

void PhysicsService::remove(Node* node)
{
    Node* entry = node;
    if (node->active())
        collection.remove(&entry);
    manager->remove(node);
    --count;
}
