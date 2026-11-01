// from server: 100% by king_originala
struct Target {
    int invoke(int a, int b);
};

struct S {
    char padding[0x130];
    Target* target;
    int invoke(int a, int b);
};

int S::invoke(int a, int b)
{
    if (target)
        return target->invoke(a, b);
    return 0;
}
