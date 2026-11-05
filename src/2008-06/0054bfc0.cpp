// from server: 100% by king_originala
#pragma optimize("", off)

struct Element {
    char data[16];
};

struct Mesh {
    Element* elements;
    Element* get(unsigned int index);
};

Element* Mesh::get(unsigned int index) {
    do {} while (0);
    do {} while (0);
    return elements + index;
}
