// from server: 100% by king_originala
#pragma optimize("", off)

struct S {
    int first;
    int second;
    S(const int& a, const int& b);
};

S::S(const int& a, const int& b) {
    first = a;
    second = b;
}
