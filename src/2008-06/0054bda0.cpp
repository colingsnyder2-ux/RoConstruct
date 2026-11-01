// from server: 100% by king_originala
#pragma optimize("", off)

struct Mesh {
    void f(void* p);
    void g(void* p, int flag);
};

void Mesh::f(void* p)
{
    g(p, 1);
}
