// from server: 100% by king_originala
struct Part {
    unsigned char data[4];
};

extern void (__thiscall *copyPart)(Part *, const Part *);

struct S {
    int first;
    int second;
    Part part;

    S &copy(const S &source);
};

S &S::copy(const S &source)
{
    first = source.first;
    second = source.second;
    copyPart(&part, &source.part);
    return *this;
}
