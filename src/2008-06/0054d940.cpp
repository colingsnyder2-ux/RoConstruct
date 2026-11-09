// from server: 100% by king_originala
#pragma optimize("", off)

struct Element {
    unsigned char data[12];
};

struct Allocator {
    unsigned int reserved;
    Element* allocate(unsigned int count);
};

extern void allocation_error();

struct S {
    unsigned char reserved[8];
    Allocator allocator;
    Element* first;
    Element* last;
    Element* limit;

    unsigned int max_size();
    bool reserve(unsigned int count);
};

bool S::reserve(unsigned int count)
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
