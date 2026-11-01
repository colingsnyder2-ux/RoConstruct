// from server: 100% by king_originala
#pragma optimize("", off)

struct Element {
    int data[3];
};

struct Allocator {
    int state;
    void deallocate(Element* p, unsigned int count);
};

struct Mesh {
    int reserved[2];
    Allocator allocator;
    Element* first;
    Element* last;
    Element* limit;

    void destroy(int first, int last);
    void clear();
};

void Mesh::clear()
{
    if (first != 0) {
        destroy((int)first, (int)last);
        allocator.deallocate(first, (unsigned int)(limit - first));
    }

    first = 0;
    last = 0;
    limit = 0;
}
