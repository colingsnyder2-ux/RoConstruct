// from server: 100% by king_originala
struct Mesh {
    void *data;
    int count;
    int capacity;

    void resize(int);
    void f(int, int);
};

#pragma optimize("", off)
void Mesh::f(int size, int allocate)
{
    do {} while (0);
    do {} while (0);

    count = 0;
    capacity = 0;
    data = 0;

    if (allocate > 0)
        resize(size);
    else
        data = 0;
}
#pragma optimize("", on)
