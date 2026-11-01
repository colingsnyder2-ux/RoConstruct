// from server: 100% by king_originala
struct Target {
    int invoke();
};

struct S {
    char padding[16];
    Target* target;
    int invoke(int, int);
};

int S::invoke(int, int) {
    return target->invoke();
}
