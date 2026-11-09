// from server: 100% by king_originala
#pragma optimize("", off)

struct Element {
    char data[40];
};

struct Allocator {
    Element* allocate(unsigned int count);
};

void allocation_error();

struct S {
    char padding[8];
    Allocator allocator;
    Element* first;
    Element* last;
    Element* limit;

    unsigned int max_size();
    bool allocate(unsigned int count);
};

bool S::allocate(unsigned int count)
{
    first = 0;
    last = 0;
    limit = 0;

    if (count == 0) {
        return false;
    } else if (max_size() < count) {
        allocation_error();
    } else {
        first = allocator.allocate(count);
        last = first;
        limit = first + count;
    }

    return true;
}
