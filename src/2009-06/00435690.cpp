// from server: 100% by why2
struct S {
    bool f(const int* a, const int* b);
};

bool S::f(const int* a, const int* b) {
    return *a == *b;
}
