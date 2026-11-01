// from server: 100% by king_originala
struct Frame {
    float rotation[9];
    float position[3];
    Frame();
};

struct Value {
    bool toFloat(float* result);
};

struct Entry {
    unsigned char padding[16];
    Value value;
};

struct Element {
    bool isNull();
    Entry* find(unsigned int name);
};

extern unsigned int name975334;
extern unsigned int name975380;
extern unsigned int name975318;
extern unsigned int name975350;
extern unsigned int name975368;
extern unsigned int name975304;
extern unsigned int name975328;
extern unsigned int name975354;
extern unsigned int name975348;
extern unsigned int name975324;
extern unsigned int name975320;
extern unsigned int name975308;

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const Frame& value);
};

struct Descriptor {
    unsigned char padding[24];
    Setter* setter;
    void read(void* instance, Element* element, void* unused);
};

void Descriptor::read(void* instance, Element* element, void* unused)
{
    if (element->isNull())
        return;

    Frame frame;
    float value;

    element->find(name975334)->value.toFloat(&value);
    frame.position[0] = value;
    element->find(name975380)->value.toFloat(&value);
    frame.position[1] = value;
    element->find(name975318)->value.toFloat(&value);
    frame.position[2] = value;

    element->find(name975350)->value.toFloat(&value);
    frame.rotation[0] = value;
    element->find(name975368)->value.toFloat(&value);
    frame.rotation[1] = value;
    element->find(name975304)->value.toFloat(&value);
    frame.rotation[2] = value;
    element->find(name975328)->value.toFloat(&value);
    frame.rotation[3] = value;
    element->find(name975354)->value.toFloat(&value);
    frame.rotation[4] = value;
    element->find(name975348)->value.toFloat(&value);
    frame.rotation[5] = value;
    element->find(name975324)->value.toFloat(&value);
    frame.rotation[6] = value;
    element->find(name975320)->value.toFloat(&value);
    frame.rotation[7] = value;
    element->find(name975308)->value.toFloat(&value);
    frame.rotation[8] = value;

    setter->set(instance, frame);
}
