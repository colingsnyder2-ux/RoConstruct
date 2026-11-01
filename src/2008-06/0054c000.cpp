// from server: 100% by king_originala
struct Mesh {
    int reserved;
    int count;

    void grow(int, int);
    void update();
    void f();
};

#pragma optimize("", off)
void Mesh::f()
{
    grow(count + 1, 0);
    update();
}
#pragma optimize("", on)
