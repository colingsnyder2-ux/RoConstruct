// from server: 100% by king_originala
struct S
{
    int f(int, int, int, int, int);
};

int __stdcall sub_416a30(int unused, int a, int b, int c, int d, int e)
{
    return reinterpret_cast<S*>(0x92c188)->f(a, b, c, d, e);
}
