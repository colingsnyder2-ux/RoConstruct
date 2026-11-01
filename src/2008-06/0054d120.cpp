// from server: 100% by king_originala
struct Element {
    unsigned int data[2];
};

struct Mesh {
    Element* begin;
    unsigned int count;
    bool contains(Element* value);
};

#pragma optimize("", off)
bool Mesh::contains(Element* value)
{
    return value >= begin && value < begin + count;
}
