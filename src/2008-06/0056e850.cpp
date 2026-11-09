// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Value {
    bool readFloat(float* result);
};

struct Node {
    char padding[16];
    Value value;
};

struct Source {
    bool isSpecial();
    Node* find(void* key);
};

extern void* keyX;
extern void* keyY;
extern void* keyZ;

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* object, const Vector3& value) = 0;
};

struct Descriptor {
    char padding[24];
    Setter* setter;

    void read(void* object, Source* source, void* unused);
};

void Descriptor::read(void* object, Source* source, void* unused)
{
    if (!source->isSpecial()) {
        Node* x = source->find(keyX);
        if (x) {
            Node* y = source->find(keyY);
            Node* z = source->find(keyZ);
            Vector3 value = { 0.0f, 0.0f, 0.0f };
            x->value.readFloat(&value.x);
            y->value.readFloat(&value.y);
            z->value.readFloat(&value.z);
            setter->set(object, value);
        }
    }
}
