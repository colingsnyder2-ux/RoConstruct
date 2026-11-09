// from server: 100% by king_originala
struct Frame
{
    float matrix[9];
    float x, y, z;
    bool equalMatrix(const Frame &other) const;
};

struct S
{
    int f(int destination, int object);
    bool compare(int left, int right);
};

#pragma float_control(precise, off)

bool S::compare(int left, int right)
{
    Frame rightStorage;
    Frame leftStorage;
    const Frame *r = (const Frame *)f((int)&rightStorage, right);
    const Frame *l = (const Frame *)f((int)&leftStorage, left);

    if (l->x == r->x &&
        l->y == r->y &&
        l->z == r->z &&
        l->equalMatrix(*r))
        return true;
    return false;
}
