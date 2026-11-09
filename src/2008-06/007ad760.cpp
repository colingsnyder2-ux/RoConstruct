// from server: 100% by king_originala
struct Element {
    char bytes[56];
};

struct Storage {
    Element* data;
    unsigned count;
    void resize(unsigned newCount, const Element* value);
};

struct Material {
    char padding[12];
    Storage storage;
    Element* append();
};

Element* Material::append()
{
    Storage* s = &storage;
    s->resize(s->count + 1, 0);
    return s->data + s->count - 1;
}
