// from server: 100% by king_originala
struct Vector2 {
    short x;
    short y;
};

struct Value {
    bool get(int*);
};

struct Element {
    unsigned char padding[16];
    Value value;

    bool isNull();
    Element* find(void*);
};

extern void* xKey;
extern void* yKey;

struct Accessor;

struct AccessorTable {
    void* reserved[3];
    void (__thiscall* set)(Accessor*, void*, const Vector2&);
};

struct Accessor {
    AccessorTable* table;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor* accessor;

    void read(void*, Element*, void*);
};

void Descriptor::read(void* object, Element* element, void*)
{
    if (!element->isNull()) {
        Element* xElement = element->find(xKey);
        Element* yElement = element->find(yKey);
        int x;
        int y;
        xElement->value.get(&x);
        yElement->value.get(&y);
        Vector2 result;
        result.x = (short)x;
        result.y = (short)y;
        accessor->table->set(accessor, object, result);
    }
}
