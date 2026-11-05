// from server: 100% by king_originala
struct Color3 {
    float r, g, b;
};

struct Color3uint8 {
    unsigned char r, g, b;
    Color3uint8(const Color3&);
};

struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual Color3 get(void*) = 0;
};

struct Value {
    unsigned int reserved;
    unsigned int type;
    unsigned int data;
    void clear();
};

struct Output {
    unsigned char padding[16];
    Value value;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor* accessor;
    void read(void*, Output*);
};

void Descriptor::read(void* object, Output* output)
{
    Color3 color = accessor->get(object);
    Color3uint8 bytes(color);
    unsigned int packed =
        (((bytes.r + 0xff00u) << 8) + bytes.g) * 256u + bytes.b;
    Value* value = &output->value;
    value->clear();
    value->data = packed;
    value->type = 6;
}
