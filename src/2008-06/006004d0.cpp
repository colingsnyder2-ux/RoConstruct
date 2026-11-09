// from server: 100% by king_originala
struct S {
    char padding[0x1c8];
    int value;

    int set(int);
    int next();
};

int S::next()
{
    return set(value + (value + 1) % 2 + 1);
}
