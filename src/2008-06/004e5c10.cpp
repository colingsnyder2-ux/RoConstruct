// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Value {
    unsigned char storage[16];
};

struct Node {
    unsigned int hash;
    Vector3 key;
    Value value;
    Node* next;
};

struct Block {
    unsigned char padding[8];
    Node** buckets;
    unsigned int bucketCount;

    Value* find(const Vector3& key);
};

#pragma float_control(precise, off, push)

Value* Block::find(const Vector3& key)
{
    unsigned int hash = key.hashCode();
    Node* node = buckets[hash % bucketCount];

    while (node) {
        if (node->hash == hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z)
            break;
        node = node->next;
    }

    return &node->value;
}

#pragma float_control(pop)
