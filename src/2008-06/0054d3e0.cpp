// from server: 100% by king_originala
struct Mesh {
    void *data;
    unsigned size;
    unsigned capacity;

    void assign(void *);
    void f(void *, int);
};

#pragma optimize("", off)
void Mesh::f(void *arg, int count)
{
    do {} while (0);
    do {} while (0);

    size = 0;
    capacity = 0;
    data = 0;

    if (count > 0)
        assign(arg);
    else
        data = 0;
}
#pragma optimize("", on)
