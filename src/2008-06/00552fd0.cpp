// from server: 100% by king_originala
struct S {
    unsigned int count() const;
    bool empty() const;
};

#pragma optimize("", off)
bool S::empty() const
{
    return !count();
}
