// from server: 100% by king_originala
#pragma optimize("", off)

struct Allocator {
    void deallocate(int* p, unsigned int count);
};

struct S {
    unsigned int unused[2];
    Allocator allocator;
    int* first;
    int* last;
    int* limit;

    void destroy(int* begin, int* end);
    void f();
};

void S::f() {
    if (first != 0) {
        destroy(first, last);
        allocator.deallocate(first, limit - first);
    }
    first = 0;
    last = 0;
    limit = 0;
}
