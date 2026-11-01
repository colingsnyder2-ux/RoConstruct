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

    void resize(unsigned int size, int value);
    Element* last();
    Element* append();
};

Element* Mesh::append()
{
    resize(count + 1, 0);
    return last();
}
