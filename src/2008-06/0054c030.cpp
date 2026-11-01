// from server: 100% by king_originala
#pragma optimize("", off)

struct Vertex {
    char data[24];
};

struct Mesh {
    Vertex* vertices;
    Vertex* getVertex(int index);
};

Vertex* Mesh::getVertex(int index)
{
    do {} while (0);
    do {} while (0);
    return vertices + index;
}
