// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
    Vector3();
};

struct Member
{
    Member();
};

struct S
{
    Vector3 first;
    Member second;
    S();
};

#pragma optimize("", off)
S::S()
{
}
