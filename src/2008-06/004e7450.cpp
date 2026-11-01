// from server: 100% by king_originala
#pragma float_control(precise, off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Vector {
    float x, y, z;
    Vector(const Vector&);
    unsigned int hash() const;
};

inline Vector::Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

struct Element {
    void* pointer;
    Element(const Element&);
    ~Element();
};

struct Value {
    Element elements[4];
    void assign(const Value&);
};

struct Node {
    unsigned int hash;
    Vector key;
    Value value;
    Node* next;

    Node(Vector, Value, unsigned int, Node*);
};

struct Texture {
    int unused;
    int count;
    Node** buckets;
    int capacity;

    void insert(const Vector&, const Value&);
    void resize(int);
};

void Texture::insert(const Vector& key, const Value& value)
{
    unsigned int hash = key.hash();
    unsigned int index = hash % capacity;
    Node* node = buckets[index];

    if (!node) {
        buckets[index] = new Node(key, value, hash, 0);
        ++count;
    } else {
        int length = 1;
        bool sameHash = true;

        do {
            sameHash = sameHash && hash == node->hash;

            if (hash == node->hash &&
                node->key.x == key.x &&
                node->key.y == key.y &&
                node->key.z == key.z) {
                node->value.assign(value);
                return;
            }

            node = node->next;
            ++length;
        } while (node);

        if ((!sameHash & (length > 5)) && capacity < count * 20)
            resize(capacity * 2 + 1);

        index = hash % capacity;
        buckets[index] = new Node(key, value, hash, buckets[index]);
        ++count;
    }
}
