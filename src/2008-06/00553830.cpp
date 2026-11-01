// from server: 100% by king_originala
struct S {
    int value;
    int f(int);
};

#pragma optimize("", off)
int S::f(int) {
    return value;
}
#pragma optimize("", on)
