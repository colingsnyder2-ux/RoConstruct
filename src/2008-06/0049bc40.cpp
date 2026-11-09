// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct Element {
    unsigned char storage[64];
    Element(const Element&);
};

inline void construct(Element* p, const Element& value)
{
    new (p) Element(value);
}

struct S {
    unsigned char padding[16];
    Element** map;
    unsigned int capacity;
    unsigned int first;
    unsigned int count;

    void grow(unsigned int);
    void push_back(const Element&);
};

void S::push_back(const Element& value)
{
    if (capacity <= count + 1)
        grow(1);

    unsigned int slot = first + count;
    if (capacity <= slot)
        slot -= capacity;

    if (map[slot] == 0)
        map[slot] = static_cast<Element*>(operator new(64));

    construct(map[slot], value);
    ++count;
}
