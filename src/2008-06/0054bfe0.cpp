// from server: 100% by king_originala
struct Mesh {
    Mesh();
    void f(void *arg, int count);
};

#pragma optimize("", off)
Mesh::Mesh()
{
    f(0, 0);
}
