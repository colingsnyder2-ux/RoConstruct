// from server: 100% by king_originala
extern "C" int __cdecl helper(int);

struct Mesh {
    int f(int);
};

#pragma optimize("", off)
int Mesh::f(int value)
{
    return helper(value);
}
