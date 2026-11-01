// from server: 100% by king_originala
struct Mesh {
    unsigned int* data;
    unsigned int* get(unsigned int index);
};

#pragma optimize("", off)
unsigned int* Mesh::get(unsigned int index)
{
    do {
    } while (0);

    return data + index;
}
