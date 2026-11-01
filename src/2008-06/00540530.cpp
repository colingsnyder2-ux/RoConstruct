// from server: 100% by king_originala
struct S {
    int get() const;
    void set(int value);
    S& operator=(const S& other);
};

#pragma optimize("", off)
S& S::operator=(const S& other)
{
    set(other.get());
    return *this;
}
#pragma optimize("", on)
