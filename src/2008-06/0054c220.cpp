// from server: 100% by king_originala
struct Element {
    char storage[24];
    void *destroy(unsigned int);
};

extern "C" void __cdecl alignedFree(void *);

struct S {
    Element *data;
    int count;
    int capacity;
    void clear();
};

#pragma optimize("", off)
void S::clear() {
    for (int i = 0; i < count; i++)
        data[i].destroy(0);

    alignedFree(data);
    data = 0;
    count = 0;
    capacity = 0;
}
