// from server: 100% by colin
struct S {
    bool m(S* other);
};

bool S::m(S* other)
{
    return this != other;
}
