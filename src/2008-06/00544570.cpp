// from server: 100% by king_originala
struct S {
    void* first;
    void* second;

    S& operator++();
    S operator++(int);
};

#pragma optimize("", off)
S S::operator++(int)
{
    S previous = *this;
    ++*this;
    return previous;
}
#pragma optimize("", on)
