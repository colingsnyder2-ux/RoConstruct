// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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