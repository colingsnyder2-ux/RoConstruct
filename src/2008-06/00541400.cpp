// from server: 100% by king_originala
#pragma optimize("", off)

struct Pair {
    int first;
    int second;
    bool differs(const Pair& other) const;
};

extern int __cdecl combine(int first, int second, int third);

struct S {
    int padding[4];
    int value;

    Pair find(int first, int second);
    void update(int first, int second);
    Pair f(int a, int b, int c, int d);
};

Pair S::f(int a, int b, int c, int d)
{
    Pair first = find(a, b);
    Pair second = find(c, d);

    if (first.differs(second)) {
        int replacement = combine(second.second, value, first.second);
        update(replacement, value);
        value = replacement;
    }

    return first;
}
