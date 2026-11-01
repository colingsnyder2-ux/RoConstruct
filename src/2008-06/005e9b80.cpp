// from server: 100% by king_originala
struct Node {
    char padding[28];
    void* value;
};

struct Object {
    char padding[36];
    Node* node;
};

struct Collection {
    char storage[32];
    void insertItem(void*);
    void eraseItem(void*);
};

struct PhysicsService {
    char padding[64];
    Collection active;
    Collection inactive;
    void update(Object*, bool);
};

void PhysicsService::update(Object* object, bool enabled)
{
    void* value = object->node->value;
    if (enabled)
        active.insertItem(value);
    else
        inactive.eraseItem(value);
}
