// from server: 100% by king_originala
struct S {
    int first;
    int second;

    S& advance(int amount);
    S offset(int amount) const;
};

#pragma optimize("", off)
S S::offset(int amount) const {
    S copy = *this;
    return copy.advance(amount);
}
#pragma optimize("", on)
