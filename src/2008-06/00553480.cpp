// from server: 100% by king_originala
struct S {
    int value;
    S(int, int);
};

#pragma optimize("", off)
S::S(int v, int)
{
    value = v;
}
