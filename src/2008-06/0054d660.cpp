// from server: 100% by king_originala
#pragma optimize("", off)

struct Element
{
    unsigned char data[16];
};

struct Mesh
{
    Element* elements;
    unsigned int count;
    Element* last();
};

Element* Mesh::last()
{
    do {} while (0);
    do {} while (0);
    return elements + (count - 1);
}
