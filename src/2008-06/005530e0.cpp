// from server: 100% by king_originala
struct B {
    int *allocate(unsigned int);
};

extern "C" void __cdecl length_error();

struct S {
    char pad[8];
    B allocator;
    int *first;
    int *last;
    int *end;

    unsigned int max_size();
    bool f(unsigned int);
};

#pragma optimize("", off)
bool S::f(unsigned int count)
{
    first = 0;
    last = 0;
    end = 0;

    if (count == 0) {
        return false;
    } else if (max_size() < count) {
        length_error();
    } else {
        first = allocator.allocate(count);
        last = first;
        end = first + count;
    }

    return true;
}
