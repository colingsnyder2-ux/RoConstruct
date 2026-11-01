// from server: 100% by king_originala
struct Mesh;

struct Result {
    void initialize(void *, Mesh *);
};

struct Mesh {
    void *lookup(void *);
    Result *f(Result *, void *);
};

#pragma optimize("", off)
Result *Mesh::f(Result *result, void *arg)
{
    result->initialize(lookup(arg), this);
    return result;
}
#pragma optimize("", on)
