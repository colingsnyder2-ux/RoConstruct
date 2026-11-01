// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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