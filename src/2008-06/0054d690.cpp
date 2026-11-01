// from server: 100% by king_originala
struct Mesh {
    void *first;
    void *last;
    void *end;

    void f(void *arg, int count);
    void initialize(void *arg);
};

#pragma optimize("", off)
void Mesh::f(void *arg, int count)
{
    do {} while (0);
    do {} while (0);
    last = 0;
    end = 0;
    first = 0;
    if (count > 0)
        initialize(arg);
    else
        first = 0;
}
#pragma optimize("", on)
