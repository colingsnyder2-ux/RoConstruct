// from server: 100% by colin
struct Element {
    unsigned char data[32];
};

struct DestroyTag {};

struct S {
    unsigned char prefix[8];
    unsigned char allocator;
    unsigned char padding[3];
    Element* first;
    Element* last;
    Element* limit;

    S& operator=(const S& other);
    void clear();
    void destroy(Element* begin, Element* end);
    Element* construct(const Element* begin, const Element* end,
                       Element* destination);
    bool allocate(unsigned int count);
};

extern Element* __cdecl copy_elements(const Element* begin,
                                     const Element* end,
                                     Element* destination);
extern void __cdecl destroy_elements(Element* begin, Element* end,
                                     unsigned char* allocator,
                                     DestroyTag tag);
extern void __cdecl release_storage(void* storage);

S& S::operator=(const S& other)
{
    if (this != &other) {
        if (static_cast<unsigned int>(other.last - other.first) == 0) {
            clear();
        } else if (static_cast<unsigned int>(other.last - other.first)
                   <= static_cast<unsigned int>(last - first)) {
            Element* newEnd = copy_elements(other.first, other.last, first);
            DestroyTag tag;
            destroy_elements(newEnd, last, &allocator, tag);
            last = first + (other.last - other.first);
        } else {
            unsigned int capacity;
            if (first == 0)
                capacity = 0;
            else
                capacity = limit - first;

            if (static_cast<unsigned int>(other.last - other.first)
                <= capacity) {
                const Element* middle = other.first + (last - first);
                copy_elements(other.first, middle, first);
                last = construct(middle, other.last, last);
            } else {
                if (first != 0) {
                    destroy(first, last);
                    release_storage(first);
                }
                if (allocate(other.last - other.first)) {
                    Element* dest = first;
                    last = construct(other.first, other.last, dest);
                }
            }
        }
    }
    return *this;
}
