// from server: 100% by king_originala
struct Mesh {
    void *data;
    int count;
    int capacity;
    Mesh();
    void f(int size, int allocate);
};

#pragma optimize("", off)
Mesh::Mesh()
{
    f(0, 0);
}
