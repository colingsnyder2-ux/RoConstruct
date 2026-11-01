// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Node {
    unsigned int hash;
    Vector3 key;
    unsigned char padding[4];
    Node* next;
};

struct Block {
    unsigned char padding[8];
    Node** buckets;
    unsigned int bucketCount;

    bool contains(const Vector3& key);
};

#pragma float_control(precise, off, push)

bool Block::contains(const Vector3& key)
{
    unsigned int hash = key.hashCode();
    Node* node = buckets[hash % bucketCount];
    while (node) {
        if (node->hash == hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z)
            return true;
        node = node->next;
    }
    return false;
}

#pragma float_control(pop)
