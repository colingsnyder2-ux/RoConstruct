// from server: 100% by king_originala
struct S {
    int value;
    S(int);
};

#pragma optimize("", off)
S::S(int v)
{
    value = v;
}
