// from server: 100% by king_originala
#pragma optimize("", off)

struct S_func_00458e90 {
    void f(int a1, int a2);
};

struct Allocator {
    int unused;
    void deallocate(short* p, unsigned int count);
};

struct S {
    int unused[2];
    Allocator allocator;
    short* first;
    short* last;
    short* limit;
    void clear();
};

void S::clear()
{
    if (first != 0) {
        reinterpret_cast<S_func_00458e90*>(this)->f(
            reinterpret_cast<int>(first), reinterpret_cast<int>(last));
        allocator.deallocate(first, limit - first);
    }
    first = 0;
    last = 0;
    limit = 0;
}
