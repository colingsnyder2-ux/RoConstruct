// from server: 100% by king_originala
#pragma optimize("", off)

struct Element {
    char data[40];
};

struct Allocator {
    char data[4];
    void deallocate(Element* p, unsigned int count);
};

struct S {
    char padding[8];
    Allocator allocator;
    Element* first;
    Element* last;
    Element* limit;

    void destroy(Element* begin, Element* end);
    void clear_storage();
};

void S::clear_storage()
{
    if (first != 0) {
        destroy(first, last);
        allocator.deallocate(first, limit - first);
    }
    first = 0;
    last = 0;
    limit = 0;
}
