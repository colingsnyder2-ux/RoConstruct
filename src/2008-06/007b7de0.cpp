// from server: 100% by king_originala
__forceinline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

__forceinline void __cdecl operator delete(void*, void*)
{
}

struct Element {
    char storage[0x2c];

    Element(const Element&);
    ~Element();
    Element& operator=(const Element&);
};

struct S {
    Element* data;
    int size;
    int capacity;

    void resize(int, int);
    void append(const Element&);
};

void S::append(const Element& value)
{
    if (size < capacity) {
        new (data + size) Element(value);
        ++size;
    } else if (&value >= data && &value < data + size) {
        Element temporary(value);
        append(temporary);
    } else {
        resize(size + 1, 0);
        data[size - 1] = value;
    }
}
