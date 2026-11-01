// from server: 100% by king_originala
extern void __cdecl alignedFree(void*);

struct Element {
    virtual void slot0();
    virtual void release(int);
    char storage[40];
};

struct S {
    Element* elements;
    int count;
    int capacity;

    void clear();
};

void S::clear()
{
    for (int i = 0; i < count; ++i)
        elements[i].release(0);

    alignedFree(elements);
    elements = 0;
    count = 0;
    capacity = 0;
}
