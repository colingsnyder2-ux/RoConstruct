// from server: 100% by colin
struct Mesh {
    int size;
    void *first;
    void *last;

    void initialize(void *);
    void f(void *, int);
};

#pragma optimize("", off)
void Mesh::f(void *arg, int count)
{
    do {} while (0);
    do {} while (0);

    first = 0;
    last = 0;
    size = 0;

    if (count > 0)
        initialize(arg);
    else
        size = 0;
}
#pragma optimize("", on)
