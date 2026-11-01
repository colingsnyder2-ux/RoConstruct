// from server: 100% by king_originala
struct Mesh {
    int value;
    int f(int offset);
};

#pragma optimize("", off)
int Mesh::f(int offset)
{
    do {} while (0);
    do {} while (0);
    return value + offset;
}
#pragma optimize("", on)
