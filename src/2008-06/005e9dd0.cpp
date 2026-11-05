// from server: 100% by king_originala
struct Collection {
    char storage[0x85];
    void update(void* value);
};

struct PhysicsService {
    char padding[0x20];
    Collection collection;
    bool updating;

    void update(void* value);
};

void PhysicsService::update(void* value) {
    updating = true;
    collection.update(value);
    updating = false;
}
