// from server: 100% by colin
struct Color8 {
    unsigned char r, g, b;
};

struct Color {
    float r, g, b;
    Color(const Color8&);
};

struct Value {
    bool readPacked(unsigned int*);
    bool readFloat(float*);
};

struct Node {
    unsigned char padding[16];
    Value value;
    bool isEmpty();
    Node* find(const void*);
};

extern const void* redKey;
extern const void* greenKey;
extern const void* blueKey;

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Color&);
};

struct Descriptor {
    unsigned char padding[24];
    Setter* setter;
    void read(void*, Node*, void*);
};

void Descriptor::read(void* object, Node* node, void*)
{
    Node* source = node;
    if (source->isEmpty())
        return;

    unsigned int packed;
    if (source->value.readPacked(&packed)) {
        Color8 bytes;
        bytes.r = static_cast<unsigned char>(packed >> 16);
        bytes.g = static_cast<unsigned char>(packed >> 8);
        bytes.b = static_cast<unsigned char>(packed);
        Color color(bytes);
        setter->set(object, color);
    } else {
        Node* red = source->find(redKey);
        Node* green = source->find(greenKey);
        Node* blue = source->find(blueKey);
        float components[3];
        red->value.readFloat(&components[0]);
        green->value.readFloat(&components[1]);
        blue->value.readFloat(&components[2]);
        setter->set(object, *reinterpret_cast<Color*>(components));
    }
}
